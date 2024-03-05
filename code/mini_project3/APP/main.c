/*
 * main.c
 *
 *  Created on: Oct 14, 2023
 *      Author: mario
 */
#include"HAL/LM35.h"
#include"HAL/LCD.h"
#include"HAL/DCmotor.h"

int main(void){

	/* adjust ADC configurations */
	ADC_configType ADC_configrations = {INTERNAL256,FACTOR8};
	uint8 temperature;

/* Initiate ADC, LCD and DC-motor */
	ADC_init(&ADC_configrations);
	DCmotor_init();
	LCD_init();

	LCD_displayStringRowColumn("Fan is ",1,0);

	LCD_displayStringRowColumn("Temp = ",2,0);


	while(1){

		temperature = LM35_getTemperature();

		if(temperature < 30){
			DCmotor_rotate(STOP,0);
			LCD_displayStringRowColumn("OFF",1,7);
			LCD_moveCursor(2,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' '); /* To clear third digit */
		}

		else if(temperature >= 30 && temperature < 60){
			DCmotor_rotate(CW,25);
			LCD_displayStringRowColumn("ON 25%",1,7);
			LCD_moveCursor(2,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' '); /* To clear third digit */
		}

		else if(temperature >= 60 && temperature < 90){
			DCmotor_rotate(CW,50);
			LCD_displayStringRowColumn("ON 50%",1,7);
			LCD_moveCursor(2,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' '); /* To clear third digit */
		}

		else if(temperature >= 90 && temperature < 120){
			DCmotor_rotate(CW,75);
			LCD_displayStringRowColumn("ON 75%",1,7);
			LCD_moveCursor(2,7);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' '); /* To clear third digit */
		}

		else if(temperature >= 120){
			DCmotor_rotate(CW,100);
			LCD_displayStringRowColumn("ON 100%",1,7);
			LCD_moveCursor(2,7);
			LCD_intgerToString(temperature);
		}
	}


}//end main
