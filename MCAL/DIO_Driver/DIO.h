/*
 * DIO.h
 *
 * Created: 8/17/2020 12:58:04 PM
 *  Author: Ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../utils/types.h"

// function to initialize the digital input output
void DIO_init(uint8_t configuration [no_of_registers] [no_of_pins]);
// function to write on micro-controller
void DIO_write(uint8_t port,uint8_t pin, uint8_t data);
// function to read from the micro-controller
void DIO_read(uint8_t port,uint8_t pin, uint8_t *state);


#endif /* DIO_H_ */