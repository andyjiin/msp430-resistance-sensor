#include <msp430.h>
#include "lcd_display.h"
#include "driverlib.h"
#include <stdint.h>

void main (void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    lcd_display_init(); //initialize and set up LCD
    uint16_t dividend = 773; //number to be displayed
    uint8_t num_to_display[5];
    uint16_t divisor =10000;
    uint8_t i=0;

    //loop to isolate each digit, starting from the ten-thousands digit and place each digit in array
    while (divisor>=1){
        num_to_display[i] = dividend/divisor;
        dividend = dividend%divisor;
        i++;
        divisor /=10;
     }
     
    lcd_display_show_on_screen(num_to_display); //call display function to show the numbers on the screen
    LCD_E_on(LCD_E_BASE); // Turn on LCD
}
