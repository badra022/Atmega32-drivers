/******************************************************************************
 *
 * Module: spi
 *
 * File Name: spi.c
 *
 * Description: spi src file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/
/*********************************************************************************
 * 									INCLUDES									 *
 *********************************************************************************/
#include"spi.h"

/*********************************************************************************
 * 								Global variables								 *
 *********************************************************************************/
static volatile void (* g_SPI_transferComplete_ptr)(void) = NULL;
volatile uint8 g_SPI_currentReading = 0;
/*********************************************************************************
 * 								Function Definitions							 *
 *********************************************************************************/
void SPI_init(const SPI_configType * a_ptr)
{
	if(a_ptr->mode == SPI_MASTER)
	{
		/******** Configure SPI Master Pins *********
		 * SS(PB4)   --> Output
		 * MOSI(PB5) --> Output
		 * MISO(PB6) --> Input
		 * SCK(PB7) --> Output
		 ********************************************/
		SET_BIT(DDRB , 4);
		SET_BIT(DDRB , 5);
		CLEAR_BIT(DDRB , 6);
		SET_BIT(DDRB , 7);
	}
	else if(a_ptr->mode == SPI_SLAVE)
	{
		/******** Configure SPI Slave Pins *********
		 * SS(PB4)   --> Input
		 * MOSI(PB5) --> Input
		 * MISO(PB6) --> Output
		 * SCK(PB7) --> Input
		 ********************************************/
		CLEAR_BIT(DDRB , 4);
		CLEAR_BIT(DDRB , 5);
		SET_BIT(DDRB , 6);
		CLEAR_BIT(DDRB , 7);
	}
	/**********************************
	 * 1.  SPI enable through setting SPE in SPCR
	 * 2.  setting the data ordering firstly MSB to transmit as standard says ( DORD = 0)
	 * 3.  select is this is master or slave (MSTR) bit
	 * 4.  setting the master's clock polarity 1 for Falling and 0 for Raising in CPOL bit case of leading always
	 * 5.  selecting which edge to sample the data and setup the data in
	 * 4 & 5 aren't valid configurations and don't affect transmission
	 * 6.  selecting sck frequency in SPR1:0
	 **********************************/
	SPCR = (a_ptr->mode << MSTR) | (a_ptr->interrupt << SPIE) | (1<<SPE) | (a_ptr->clock & 0x03);
	/**********************************
	 * double speed or not (SPI2X) bit
	 **********************************/
	SPSR |= (a_ptr->clock >> 2);
}
void SPI_sendByte(uint8 data)
{
	while(BIT_IS_CLEAR(SPSR , SPIF));
	SPDR = data;
}
uint8 SPI_receiveByte(void)
{
	while(BIT_IS_CLEAR(SPSR , SPIF));
	g_SPI_currentReading = SPDR;
	return SPDR;
}
void SPI_sendString(const uint8 * str)
{
	uint8 count = 0;

	while(str[count] != '\0')
	{
		SPI_sendByte(str[count]);
		count++;
	}
}
void SPI_receiveString(uint8 * str)
{
	uint8 count = 0;

	do
	{
		str[count] = SPI_receiveByte();
		count++;
	}while(str[count] != '*');

	str[count] = '\0';
	/****************ANOTHER METHOD****************************************
	 * do
	 * {
	 * 		*str = SPI_receiveByte();
	 * 		str++;
	 * 	}while(*str != '*');
	 *
	 * 	*str = '\0';
	 ***********************************************************************/
}
void SPI_setCallBack(void (*a_ptr)(void))
{
	g_SPI_transferComplete_ptr = a_ptr;
}



/*********************************************************************************
 * 								interrupt service routines						 *
 *********************************************************************************/
ISR(SPI_STC_vect)
{
	g_SPI_currentReading = SPDR;
	if(g_SPI_transferComplete_ptr != NULL)
	{
		g_SPI_transferComplete_ptr();
	}
}
