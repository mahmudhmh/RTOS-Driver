/*
 * Scheduler_interface.h
 *
 * Created: 12/11/2021 10:44:49 AM
 *  Author: User
 */ 

#include "STD_Types.h"
#include "Bitwise.h"

#ifndef SCHEDULER_INTERFACE_H_
#define SCHEDULER_INTERFACE_H_

void	Scheduler_voidInit(void);

void	Scheduler_voidCreateTask(uint8 Copy_u8Priority ,uint16 Copy_u16Periodicity , void (*pf) (void) , uint8 First);




#endif /* SCHEDULER_INTERFACE_H_ */