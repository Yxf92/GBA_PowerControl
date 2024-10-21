#ifndef __TARGET_H__
#define __TARGET_H__

#include "at32f423.h"
#include "main.h"

/****************          led config          ****************/
#define RED_LED_PORT GPIOA
#define RED_LED_PIN GPIO_PINS_15

#define GREEN_LED_PORT GPIOB
#define GREEN_LED_PIN GPIO_PINS_3

#define BLUE_LED_PORT GPIOB
#define BLUE_LED_PIN GPIO_PINS_4

#define GB_LED_GPIO_PORT    GPIOB
#define GB_LED_PIN    GPIO_PINS_6

#define BLUE_LED_ON BLUE_LED_PORT->clr ^= BLUE_LED_PIN
#define BLUE_LED_OFF BLUE_LED_PORT->scr ^= BLUE_LED_PIN
#define BLUE_LED_FLICKER BLUE_LED_PORT->odt ^= BLUE_LED_PIN

#define GREEN_LED_ON GREEN_LED_PORT->clr ^= GREEN_LED_PIN
#define GREEN_LED_OFF GREEN_LED_PORT->scr ^= GREEN_LED_PIN
#define GREEN_LED_FLICKER GREEN_LED_PORT->odt ^= GREEN_LED_PIN

#define RED_LED_ON RED_LED_PORT->clr ^= RED_LED_PIN
#define RED_LED_OFF RED_LED_PORT->scr ^= RED_LED_PIN
#define RED_LED_FLICKER RED_LED_PORT->odt ^= RED_LED_PIN

#define GB_LED_OFF GB_LED_GPIO_PORT->clr ^= GB_LED_PIN
#define GB_LED_ON GB_LED_GPIO_PORT->scr ^= GB_LED_PIN
#define GB_LED_FLICKER GB_LED_GPIO_PORT->odt ^= GB_LED_PIN

/****************         usart1 config        ****************/
#define USART1_RCC_Periph CRM_USART1_PERIPH_CLOCK

#define USART1_TX_PORT GPIOA
#define USART1_TX_PIN GPIO_PINS_9
#define USART1_TX_MODE GPIO_MODE_MUX

#define USART1_RX_PORT GPIOA
#define USART1_RX_PIN GPIO_PINS_10
#define USART1_RX_MODE GPIO_MODE_INPUT

/****************         adc config        ****************/
#define ADCRESOLUTION 4096.0f // ADC的分辨率
#define ADCRANGE 3.3f         // ADC参考电压值
#define ADCOFFSET -20.0f        // ADC采样偏移

#define CURSAMPRES 0.01f // 电流采样电阻阻值 欧姆
#define CURGAIN 1.0f     // 运放放大系数
#define CUROFFSET 0.0f // 运放输出偏移

#define RES_DIV 0.0909f  // 100k / (100k + 10k) / 10

/****************         VBAT adc config        ****************/
#define VBAT_PORT GPIOA
#define VBAT_PIN GPIO_PINS_0
#define VBAT_ADC_CHANNEL ADC_CHANNEL_0
#define VBAT_ADC adc_value[0]

/****************         ADC_3V adc config        ****************/
#define ADC_3V_PORT GPIOA
#define ADC_3V_PIN GPIO_PINS_1
#define ADC_3V_ADC_CHANNEL ADC_CHANNEL_1
#define ADC_3V_ADC adc_value[1]

/****************         VBAT & PROTECT        ****************/
#define EN_3V_PIN    GPIO_PINS_1
#define EN_3V_GPIO_PORT    GPIOB

#define EN_3V_RESET EN_3V_GPIO_PORT->clr ^= EN_3V_PIN
#define EN_3V_SET EN_3V_GPIO_PORT->scr ^= EN_3V_PIN

/****************           DAC CONFIG        ****************/
#define V_CON_PIN    GPIO_PINS_4
#define V_CON_GPIO_PORT    GPIOA

#endif
