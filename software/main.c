#include <msp430.h>
#include "driverlib.h"
#include "Board.h"

#include "lcd_display.h"
#include "adc.h"
#include "mux.h"

#define SYSTEM_DELAY 10000

void main (void) {
     WDT_A_hold(WDT_A_BASE);

     // Initialize
     adc_init();
     lcd_display_init();
     mux_init();

     // Select reference resistor
     mux_select(MUX_REF_RESISTOR_100_OHM);

     while(1) {
         __delay_cycles(SYSTEM_DELAY);
         lcd_display_show_on_screen(adc_read()); //call display function to show the numbers on the screen
     }
}
