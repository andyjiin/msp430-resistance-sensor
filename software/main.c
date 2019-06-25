#include <limits.h>
#include <msp430.h>
#include "driverlib.h"
#include "Board.h"

#include "lcd_display.h"
#include "adc.h"
#include "mux.h"
#include "resistance.h"
#include "indicator.h"

#define SYSTEM_DELAY 100000

void main (void) {
    WDT_A_hold(WDT_A_BASE);

     // Initialize modules
     adc_init();
     lcd_display_init();
     mux_init();
     indicator_init();

     // Select reference resistor to begin characterization
     mux_ref_resistor ref_resistor = MUX_REF_RESISTOR_33_OHM;
     mux_select(ref_resistor);

     bool auto_range = false;

     while(1) {
         // Read the voltage from the ADC and calculate the resistance
         uint16_t voltage = adc_read();
         uint32_t resistance = RESISTANCE_CALCULATE(voltage, mux_convert_resistance(ref_resistor));

         // Perform adjustments on the calculated resistance (auto-ranging)
         // If the resistance is within range of the reference resistor
         if (resistance > 0 && resistance < MUX_REF_RESISTOR_33_OHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_33_OHM) { // If we need to update the reference resistor
                 ref_resistor = MUX_REF_RESISTOR_33_OHM;
                 auto_range = true;
                 indicator_set(false);
             }
         } else if (resistance >= MUX_REF_RESISTOR_33_OHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_100_OHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_100_OHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_100_OHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else if (resistance >= MUX_REF_RESISTOR_100_OHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_470_OHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_470_OHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_470_OHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else if (resistance >= MUX_REF_RESISTOR_470_OHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_1_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_1_KOHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_1_KOHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else if (resistance >= MUX_REF_RESISTOR_1_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_10_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_10_KOHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_10_KOHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else if (resistance >= MUX_REF_RESISTOR_10_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_100_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_100_KOHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_100_KOHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else if (resistance >= MUX_REF_RESISTOR_100_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_560_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_560_KOHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_560_KOHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else if (resistance >= MUX_REF_RESISTOR_560_KOHM_UPPER_BOUND && resistance < MUX_REF_RESISTOR_1120_KOHM_UPPER_BOUND) {
             if (ref_resistor != MUX_REF_RESISTOR_1120_KOHM) { // If we need to update the reference resistor
                  ref_resistor = MUX_REF_RESISTOR_1120_KOHM;
                  auto_range = true;
                  indicator_set(false);
              }
         } else {
             // If we have reached here, it means that the resistance calculated may not be reliable as it is not within
             // the acceptable range of this module
             indicator_set(true);
         }

         // If the auto-range flag is set, we must update the reference resistor correspondingly
         if (auto_range) {
             auto_range = false;
             mux_select(ref_resistor);
         }

         // TODO: Handle units via the LCD
         if (resistance > USHRT_MAX) {
             resistance = resistance/1000;
         }

         lcd_display_show_on_screen(resistance); // Call display function to show the numbers on the screen
         __delay_cycles(SYSTEM_DELAY); // System delay
     }
}
