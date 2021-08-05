/*
 * microconfg.c
 *
 * Created: 28/01/2019 11:50:30 م
 *  Author: MIK-PC
 */ 

#include "microconf.h"

void OUTPUT_MODE(volatile uint8 *DIR_ADRESSS,volatile uint8 *INPUT_TRISTATE_ADRESS,uint8 PIN_NO,IO_MODE PIN_MODE)

{
	SET_BIT(*DIR_ADRESSS,PIN_NO);
	
	switch (PIN_MODE)
	{
			case INPUT_FLOAT:
			CLEAR_BIT(*INPUT_TRISTATE_ADRESS,PIN_NO);
			break;
			
			case INPUT_PULLUP:
			SET_BIT(*INPUT_TRISTATE_ADRESS,PIN_NO);
			break;
			
			default:
			break;
	}

	
}



void INPUT_MODE(volatile uint8 *DIR_ADRESSS,volatile uint8 *OUT_FLOATORPULL_ADRESS,uint8 PIN_NO,IO_MODE PIN_MODE)

{
	CLEAR_BIT(*DIR_ADRESSS,PIN_NO);
	
	switch(PIN_MODE)
{
	
	case OUTPUT_BLOCK:
	SET_BIT(*OUT_FLOATORPULL_ADRESS,PIN_NO);
	break;
	
	case OUTPUT_PASS:
	CLEAR_BIT(*OUT_FLOATORPULL_ADRESS,PIN_NO);
	break;
	
	default:
	break;
}
}
