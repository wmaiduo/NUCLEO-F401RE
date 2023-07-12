#ifndef ADC_H
#define ADC_H

uint32_t pa5_adc_read(void);
void adc_init_start(void);

#define ADC_PIN GPIO_PIN_5

#endif
