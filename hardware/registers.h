/*
 * registers.h
 *
 * Created: 8/17/2020 12:46:42 PM
 *  Author: Ahmed
 */
#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "../utils/types.h"

//A
// decide voltage --> high or low
#define PA_DATA	(*(volatile uint8_t *)0x3B)
// decide direction --> input or output
#define PA_CTRL	(*(volatile uint8_t *)0x3A)
// read the pin value (status) 
#define PA_STAT (*(volatile uint8_t	*)0x39)


//B
// decide voltage --> high or low
#define PB_DATA	(*(volatile uint8_t *)0x38)
// decide direction --> input or output
#define PB_CTRL	(*(volatile uint8_t *)0x37)
// read the pin value (status)
#define PB_STAT (*(volatile uint8_t	*)0x36)

// C
// decide voltage --> high or low
#define PC_DATA	(*(volatile uint8_t *)0x35)
// decide direction --> input or output
#define PC_CTRL	(*(volatile uint8_t *)0x34)
// read the pin value (status)
#define PC_STAT (*(volatile uint8_t	*)0x33)


// D
// decide voltage --> high or low
#define PD_DATA	(*(volatile uint8_t *)0x32)
// decide direction --> input or output
#define PD_CTRL	(*(volatile uint8_t *)0x31)
// read the pin value (status)
#define PD_STAT (*(volatile uint8_t	*)0x30)
#endif /* REGISTERS_H_ */