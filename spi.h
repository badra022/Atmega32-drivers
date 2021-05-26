 /******************************************************************************
 *
 * Module: spi
 *
 * File Name: spi.h
 *
 * Description: spi header file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/
#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_
/*********************************************************************************
 * 									INCLUDES									 *
 *********************************************************************************/
#include"../COMPLEX DRIVERS/micro_config.h"
#include"../COMPLEX DRIVERS/common_macros.h"
#include"../COMPLEX DRIVERS/std_types.h"
/*********************************************************************************
 * 							Definitions and Configurations						 *
 *********************************************************************************/
extern volatile uint8 g_SPI_currentReading;
#define SPIE		7
#define SPE			6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0
#define SPIF		7
#define WCOL		6
#define SPI2X		0
typedef enum
{
	SPI_SLAVE ,
	SPI_MASTER ,
}SPI_mode;
typedef enum
{
	SPI_F_CPU_4_X ,
	SPI_F_CPU_16_X ,
	SPI_F_CPU_64_X ,
	SPI_F_CPU_128_X ,
	SPI_F_CPU_2_2X ,
	SPI_F_CPU_8_2X ,
	SPI_F_CPU_32_2X ,
	SPI_F_CPU_64_2X ,
}SPI_SCK;
typedef struct
{
	SPI_mode mode;
	uint8 interrupt;
	SPI_SCK clock;
}SPI_configType;
/*********************************************************************************
 * 							Module shared global Variables						 *
 *********************************************************************************/
extern volatile uint8 g_SPI_currentReading;
/*********************************************************************************
 * 								Function Declarations							 *
 *********************************************************************************/
void SPI_init(const SPI_configType * a_ptr);

void SPI_sendByte(uint8 data);

uint8 SPI_receiveByte(void);

void SPI_sendString(const uint8 * str);

void SPI_receiveString(uint8 * str);

void SPI_setCallBack(void (*a_ptr)(void));

#endif /* MCAL_SPI_H_ */
