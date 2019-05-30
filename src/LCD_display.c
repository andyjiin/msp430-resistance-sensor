#include "lcd_display.h"
#include "driverlib.h"

void lcd_display_show_on_screen(const uint16_t num_input){

    uint16_t dividend = num_input;
    uint8_t num_to_display[5];
    uint16_t divisor =10000;
    uint8_t i=0;

    //loop to isolate each digit, starting from the ten-thousands digit and place each digit in array
    while (divisor>=1){
        num_to_display[i] = dividend/divisor;
        dividend = dividend%divisor;
        i++;
        divisor/=10;
    }
    uint8_t ten_thousands = num_to_display[0];
    uint8_t thousands = num_to_display[1];
    uint8_t hundreds = num_to_display[2];
    uint8_t tens =num_to_display[3];
    uint8_t ones = num_to_display[4];

     // Display the number on the screen
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_4, lcd_display_lut_digits[ten_thousands]); // LCD Pin8-Pin9 for ten-thousands digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_6, lcd_display_lut_digits[thousands]); // LCD Pin12-Pin13 for thousands digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_8,lcd_display_lut_digits[hundreds]); // LCD Pin16-Pin17 for hundreds digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_10,lcd_display_lut_digits[tens]); // LCD Pin20-Pin21 for tens digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_2, lcd_display_lut_digits[ones]);  // LCD Pin4-Pin5 for ones digit
    LCD_E_setMemory(LCD_E_BASE, LCD_E_MEMORY_BLINKINGMEMORY_18,lcd_display_spacechar);// LCD Pin36-Pin37 for space
}

void lcd_display_init(void){

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

//lookup table for digits on MSP-EXP430FR4133 segmented LCD
const char lcd_display_lut_digits[10] = {
    0xFC, /* "0" */
    0x60, /* "1" */
    0xDB, /* "2" */
    0xF3, /* "3" */
    0x67, /* "4" */
    0xB7, /* "5" */
    0xBF, /* "6" */
    0xE4, /* "7" */
    0xFF, /* "8" */
    0xF7 /* "9" */
};

//SPACE character
const char lcd_display_spacechar = 0x00;

//look up table to alphabetical numbers, INCOMPLETE
const char lcd_display_lut_alphabet[13]={
    0xEF, /* 0 , "A" */
    0xFF, /* 1, "B" */
    0x9C, /* 2, "C" */
    0xFC, /* 3, "D" */
    0X9F, /* 4, "E" */
    0x8F, /* 5, "F" */
    0xBD, /* 6, "G" */
    0x6F, /* 7, "H" */
          /* "I" */
    0x78, /* "J" */
    0xFC, /* "O" */
    0xCF, /* "P" */
    0x7C,  /* "U" */
    0x77, /* "Y" */
};
