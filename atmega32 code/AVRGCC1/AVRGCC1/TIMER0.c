/*
 * TIMER0.c
 *
 * Created: 18/03/2020 11:19:02 م
 *  Author: MIK-PC
 */ 
#include "TIMER0.h"

void Timer0_Intialization(void)
{
	sei();
	TCNT0=156;
	TCCR0=0x01;
//	TIMSK |=(1<<TOIE0);
}