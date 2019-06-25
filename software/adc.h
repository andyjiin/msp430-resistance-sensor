/*
 * @file: adc.h
 *
 * @brief: Module to control the MSP430FR4133 onboard ADC with internal reference voltage of 3.3V.
 * Currently ADC is only active on analog pins defined in Board.h
 *
 * @author: a4jin@uwaterloo.ca
 */

#ifndef ADC_H_
#define ADC_H_

// y = 3.1902x + 10.337
#define ADC_VOLTAGE_CONVERT(reading) ((((uint16_t)(reading)) * 3.2) + 10)

/*
 * @brief: Initializes the ADC module and appropriate analog pins
 */
void adc_init(void);

/*
 * @brief: Reads the converted ADC value
 *
 * @return: The voltage read back from ADC in millivolts
 */
uint16_t adc_read(void);

#endif /* ADC_H_ */
