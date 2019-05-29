#include <LUT_LCD_Display.h>
#include "driverlib.h"

void LCD_Display_Setup(void){
    
    // L0 ̃L26 & L36 ̃L39 pins selected
     LCD_E_setPinAsLCDFunctionEx(LCD_E_BASE, LCD_E_SEGMENT_LINE_0, LCD_E_SEGMENT_LINE_26);
     LCD_E_setPinAsLCDFunctionEx(LCD_E_BASE, LCD_E_SEGMENT_LINE_36, LCD_E_SEGMENT_LINE_39);

     // Init LCD as 4-mux mode
     LCD_E_initParam initParams= {0};
     initParams.clockSource = LCD_E_CLOCKSOURCE_XTCLK;
     initParams.clockDivider = LCD_E_CLOCKDIVIDER_8;
     initParams.muxRate = LCD_E_4_MUX; initParams.waveforms = LCD_E_STANDARD_WAVEFORMS;
     initParams.segments = LCD_E_SEGMENTS_ENABLED;
     LCD_E_init(LCD_E_BASE, &initParams);

     // LCD Operation - Mode 3, internal 3.08v, charge pump 256Hz
     LCD_E_setVLCDSource(LCD_E_BASE, LCD_E_INTERNAL_REFERENCE_VOLTAGE, LCD_E_EXTERNAL_SUPPLY_VOLTAGE);
     LCD_E_setVLCDVoltage(LCD_E_BASE, LCD_E_REFERENCE_VOLTAGE_3_08V);
     LCD_E_enableChargePump(LCD_E_BASE);
     LCD_E_setChargePumpFreq(LCD_E_BASE, LCD_E_CHARGEPUMP_FREQ_16);

     // Clear LCD memory
     LCD_E_clearAllMemory(LCD_E_BASE);
     // Configure COMs and SEGs
     // L0, L1, L2, L3: COM pins
     // L0 = COM0, L1 = COM1, L2 = COM2, L3 = COM3
     LCD_E_setPinAsCOM(LCD_E_BASE, LCD_E_SEGMENT_LINE_0, LCD_E_MEMORY_COM0);
     LCD_E_setPinAsCOM(LCD_E_BASE, LCD_E_SEGMENT_LINE_1, LCD_E_MEMORY_COM1);
     LCD_E_setPinAsCOM(LCD_E_BASE,LCD_E_SEGMENT_LINE_2, LCD_E_MEMORY_COM2);
     LCD_E_setPinAsCOM(LCD_E_BASE, LCD_E_SEGMENT_LINE_3, LCD_E_MEMORY_COM3);
}

void LCD_Display_onScreen(const uint8_t *nums_array){
    uint8_t ten_thousands = nums_array[0];
    uint8_t thousands = nums_array[1];
    uint8_t hundreds = nums_array[2];
    uint8_t tens = nums_array[3];
    uint8_t ones = nums_array[4];

     // Display the number on the screen
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_4, LUT_DIGIT[ten_thousands]); // LCD Pin8-Pin9 for ten-thousands digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_6, LUT_DIGIT[thousands]); // LCD Pin12-Pin13 for thousands digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_8, LUT_DIGIT[hundreds]); // LCD Pin16-Pin17 for hundreds digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_10, LUT_DIGIT[tens]); // LCD Pin20-Pin21 for tens digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_2, LUT_DIGIT[ones]);  // LCD Pin4-Pin5 for ones digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_18,LUT_SPACE_CHAR);// LCD Pin36-Pin37 for space
}

void main (void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //initialize and set up LCD
    LCD_Display_Setup();

    uint16_t dividend = 5245; //number to be displayed
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
    //call display function to show the numbers on the screen
    LCD_Display_onScreen(num_to_display);

    // Turn on LCD
    LCD_E_on(LCD_E_BASE);
}