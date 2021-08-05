/*
 * keypad.h
 *
 * Created: 10/03/2020 03:25:19 م
 *  Author: MIK-PC
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*#define F_CPU 1000000UL

#include <util/delay.h>
*/
#include <avr/io.h>
#include <util/delay.h>
#define KEY_PRT 	PORTD
#define KEY_DDR		DDRD
#define KEY_PIN		PIND

char keyfind();



#endif /* KEYPAD_H_ */