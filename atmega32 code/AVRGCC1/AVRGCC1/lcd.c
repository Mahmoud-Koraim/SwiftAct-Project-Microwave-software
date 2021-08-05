/*
 * lcd.c
 *
 * Created: 10/03/2020 11:35:16 ص
 *  Author: MIK-PC
 */ 
/*
 * lcd.c
 *
 * Created: 10/03/2020 11:35:16 ص
 *  Author: MIK-PC
 */ 
#include "lcd.h"

void LCD_INISTIALIZATION(void)
{
	DATE_IN_OUT =0xFF;
	CONTRLO_PINS_IN_OUT|=((1<<ENABLE)|(1<<RE_WR)|(1<<REG_SEL));
	//CONTRLO_PINS_HI_LO&=~(1<<ENABLE);
	
	_delay_ms(20);       //wait for start initialization
	SEND_COMND(0x38);   //8bit mode
	SEND_COMND(0x0E);   //curser not be blinking
	SEND_COMND(0x01);   // clear display
	_delay_ms(2);
	SEND_COMND(0x06);   //INCREAMENT CURSOR TO RIGHT

}

void SEND_COMND(unsigned char CMD)
{
	CONTRLO_PINS_HI_LO&=~((1<<RE_WR)|(1<<REG_SEL)) ;
	DATE_HI_LO=CMD;
	HI_LO_PULS_EN();
}

void HI_LO_PULS_EN(void)
{
	CONTRLO_PINS_HI_LO|=(1<<ENABLE);
	_delay_us(1);
	CONTRLO_PINS_HI_LO&=~(1<<ENABLE);
	_delay_us(100);
	_delay_ms(50);
}

void SEND_DATE(unsigned char DATE)
{
	CONTRLO_PINS_HI_LO &=~(1<<RE_WR);
	CONTRLO_PINS_HI_LO |=(1<<REG_SEL);
	DATE_HI_LO=DATE;
	HI_LO_PULS_EN();
}
void SEND_STRING(unsigned char *STR)
{
	while(*STR>0)
	{
		
		SEND_DATE(*STR++);  //first send and then increament
		
	}
}
char ARR_LOC_ROWS[]={0x80,0xC0,0x94,0xD4};
void GO_LOC(uint8_t x,uint8_t y)
{
	//char ARR_LOC_ROWS[]={0x80,0xC0,0x94,0xD4};
	
	SEND_COMND(ARR_LOC_ROWS[x-1]+(y-1));
}

void SEND_LONG_NUM(char *p,int siz)
{
	static char NUM_ST[4];
	for (int i=0;i<siz;i++)
	{
		itoa(*p,NUM_ST,10);
		SEND_STRING(NUM_ST);
		p++;
		//itoa(*p,NUM_ST,10);
		//	SEND_STRING(NUM_ST);
	}
	int sift=(20+(20-siz)/2);
	for (int i=0;i<sift;i++)
	{
		SEND_COMND(0x1C);
	}
	
}