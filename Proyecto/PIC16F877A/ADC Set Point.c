/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
ADC Set Point.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
---------------------------------------------------------------------------
Implementar una lectura analógica de un potenciómetro, si el valor del ADC supera
un Set Point, el LED encenderá.
---------------------------------------------------------------------------
*/

#include <16F877A.h>                 //Incluye el microcontrolador con el que se va a trabajar 
#DEVICE ADC=8                        //Configura el ADC a 8 bits
#use delay ( clock=20Mhz, crystal )  //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

#define LED PIN_A1                   //Pin donde está conectado el LED del X-TRAINER

int ValorPot;                        //Variable para almacenar el valor leído del ADC

void main ( void ) {
    setup_adc_ports ( AN0 );         //Configura solo el puerto A0 como entrada analógica
    setup_adc ( ADC_CLOCK_DIV_8 );   //Configura oscilador para la conversión

    while ( 1 ) {
        set_adc_channel ( 0 );       //Selecciona el canal 0 para la conversión
        ValorPot = read_adc ( );     //Lee el valor del ADC y lo guarda en la variable

        if ( ValorPot >= 128 ) {     //Compara el valor de el ADC con 128
            output_HIGH ( LED );     // Leds activos
        } else {
            output_LOW ( LED );      // Leds activos
        }
    }
}