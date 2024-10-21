#ifndef __FLASH_DRIVE_H__
#define __FLASH_DRIVE_H__

#include "at32f423.h"

#define FLASH_PAGE_SIZE ((uint32_t)0x00000800)

void FlashErase(uint32_t str, uint8_t NbrOfPage);
void FlashProgramAllow(void);
void FlashProgramForbid(void);

void Erase_Flash(uint32_t str, uint8_t NbrOfPage);
void ProgramFlashWord(uint32_t str, uint32_t data);
void ProgramFlashHalfWord(uint32_t str, uint16_t data);

#endif
