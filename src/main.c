#include <msp430.h>
#include "lcd_display.h"
#include "driverlib.h"
#include <stdint.h>

void main (void)
{   
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    lcd_display_init(); //initialize and set up LCD

    uint16_t num_input = 703; //number to be displayed

    lcd_display_show_on_screen(num_input); //call display function to show the numbers on the screen
    LCD_E_on(LCD_E_BASE); // Turn on LCD
}
