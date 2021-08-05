/*
 * microconf.h
 *
 * Created: 26/08/2018 02:42:27 م
 *  Author: Ali Abdelhady
 */ 


#ifndef MICROCONF_H_
#define MICROCONF_H_

	#define F_CPU 1000000U
	#include <avr/io.h>
	#include <util/delay.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include "stand.h"
	#include "macros.h"
typedef enum
{
	INPUT_PULLUP,
	INPUT_FLOAT,
	OUTPUT_PASS,
	OUTPUT_BLOCK,
}IO_MODE;

typedef enum
{
LOW,
HIGH,
}SIGNAL;
	
void OUTPUT_MODE(volatile uint8 *DIR_ADRESSS,volatile uint8 *INPUT_TRISTATE_ADRESS,uint8 PIN_NO,IO_MODE PIN_MODE);

void INPUT_MODE(volatile uint8 *DIR_ADRESSS,volatile uint8 *OUT_FLOATORPULL_ADRESS,uint8 PIN_NO,IO_MODE PIN_MODE);

#define PORTA_INPUTREAD_ADDRESS     ((volatile uint8 *)0X39)    //PINA
#define PORTA_BLOCKOUTPUT_ADDRESS   ((volatile uint8 *)0X39)    //PINA
#define PORTA_DIRREG_ADDRESS        ((volatile uint8 *)0X3A)    //DDRA
#define PORTA_OUTPUTREG_ADDRESS     ((volatile uint8 *)0X3B)    //PORTA
#define PORTA_INPUTMODEREAD_ADDRESS ((volatile uint8 *)0X3B)    //PORTA

#define PORTB_INPUTREAD_ADDRESS     ((volatile uint8 *)0X36)
#define PORTB_BLOCKOUTPUT_ADDRESS   ((volatile uint8 *)0X36)
#define PORTB_DIRREG_ADDRESS        ((volatile uint8 *)0X37)
#define PORTB_OUTPUTREG_ADDRESS     ((volatile uint8 *)0X38)
#define PORTB_INPUTMODEREAD_ADDRESS ((volatile uint8 *)0X38)

#define PORTC_INPUTREAD_ADDRESS     ((volatile uint8 *)0X33)
#define PORTC_BLOCKOUTPUT_ADDRESS   ((volatile uint8 *)0X33)
#define PORTC_DIRREG_ADDRESS        ((volatile uint8 *)0X34)
#define PORTC_OUTPUTREG_ADDRESS     ((volatile uint8 *)0X35)
#define PORTC_INPUTMODEREAD_ADDRESS ((volatile uint8 *)0X35)

#define PORTD_INPUTREAD_ADDRESS     ((volatile uint8 *)0X30)
#define PORTD_BLOCKOUTPUT_ADDRESS   ((volatile uint8 *)0X30)
#define PORTD_DIRREG_ADDRESS        ((volatile uint8 *)0X31)
#define PORTD_OUTPUTREG_ADDRESS     ((volatile uint8 *)0X32)
#define PORTD_INPUTMODEREAD_ADDRESS ((volatile uint8 *)0X32)


#define PORTA_INPUTREAD     (*PORTA_INPUTREAD_ADDRESS  )
#define PORTA_BLOCKOUTPUT   (*PORTA_BLOCKOUTPUT_ADDRESS)
#define PORTA_DIRREG        (*PORTA_DIRREG_ADDRESS )
#define PORTA_OUTPUTREG     (*PORTA_OUTPUTREG_ADDRESS)
#define PORTA_INPUTMODEREAD (*PORTA_INPUTMODEREAD_ADDRESS )

#define PORTB_INPUTREAD     (*PORTB_INPUTREAD_ADDRESS  )
#define PORTB_BLOCKOUTPUT   (*PORTB_BLOCKOUTPUT_ADDRESS)
#define PORTB_DIRREG        (*PORTB_DIRREG_ADDRESS )
#define PORTB_OUTPUTREG     (*PORTB_OUTPUTREG_ADDRESS  )
#define PORTB_INPUTMODEREAD    (*PORTB_INPUTMODEREAD_ADDRESS)

#define PORTC_INPUTREAD     (*PORTC_INPUTREAD_ADDRESS )
#define PORTC_BLOCKOUTPUT   (*PORTC_BLOCKOUTPUT_ADDRESS)
#define PORTC_DIRREG        (*PORTC_DIRREG_ADDRESS)
#define PORTC_OUTPUTREG     (*PORTC_OUTPUTREG_ADDRESS )
#define PORTC_INPUTMODEREAD (*PORTC_INPUTMODEREAD_ADDRESS )

#define PORTD_INPUTREAD     ( *PORTD_INPUTREAD_ADDRESS)
#define PORTD_BLOCKOUTPUT   ( *PORTD_BLOCKOUTPUT_ADDRESS)
#define PORTD_DIRREG        (*PORTD_DIRREG_ADDRESS   )
#define PORTD_OUTPUTREG     (*PORTD_OUTPUTREG_ADDRESS )
#define PORTD_INPUTMODEREAD (*PORTD_INPUTMODEREAD_ADDRESS)





#endif /* MICROCONF_H_ */