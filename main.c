/*
 * LED toggle.c
 * Created: 8/17/2020 12:27:39 PM
 * Author : Ahmed
 */
#include "hardware/registers.h"
#include "MCAL/DIO_Driver/DIO.h"
// configuration array 8x4 that specifies whether the pin will be input "in" or output "out"
// Note: default is 0 which is the same as input "in"
uint8_t configuration [no_of_registers][no_of_pins] = {{out,0,0,0,0,0,0,0},		//A
													   {0,0,0,0,0,0,0,0},		//B
													   {in,0,0,0,0,0,0,0},		//C
													   {0,0,0,0,0,0,0,0}};		//D
							
 
int main(void)
{	// initializing the DIO driver with the values inside the configuration array 
	DIO_init(configuration);
	// flags that will indicate the states of the button and the LED
	uint8_t prev_button_state = 0,button_state, LED_state;
 //Logic of the application is put inside a while loop
 while (1) 
    {	//DIO's function "DIO_read" checks the voltage on the pin (high or low), and returns button state
		// button state will be '1' if the button is being pushed, '0' otherwise
		DIO_read('C',pin_zero, &button_state);
		//comparing the current button state and previous state, 
		//this check will prevent the LED toggle while the button is being pushed, 
		//and will indicate that the button is being pressed now
		if(button_state == 1 && prev_button_state == 0){
			// check the pin voltage that is connected to the LED, and store it in the LED_state
			DIO_read('A',pin_zero, &LED_state);
			
			// whatever the current LED_state, it will be changed to the opposite value
			if(LED_state == 1){
				// passing low voltage through the pin (turning LED off)
				DIO_write('A',pin_zero,0);
			}	// passing high voltage through the pin (turning LED on)	
			else DIO_write('A',pin_zero,1);
			// storing the button_state to be used later
			prev_button_state = button_state;
		}
		// this checks whether the pin is released or not
		if(button_state == 0 && prev_button_state == 1){
			// if the button is released, we store the button_state to be used later
			prev_button_state = button_state;
		}
	}
}

