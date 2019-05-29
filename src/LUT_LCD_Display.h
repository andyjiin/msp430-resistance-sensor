/*
 * lookup_table_LCD.h
 *
 *  Created on: May 28, 2019
 *      Author: KellyTang
 */

#ifndef LUT_LCD_DISPLAY_H_
#define LUT_LCD_DISPLAY_H_

//SPACE character
const char LUT_SPACE_CHAR = 0x00;

//lookup table for digits on MSP-EXP430FR4133 segmented LCD
const char LUT_DIGIT[10] = {
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

//look up table to alphabetical numbers, INCOMPLETE
const char LUT_ALHBETICAL_UPPERCASE[13]={
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

#endif /* LUT_LCD_DISPLAY_H_ */
