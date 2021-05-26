/*
 * seven_segment.h
 *
 *  Created on: Dec 27, 2019
 *      Author: badra069
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include"../COMPLEX DRIVERS/micro_config.h"
#include"../COMPLEX DRIVERS/common_macros.h"
#include"../COMPLEX DRIVERS/std_types.h"

#define SEVEN_SEG_DATA_OUT 	PORTC
#define SEVEN_SEG_DATA_IN  	PINC
#define SEVEN_SEG_DATA_DIR	DDRC
#define UPPER				TRUE
/*********************************USER FUNCTIONS PROTOTYPES*********************************************/
void SEVEN_SEG_init(void);
void SEVEN_SEG_displayCharacter(uint8 data);
#endif /* SEVEN_SEGMENT_H_ */
