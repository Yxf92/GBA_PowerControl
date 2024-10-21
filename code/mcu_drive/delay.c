#include "delay.h"
#include "main.h"
// 共用一个__delay_us作为基础延时函数
void __delay_us(uint32_t us)
{
    uint32_t temp;
    /* LOAD寄存器不能设为0，此时CTRL寄存器最高位无法置1，进入while后死循环 */
    if (us == 0)
        return;
    SysTick->CTRL &= 0xfffffffb;
    SysTick->LOAD = (uint32_t)us * 18;        // 设置重装载值 us * system_core_clock / 8000000
    SysTick->VAL = 0x00;                      // 将定时器归零
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; // 开启定时器
    // 这里通过循环判断定时器的状态位值来确认定时器是否已归零
    do
    {
        temp = SysTick->CTRL; // 获取定时器的状态值
    } while ((temp & 0x01) && !(temp & (1 << 16)));
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; // 关闭定时器
    SysTick->VAL = 0x00;                       // 将定时器归零
}

void delay_s(uint8_t s)
{
    while (s)
    {
        delay_ms(500);
        delay_ms(500);
        s--;
    }
}

void delay_ms(uint16_t ms)
{
    if (ms >= 1000)
    {
        delay_s(ms / 1000);
    }
    /* 小于1s剩余的时间 */
    __delay_us((ms %= 1000) * 1000);
}

void delay_us(uint32_t us)
{
    if (us >= 1000)
    {
        delay_ms(us / 1000);
    }
    /* 小于1ms剩余的时间 */
    __delay_us(us %= 1000);
}
