#ifndef ADC_H_
#define ADC_H_

// y = 3.1902x + 10.337
#define ADC_VOLTAGE_CONVERT(reading) ((((uint16_t)(reading)) * 3.2) + 10)

void adc_init(void);

uint16_t adc_read(void);

#endif /* ADC_H_ */
