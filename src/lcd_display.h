#include <stdint.h>

#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_

#define LCD_DISPLAY_LUT_DIGITS_SIZE 10
#define LCD_DISPLAY_LUT_ALPHABET_SIZE 13
#define LCD_DISPLAY_SPACECHAR 0x0

extern const char lcd_display_lut_digits[LCD_DISPLAY_LUT_DIGITS_SIZE];
extern const char lcd_display_lut_alphabet[LCD_DISPLAY_LUT_ALPHABET_SIZE];

void lcd_display_show_on_screen(const uint16_t num_input);
void lcd_display_init(void);

#endif /* LCD_DISPLAY_H_ */
