#include "Scheduler_interface.h"
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "Bitwise.h"

void	LED1	(void)
{
	//// Toggle LED C7
	PORTC ^= (1<<7);  	//1000 0000
}
void	LED2	(void)
{
	//// Toggle LED C2
	PORTC ^= (1<<2);  	//0000 0100
}
void	LED3	(void)
{
	//// Toggle LED D3
	PORTD ^= (1<<3);  //1000 1000
}



int main(void)
{
	//DDRC |= (1<<PD2);
	

	/*	Initialization part						*/
	/*	PC7 ,PC2 and PD3 are Output Pins		*/
	
	DDRC = 0xFF; // DDRC |= 0b10000100;
	DDRD = 0xFF; // DDRD |= 0b00001000;
	
	Scheduler_voidInit();
	
	Scheduler_voidCreateTask(0,1000,LED1,0);		//	1 Sec
	Scheduler_voidCreateTask(1,2000,LED2,1);		//	2 Sec
	Scheduler_voidCreateTask(2,3000,LED3,2);		//	3 Sec
	
	while(1)
	{
		/* PORTC |= 1 << PINC2;
		 _delay_ms(1000);
		 PORTB &= ~(1<<PINB0);
		 _delay_ms(1000);*/
	}
	return 0 ;
}