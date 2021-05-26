 /******************************************************************************
 *
 * Module: WDT
 *
 * File Name: watchdog.h
 *
 * Description: watchdog header file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
/*********************************************************************************
 * 									INCLUDES									 *
 *********************************************************************************/
#include"../COMPLEX DRIVERS/micro_config.h"
#include"../COMPLEX DRIVERS/common_macros.h"
#include"../COMPLEX DRIVERS/std_types.h"
/*********************************************************************************
 * 							Definitions and Configurations						 *
 *********************************************************************************/
typedef enum
{
	_16_3_MSEC 	,
	_32_5_MSEC 	,
	_65_MSEC	,
	_130_MSEC	,
	_260_MSEC	,
	_520_MSEC	,
	_1_SEC		,
	_2_1_SEC	,
}WATCHDOG_5V_timeOut;
#define WDE		3
#define WDP2	2
#define WDP1	1
#define WDP0	0
#define WDTOE	4
/*********************************************************************************
 * 								Function Declarations							 *
 *********************************************************************************/
void WATCHDOG_on(WATCHDOG_5V_timeOut a_prescale);
/*--------------------------------------------------------------
 * [Description] : this function is responsible for enabling WDT
 * 				and setting the time out period in the arg "prescale"
 *  [Args] :
 *  [in]a_prescale :
 *  		this Arg shall indicate the value to put in the 3 bits WDP0:2
 *  		as a time out value (prescaler of the WDT)
----------------------------------------------------------------- */
void WATCHDOG_off(void);
/*--------------------------------------------------------------
 * [Description] : this function is responsible for disabling the WDT by a
 * 				certain procedure described at the data sheet
----------------------------------------------------------------- */
#endif /* DC_MOTOR_H_ */
