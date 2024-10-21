#ifndef __LED_DRIVE_H__
#define __LED_DRIVE_H__

#include "at32f423.h"
#include "at32f423_wk_config.h"

#define BLUE_LED_ON LED_B_GPIO_PORT->clr ^= LED_B_PIN
#define BLUE_LED_OFF LED_B_GPIO_PORT->scr ^= LED_B_PIN
#define BLUE_LED_FLICKER LED_B_GPIO_PORT->odt ^= LED_B_PIN

#define GREEN_LED_ON LED_G_GPIO_PORT->clr ^= LED_G_PIN
#define GREEN_LED_OFF LED_G_GPIO_PORT->scr ^= LED_G_PIN
#define GREEN_LED_FLICKER LED_G_GPIO_PORT->odt ^= LED_G_PIN

#define RED_LED_ON LED_R_GPIO_PORT->clr ^= LED_R_PIN
#define RED_LED_OFF LED_R_GPIO_PORT->scr ^= LED_R_PIN
#define RED_LED_FLICKER LED_R_GPIO_PORT->odt ^= LED_R_PIN


#define EN_3V_ON EN_3V_GPIO_PORT->clr ^= EN_3V_PIN
#define EN_3V_OFF EN_3V_GPIO_PORT->scr ^= EN_3V_PIN
#define EN_3V_FLICKER EN_3V_GPIO_PORT->odt ^= EN_3V_PIN

#define RED_GREEN_BLUE 1  //红绿蓝闪烁
#define RED_GREEN      2  //红蓝闪烁
#define RED_BLUE       3  //红绿闪烁
#define GREEN_BLUE     4  //绿蓝闪烁
#define RED            5  //红闪
#define GREEN          6  //绿闪
#define BLUE           7  //蓝闪
#define CYAN           8  //青闪
#define YELLOW         9  //黄闪
#define PURPLE         10 //紫闪
#define WHITE          11 //白闪
#define CYAN_RED       12 //青红闪烁
#define YELLOW_BLUE    13 //黄蓝闪烁
#define PURPLE_GREEN   14 //紫绿闪烁

#define REDON          15 //红灯长亮
#define GREENON        16 //绿灯长亮
#define BLUEON         17 //蓝灯长亮
#define CYANON         18 //青灯长亮
#define YELLOWON       19 //黄灯长亮
#define PURPLEON       20 //紫灯长亮
#define WHITEON        21 //白灯长亮
#define CLOSE_LED_MOD  0
#define CLOSE_LED_MOD1 255

typedef struct
{
    uint8_t ledmod;
    uint8_t led_flag;
} LED_CONFIG_DATA;

void SET_LedMod(uint8_t ledmod);
void LedState(void);
void LED_Handler(void);

#endif
