 /******************************************************************************
 *
 * Module: dc_motor
 *
 * File Name: dc_motor.h
 *
 * Description: dc motor header file
 *
 * Author: Ahmed Mohamed
 *
 *******************************************************************************/
#ifndef ICU_H_
#define ICU_H_
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
	TIMER1_NON ,
	TIMER1_F_CPU ,
	TIMER1_F_CPU_8 ,
	TIMER1_F_CPU_64 ,
	TIMER1_F_CPU_256 ,
	TIMER1_F_CPU_1024 ,
	TIMER1_PIN_FALLING_EDGE ,
	TIMER1_PIN_RAISING_EDGE ,
}TIMER1_clock;

typedef enum
{
	ICU_FALLING_EDGE ,
	ICU_RAISING_EDGE ,
}ICU_edge;

typedef struct
{
	ICU_edge edge;
	TIMER1_clock clock;
}ICU_config;

#define FOC1A	3
#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
#define ICF1	5
#define FOC1B	2
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define WGM11	1
#define WGM10	0
#define TICE1	5

/*********************************************************************************
 * 							Module shared global Variables						 *
 *********************************************************************************/
extern volatile uint8 g_IcucaptureCount;
/*********************************************************************************
 * 								Function Declarations							 *
 *********************************************************************************/
void ICU_init(const ICU_config * a_ptr);
void ICU_setEdge(ICU_edge edge);
void ICU_Deinit(void);
uint16 ICU_getTimeCaptured(void);
void ICU_clearTimer(void);
void ICU_setCallBackFunc(void (*a_ptr)(void));
#endif /* ICU_H_ */
