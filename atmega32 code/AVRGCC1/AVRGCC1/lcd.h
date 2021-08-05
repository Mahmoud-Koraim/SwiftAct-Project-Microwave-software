/*
 * lcd.h
 *
 * Created: 10/03/2020 11:34:44 ص
 *  Author: MIK-PC
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#include <util/delay.h>


//***************************
//---------------------------
#define ENABLE  1
#define RE_WR   2
#define REG_SEL 3
//*************************
#define DATE_IN_OUT                DDRA
#define DATE_HI_LO                 PORTA

#define CONTRLO_PINS_IN_OUT        DDRB
#define CONTRLO_PINS_HI_LO         PORTB
/////////////////////////////////////////////
void LCD_INISTIALIZATION(void);
void SEND_COMND(unsigned char CMD);
void HI_LO_PULS_EN(void);
void SEND_DATE(unsigned char DATE);
void SEND_STRING(unsigned char *STR);
void GO_LOC(uint8_t x,uint8_t y);
void SEND_LONG_NUM(char *p,int siz);

#endif /* LCD_H_ */