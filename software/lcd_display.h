/*
 * @file: lcd_display.h
 *
 * @brief: This module is written to control the onboard LCD on the MSP430FR4133 LaunchPad.
 * Utilizes a simple lookup table to easily display digits and simple alphabetical characters
 * for resistance values with units
 *
 * @author: jm5tang@uwaterloo.ca and a4jin@uwaterloo.ca
 */

#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_

#include <stdint.h>

#define LCD_DISPLAY_LUT_DIGITS_SIZE 10
#define LCD_DISPLAY_LUT_ALPHABET_SIZE 13
#define LCD_DISPLAY_SPACECHAR 0x0
#define LCD_DISPLAY_DIGITS 5

extern const char lcd_display_lut_digits[LCD_DISPLAY_LUT_DIGITS_SIZE];
extern const char lcd_display_lut_alphabet[LCD_DISPLAY_LUT_ALPHABET_SIZE];

/*
 * @brief: Initializes the lcd display for display usage
 */
void lcd_display_init(void);

/*
 * @brief: Displays the provided uint16_t to the screen
 *
 * @param num_input: The input number to display
 */
void lcd_display_show_on_screen(const uint16_t num_input, const char *unit);

#endif /* LCD_DISPLAY_H_ */
