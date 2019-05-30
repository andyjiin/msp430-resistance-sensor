#include <stdint.h>

#ifndef LCD_DISPLAY_H_
#define LCD_DISPLAY_H_

extern const char lcd_display_lut_digits[10];
extern const char lcd_display_spacechar;
extern const char lcd_display_lut_alphabet[13];

void lcd_display_show_on_screen(const uint8_t *nums_array);
void lcd_display_init(void);

#endif /* LCD_DISPLAY_H_ */
