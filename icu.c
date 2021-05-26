 /******************************************************************************
 *
 * Module: dc motor
 *
 * File Name: dc_motor.c
 *
 * Description: dc_motor src file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/
/*********************************************************************************
 * 									INCLUDES									 *
 *********************************************************************************/
#include"icu.h"

/*********************************************************************************
 * 								Global variables								 *
 *********************************************************************************/
static volatile void (*g_callBackIcuFunc_ptr)(void) = NULL;
volatile uint8 g_IcucaptureCount = 0;
/*********************************************************************************
 * 								Function Definitions							 *
 *********************************************************************************/
void ICU_init(const ICU_config * a_ptr)
{
	/* initiating the ctrl registers */
	TCCR1A = 0;
	TCCR1B = 0;
	/*for normal mode operation*/
	SET_BIT(TCCR1A , FOC1A);
	SET_BIT(TCCR1A , FOC1A);
	/* normal mode is all WGM are 0s so it's not changed*/
	/*disabling the noise canceler */
	CLEAR_BIT(TCCR1B , ICNC1);
	/* selecting the edge as at the configuration ptr*/
	SET_VALUE(TCCR1B , ICES1 , a_ptr->edge);
	/* setting the prescaler for timer 1 */
	TCCR1B |= a_ptr->clock;
	/* initial value of the counting register TCNT1 and ICR1*/
	TCNT1 = 0;
	ICR1 = 0;
	/* enabling the interrupt for the ICU module (not a selectable configuration)*/
	SET_BIT(TIMSK , TICE1);
}
void ICU_setEdge(ICU_edge edge)
{
	SET_VALUE(TCCR1B , ICES1 , edge);
}
void ICU_Deinit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
}
uint16 ICU_getTimeCaptured(void)
{
	/* return the stored value that indicate the count that is captured*/
	return ICR1;
}
void ICU_clearTimer(void)
{
	/* reset the counter register*/
	TCNT1 = 0;
}
void ICU_setCallBackFunc(void (*a_ptr)(void))
{
	g_callBackIcuFunc_ptr = a_ptr;
}


/*********************************************************************************
 * 								interrupt service routines						 *
 *********************************************************************************/
ISR(TIMER1_CAPT_vect)
{
	if(g_callBackIcuFunc_ptr == NULL)
	{
		g_callBackIcuFunc_ptr();
	}
}
