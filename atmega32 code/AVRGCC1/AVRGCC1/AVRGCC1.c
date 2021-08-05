/*
 * AVRGCC1.c
 *
 * Created: 15/03/2020 02:17:15 م
 *  Author: MIK-PC
 */ 

#include <avr/io.h>
#include "keypad.h"
#include "lcd.h"
#include "micowave.h"
int main(void)
{
	// Start_Message();
	//Device_Drive();
    Starting_Program();
	while(1)
    {
			
      	if (Sensors_Read())
			{
				TIMSK |=(1<<TOIE0);
				Turn_Output();
			}
			else
			{
				TIMSK &=(~(1<<TOIE0));
				Stop_Output();

              Turn_Buz();
		    }

	    //TODO:: Please write your application code 
    }
}