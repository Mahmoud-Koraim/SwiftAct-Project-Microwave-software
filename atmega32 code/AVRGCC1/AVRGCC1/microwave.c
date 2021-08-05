/*
 * microwave.c
 *
 * Created: 15/03/2020 02:28:02 م
 *  Author: MIK-PC
 */ 
#include "micowave.h"

uint8_t Arr_Time[4]={0,0,0,0};
static uint8_t t=0;   //why static
volatile uint16_t Num_Total_Sec;
volatile char Date;   //to recieve date from keypad fun keyfind()

volatile uint8_t finish=1; 

volatile  uint8_t flag=1;
volatile  uint8_t flag2=0;
void Device_Drive(void)
{
	//define inputs
	DDRC &=(~(1<<Door_Sen));
	DDRC &=(~(1<<Weight_Sen));
	DDRC &=(~(1<<Cancal_Sw));
	//define output
	DDRC|=(1<<Motor);
	DDRC|=(1<<Heater);
	DDRC|=(1<<Lamp);
	DDRC|=(1<<Buz);
}
void Turn_Output(void)
{
	PORTC|=(1<<Motor);
	PORTC|=(1<<Heater);
	PORTC|=(1<<Lamp);
}
void Stop_Output(void)
{
	PORTC &=(~(1<<Motor));
	PORTC &=(~(1<<Heater));
	PORTC &=(~(1<<Lamp));

}

uint8_t Sensors_Read(void)
{
	if (IS_BIT_SET(PORTC_INPUTREAD,Door_Sen) && IS_BIT_SET(PORTC_INPUTREAD,Weight_Sen)&&IS_BIT_SET(PORTC_INPUTREAD,Cancal_Sw)&&(flag==1))
	{
		flag2=1;
		return 1;
	}
	else
	{

		return 0;

		
	}
}
void Turn_Buz(void)
{
					if (flag2==1)
				{
	  			    Buzzer_On;
                   _delay_ms(200);
	             	Buzzer_Off;
				   flag2=0; 
				}
				else
				{
					
				}
}
void Starting_Program(void)
{ 
	
	Device_Drive();
	Start_Message();
	Entering_Time();
	Timer0_Intialization();
}

void Start_Message(void)
{   
	LCD_INISTIALIZATION();
	GO_LOC(2,1);
	SEND_STRING("wellcome");
	for (int j=0;j<=5;j++)
	{
		SEND_COMND(0x1C);
		_delay_ms(30); 
	}
	_delay_ms(500);
	SEND_COMND(0x01); //clear lcd and curser goto loc(1.1) automatically
	SEND_STRING("timer");
    SEND_STRING(" 00:00 ");
	
	GO_LOC(1,7);
	////////////////////////////
	

}
void Create_Timing(void)
{
	SEND_COMND(0x01); //clear lcd and curser goto loc(1.1) automatically
    GO_LOC(1,1);
	SEND_DATE('0');
	SEND_DATE('0');
	SEND_DATE(':');
	SEND_DATE('0');
	SEND_DATE('0');
	SEND_DATE(':');
}
/*void Time_Of_Heating(void)
{
	uint8_t t=0;
	SEND_DATE(keyfind())
   Arr_Time[t++]=(keyfind()-48);
   if(Arr_Time==2)
   {
	   SEND_DATE(' ');
   }
}*/	

void Entering_Time(void)
{
//Date=keyfind();
//if((Date != '='))
//int n=5;
//if(n>1)
while(finish==1)
	{
		//jump:
	// Reset_time();
		if (t<4)
	    {
	    Date=keyfind();
		       if (Date=='*')
		       {
				   Reset_time();
				// goto jump;
		       }
	  else if (t==0  && (Date == '='))
			 {
				 //donothing
			 }
		       
			   else
		 {
			
	   
		    if ((Date == '='))
		       {
				  goto jump;
			   }
		     SEND_DATE(Date);
        Arr_Time[t++]=(Date-48);
           if(t==2)
               {
	             GO_LOC(1,10);
               }
		    if ((t==4)&&(keyfind()=='='))
		        {
					jump:
				  t=4;    //to avoid receving again from key pad and char('*')will affect 
				  Num_Total_Sec=(Arr_Time[0] *10*60)+(Arr_Time[1] * 60)+(Arr_Time[2] * 10)+(Arr_Time[3] *1);
				  Buzzer_On;
				  _delay_ms(200);
				  Buzzer_Off;
			      GO_LOC(2,1);
		          SEND_STRING("wait  ");
		          SEND_DATE(Arr_Time[0]+48);
				  SEND_DATE(Arr_Time[1]+48);
				  SEND_DATE(':');
				  SEND_DATE(Arr_Time[2]+48);
				  SEND_DATE(Arr_Time[3]+48);
				  
				  finish=0;  
				 }
     
		    }
		}          
	}			
/*/else if (Date =='=')
{
	Num_Total_Sec=(Arr_Time[0] *10*60)+(Arr_Time[1] * 60)+(Arr_Time[2] * 10)+(Arr_Time[3] *1);
	GO_LOC(2,6);
	//SEND_LONG_NUM(Num_Total_Sec,)
	SEND_DATE(Arr_Time[0]+48);
	SEND_DATE(Arr_Time[1]+48);
	
}
*/
}
void Reset_time(void)
{  
	t=0;
	 Buzzer_On;
  _delay_ms(200);
  Buzzer_Off;
	GO_LOC(2,3);
	SEND_STRING("timer canseled");
    _delay_ms(500);
	SEND_COMND(0x01); //clear lcd and curser goto loc(1.1) automatically
	SEND_STRING("timer");
	//GO_LOC(1,6);
	SEND_STRING(" 00:00 ");
	Arr_Time[0]=0;
	Arr_Time[1]=0;
	Arr_Time[2]=0;
	Arr_Time[3]=0;
	GO_LOC(1,7);
}

void Remaning_Time(void)
{
	      
		         Arr_Time[0]=(Num_Total_Sec/600);  
				 Arr_Time[1]=((Num_Total_Sec % 600)/60); 
				 Arr_Time[2]=((((Num_Total_Sec % 600)%60)/10));  
				 Arr_Time[3]=(((Num_Total_Sec % 600)%60)%10);
				      GO_LOC(2,7);    
			      SEND_DATE(Arr_Time[0]+48);
				  SEND_DATE(Arr_Time[1]+48);
				  SEND_DATE(':');
				  SEND_DATE(Arr_Time[2]+48);
				  SEND_DATE(Arr_Time[3]+48);
}
void MIcrowave_Finish_task(void)
{
	              cli();   //mask all interupt globaally
				  TCCR0=0x00;
				  flag=0;
			    GO_LOC(2,1);
			    SEND_STRING("      ");	   
		       SEND_STRING("00:00 ");
				 Stop_Output();
				  Buzzer_On;
				  _delay_ms(300);
				  Buzzer_Off;
				  SEND_COMND(0x01);
               	GO_LOC(3,1);
			    SEND_STRING("welldone");
					for (int j=0;j<=5;j++)
               	{
		          SEND_COMND(0x1C);
	             	_delay_ms(30); 
             	}
				
}

ISR(TIMER0_OVF_vect)
{
	TCNT0=165;
     Num_Total_Sec--;
	if (Num_Total_Sec !=0)
	{
		 Remaning_Time();
	}
	else
	{
		MIcrowave_Finish_task();
	}
	
}