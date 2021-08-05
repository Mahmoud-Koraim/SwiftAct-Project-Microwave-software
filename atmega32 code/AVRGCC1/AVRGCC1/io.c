/*
 * io.c
 *
 * Created: 26/08/2018 02:21:18 م
 *  Author: Ali Abdelhady
 */ 


#include "microconf.h"
#include "macros.h"
#include "stand.h"
#include <avr/io.h>
int main(void)
{
	SET_BIT(DDRA,0);
	SET_BIT(PORTA,PA0);
    while(1)
    {
        
    }
}