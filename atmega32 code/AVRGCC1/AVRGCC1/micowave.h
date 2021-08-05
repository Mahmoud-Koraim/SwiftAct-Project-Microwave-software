/*
 * micowave.h
 *
 * Created: 15/03/2020 02:28:31 م
 *  Author: MIK-PC
 */ 


#ifndef MICOWAVE_H_
#define MICOWAVE_H_

#define F_CPU 1000000U
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "microconf.h"
#include <avr/interrupt.h>
#include "lcd.h"
#include "keypad.h"
#include "TIMER0.h"
//////////////////
//define INPUT
#define  Door_Sen      PINC0
#define  Weight_Sen    PINC1
#define  Cancal_Sw     PINC2
//define OUTPUT
#define  Motor         PINC3
#define  Heater        PINC4
#define  Lamp          PINC5
#define  Buz           PINC6


#define Buzzer_On    PORTC |=(1<<Buz)
#define Buzzer_Off   PORTC &=(~(1<<Buz))

void Turn_Buz(void);
void Starting_Program(void);
void Device_Drive(void);
void Turn_Output(void);
void Stop_Output(void);
void Start_Message(void);
void Create_Timing(void);
//void Entering_Time(uint8_t num_as_char);
uint8_t Sensors_Read(void);
void Remaning_Time(void);
void Cancling_Mode(void);
void Microwave_Closed(void);
void Microwave_Open(void);
void Turn_Fan(void);
void close_Fan(void);
 
void Entering_Time(void);

void Reset_time(void);
void MIcrowave_Finish_task(void);


#endif /* MICOWAVE_H_ */