#include "Std_Types.h"
#include "Bitwise.h"
#include "STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
/*
#include "Timer0_interface.h"
#include "GIE_interface.h"
*/
#include "Scheduler_interface.h"
#include "Scheduler_private.h"
#include "Scheduler_config.h"

Task		Arr_Tasks[NUMBER_OF_TASKS]	;
volatile	uint16 Scheduler_Ticks	=	0	;
/*
Your tasks
1- Try to implement scheduler using first delay parameter instead of periodicity
2- Try to implement task states
3- Try to implement a function to suspend a specific task
4- Try to implement a function to resume a specific task
5- Try to implement a function to delete a specific task
Good luck
*/
void	Scheduler_voidInit(void)
{
	/*	Tick time = 1 msec									*/
	
	/*	F_CPU		16 MHz									*/
	TCNT0 = 240;
	/*	Pre scaller = 1024 and Normal Mode (OverFlow Mode)	*/
	TCCR0 = 0x05;
	/*	Enable Timer OverFlow Mode Interrupt				*/
	TIMSK = 0x01;
	/*	Enable Global Interrupt								*/
	SetBit(SREG,7);
	
	
}
void	Scheduler_voidCreateTask(uint8 Copy_u8Priority ,uint16 Copy_u16Periodicity , void (*pf) (void) , uint8 First)
{
	/*	Range Check											*/
	if(Copy_u8Priority < NUMBER_OF_TASKS)
	{
		Arr_Tasks[Copy_u8Priority].u16Periodicity = Copy_u16Periodicity;
		Arr_Tasks[Copy_u8Priority].PfTask = pf;
		Arr_Tasks[Copy_u8Priority].firstdelay = First;

		
	}else
	{
		/*	Return Error									*/
	}
	
}


static void Scheduler_voidStartOS(void)
{
	/*	Order and execut all Ready Tasks ( as Periodicity )	*/
	for(uint8 i = 0 ; i < NUMBER_OF_TASKS ; i++)
	{
		if(Scheduler_Ticks>= Arr_Tasks[i].firstdelay){
			if(((Scheduler_Ticks % Arr_Tasks[i].u16Periodicity) -Arr_Tasks[i].firstdelay)== 0)
			{
				Arr_Tasks[i].PfTask();
			}
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	/*	PreLoad												*/
	TCNT0 = 240;
	/*	Call Scheduler = 1 msec	(Scheduler Tick time)		*/
	Scheduler_voidStartOS();
	/*	Number of Ticks										*/
	Scheduler_Ticks++;
}