#include "flash.h"
#include "delay.h"
#include "main.h"

void Forbid_INT(void)
{
    usart_enable(USART1, FALSE);
    __set_PRIMASK(1);
    // delay_ms(1);
}

void Allow_INT(void)
{
    // delay_ms(1);
    usart_enable(USART1, TRUE);
    __set_PRIMASK(0);
}

void FlashErase(uint32_t str, uint8_t NbrOfPage)
{
    Forbid_INT();
    flash_unlock();
    Erase_Flash(str, NbrOfPage);
    flash_lock();
    Allow_INT();
}

void FlashProgramAllow(void)
{
    Forbid_INT();
    flash_unlock();
}

void FlashProgramForbid(void)
{
    flash_lock();
    Allow_INT();
}

void Erase_Flash(uint32_t str, uint8_t NbrOfPage)
{
  uint8_t EraseCounter = 0;
  flash_flag_clear(FLASH_EPPERR_FLAG | FLASH_PRGMERR_FLAG);
  for (EraseCounter = 0; (EraseCounter < NbrOfPage); EraseCounter++)
  {
    if (flash_sector_erase(str + (FLASH_PAGE_SIZE * EraseCounter)) != FLASH_OPERATE_DONE)
    {
      while (1)
      {
        RED_LED_FLICKER;
        delay_ms(100);
      }
    }
  }
}

void ProgramFlashWord(uint32_t str, uint32_t data)
{
  if (flash_word_program(str, data) != FLASH_OPERATE_DONE)
  {
    while (1)
    {
      RED_LED_FLICKER;
      delay_ms(200);
    }
  }
}

void ProgramFlashHalfWord(uint32_t str, uint16_t data)
{
  if (flash_halfword_program(str, data) != FLASH_OPERATE_DONE)
  {
    while (1)
    {
      RED_LED_FLICKER;
      delay_ms(200);
    }
  }
}
