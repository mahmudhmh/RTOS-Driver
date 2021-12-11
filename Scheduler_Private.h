/*
 * Scheduler_Private.h
 *
 * Created: 12/11/2021 10:45:05 AM
 *  Author: User
 */ 

#include "STD_Types.h"
#include "Bitwise.h"

#ifndef SCHEDULER_PRIVATE_H_
#define SCHEDULER_PRIVATE_H_


static void Scheduler_voidStartOS(void);

typedef	struct
{
	uint8 firstdelay;
	uint16	u16Periodicity;
	void (*PfTask) (void);
	
}Task;




#endif /* SCHEDULER_PRIVATE_H_ */