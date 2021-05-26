/*
 * seven_segment.c
 *
 *  Created on: Dec 27, 2019
 *      Author: badra069
 */
/*****************************************FUNCTION DEFINITIONS******************************************/
#include"seven_segment.h"

void SEVEN_SEG_init(void)
{
	#if(UPPER == TRUE)
	SET_UPPER(SEVEN_SEG_DATA_DIR);
	CLEAR_UPPER(SEVEN_SEG_DATA_OUT);
	#elif(UPPER == FALSE)
	SET_LOWER(SEVEN_SEG_DATA_DIR);
	CLEAR_LOWER(SEVEN_SEG_DATA_OUT);
	#endif
}
void SEVEN_SEG_displayCharacter(uint8 data)
{
	#if(UPPER == TRUE)
	PUT_UPPER_IN_UPPER(SEVEN_SEG_DATA_OUT,data);
	#elif(UPPER == FALSE)
	PUT_UPPER_IN_LOWER(SEVEN_SEG_DATA_OUT,data);
	#endif


}
