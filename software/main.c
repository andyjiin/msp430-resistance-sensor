#include <limits.h>
#include <msp430.h>
#include "driverlib.h"
#include "Board.h"

#include "lcd_display.h"
#include "adc.h"
#include "mux.h"
#include "resistance.h"

#define SYSTEM_DELAY 100000

void main (void) {
    WDT_A_hold(WDT_A_BASE);

     // Initialize
     adc_init();
     lcd_display_init();
     mux_init();

     // Select reference resistor to begin characterization
     mux_ref_resistor ref_resistor = MUX_REF_RESISTOR_1_KOHM;
     mux_select(ref_resistor);

     bool auto_range = false;

     while(1) {
         __delay_cycles(SYSTEM_DELAY);
         uint16_t voltage = adc_read();
         uint32_t resistance = RESISTANCE_CALCULATE(voltage, mux_convert_resistance(ref_resistor));
         // If the resistance is above
         if (resistance > 0 && resistance < MUX_REF_RESISTOR_33_OHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_33_OHM) {
                 ref_resistor = MUX_REF_RESISTOR_33_OHM;
                 auto_range = true;
             }
         } else if (resistance >= MUX_REF_RESISTOR_33_OHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_100_OHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_100_OHM) {
                  ref_resistor = MUX_REF_RESISTOR_100_OHM;
                  auto_range = true;
              }
         } else if (resistance >= MUX_REF_RESISTOR_100_OHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_470_OHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_470_OHM) {
                  ref_resistor = MUX_REF_RESISTOR_470_OHM;
                  auto_range = true;
              }
         } else if (resistance >= MUX_REF_RESISTOR_470_OHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_1_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_1_KOHM) {
                  ref_resistor = MUX_REF_RESISTOR_1_KOHM;
                  auto_range = true;
              }
         } else if (resistance >= MUX_REF_RESISTOR_1_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_10_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_10_KOHM) {
                  ref_resistor = MUX_REF_RESISTOR_10_KOHM;
                  auto_range = true;
              }
         } else if (resistance >= MUX_REF_RESISTOR_10_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_100_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_100_KOHM) {
                  ref_resistor = MUX_REF_RESISTOR_100_KOHM;
                  auto_range = true;
              }
         } else if (resistance >= MUX_REF_RESISTOR_100_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_560_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_560_KOHM) {
                  ref_resistor = MUX_REF_RESISTOR_560_KOHM;
                  auto_range = true;
              }
         } else if (resistance >= MUX_REF_RESISTOR_560_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_1120_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_1120_KOHM) {
                  ref_resistor = MUX_REF_RESISTOR_1120_KOHM;
                  auto_range = true;
              }
         } else {
             // TODO: Turn on warning lights
         }

         if (auto_range) {
             auto_range = false;
             mux_select(ref_resistor);
         }

         // TODO: Handle units
         if (resistance > USHRT_MAX) {
             resistance = resistance/RESISTANCE_OHM_PER_KOHM;
         }

         lcd_display_show_on_screen(resistance); // Call display function to show the numbers on the screen
     }
}
