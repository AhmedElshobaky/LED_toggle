/*
 * DIO.c
 *
 * Created: 8/17/2020 12:57:41 PM
 *  Author: Ahmed
 */ 
#include "../../hardware/registers.h"
#include "DIO.h"
// Used to initialize the DIO driver
// the argument passed to this function is the configuration 2d array
void DIO_init(uint8_t configuration [no_of_registers][no_of_pins]){
	// for loop to check every element of the array/PINs of registers
	for(int reg = 0;reg<no_of_registers;reg++){
		for(int pin =0;pin < no_of_pins;pin++){
			switch(reg){
				// case reg = 0 referees to A register
				case 0:
					// if the value of that pin in the array is 1 then we set as output
					// else we will set it input
					if(configuration[reg][pin] == 1) PA_CTRL |=(1<<pin);
					else PA_CTRL|=(0<<pin);
					break;
				// case reg = 1 referees to B register
				case 1:
					// if the value of that pin in the array is 1 then we set as output
					// else we will set it input
					if(configuration[reg][pin] == 1) PB_CTRL |=(1<<pin);
					else PB_CTRL|=(0<<pin);
					break;
				// case reg = 2 means referees to C register
				case 2:
					// if the value of that pin in the array is 1 then we set as output
					// else we will set it input
					if(configuration[reg][pin] == 1) PC_CTRL |=(1<<pin);
					else PC_CTRL|=(0<<pin);
					break;
				// case reg = 3 referees to D register
				case 3:
					// if the value of that pin in the array is 1 then we set as output
					// else we will set it input
					if(configuration[reg][pin] == 1) PD_CTRL |=(1<<pin);
					else PD_CTRL|=(0<<pin);
					break;
			}
		}	
	}
}
// function used to set the voltage on specific pin of a certain port/register 
void DIO_write(uint8_t port,uint8_t pin, uint8_t data){
	//check which port/register this is
	switch (port){
		case 'A':
			// data= 0 it means low voltage, then we set the voltage of that pin to low using PA_DATA
			if(data == 0) 
					PA_DATA &=~(1<<pin);
			// else if data = 1 it means high voltage, then we set the voltage of that pin to high
			else if(data == 1){
					PA_DATA |=(1<<pin);
			}
			break;
		//same as port A
		case 'B':	
			if(data == 0)
				PB_DATA &=~(1<<pin);
			else if(data == 1){
				PB_DATA |=(1<<pin);
			}
			break;
		//same as port A
		case 'C':
			
			if(data == 0)
				PC_DATA &=~(1<<pin);
			else if(data == 1){
				PC_DATA |=(1<<pin);
			}
			break;
		//same as port A
		case 'D':
		
			if(data == 0)
			PD_DATA &=~(1<<pin);
			else if(data == 1){
				PD_DATA |=(1<<pin);
			}
			break;	
	}
}
// function used to read the voltage on a specific pin of a certain port/register
void DIO_read(uint8_t port,uint8_t pin, uint8_t *state){
		//check which port/register this is
		switch (port){
		case 'A':
			//if the state is not 0 then it means that there is a high voltage on that pin
			if((PA_STAT &(1<<pin)) != 0) 
				// then we update the state with high '1'	
				 *state = 1;
			// else indicates that the voltage on that pin is low,
			// we set state to low '0'
			else *state = 0;
			break;
		//same as port A
		case 'B':	
			if((PB_STAT &(1<<pin)) != 0)
			*state = 1;
			else *state = 0;
			break;
		//same as port A
		case 'C':
			if((PC_STAT &(1<<pin)) != 0)
			*state = 1;
			else *state = 0;
			break;
		//same as port A
		case 'D':
		
			if((PD_STAT &(1<<pin)) != 0)
			*state = 1;
			else *state = 0;
			break;	
	}
}