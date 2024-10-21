#ifndef __ADC_H__
#define __ADC_H__

#include "at32f423.h"

#define ADC_VALUE_LEN 2

extern __IO uint16_t adc_value[ADC_VALUE_LEN];

void ADC1_Init(void);

#endif /* __ADC_H__ */
