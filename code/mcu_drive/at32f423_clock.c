﻿/**
 **************************************************************************
 * @file     at32f423_clock.c
 * @brief    system clock config program
 **************************************************************************
 *                       Copyright notice & Disclaimer
 *
 * The software Board Support Package (BSP) that is made available to
 * download from Artery official website is the copyrighted work of Artery.
 * Artery authorizes customers to use, copy, and distribute the BSP
 * software and its related documentation for the purpose of design and
 * development in conjunction with Artery microcontrollers. Use of the
 * software is governed by this copyright notice and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
 * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
 * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
 * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
 * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
 *
 **************************************************************************
 */

/* includes ------------------------------------------------------------------*/
#include "at32f423_clock.h"

/** @addtogroup AT32F423_periph_template
 * @{
 */

/** @addtogroup 423_System_clock_configuration System_clock_configuration
 * @{
 */

/**
 * @brief  system clock config program
 * @note   the system clock is configured as follow:
 *         system clock (sclk)   = (hick / 12 * pll_ns)/(pll_ms * pll_fr)
 *         system clock source   = pll (hick)
 *         - lick                = on
 *         - lext                = off
 *         - hick                = on
 *         - hext                = off
 *         - sclk                = 150000000
 *         - ahbdiv              = 1
 *         - ahbclk              = 150000000
 *         - apb1div             = 2
 *         - apb1clk             = 75000000
 *         - apb2div             = 1
 *         - apb2clk             = 150000000
 *         - pll_ns              = 75
 *         - pll_ms              = 1
 *         - pll_fr              = 2
 * @param  none
 * @retval none
 */
void system_clock_config(void)
{
  /* reset crm */
  crm_reset();

  /* config flash psr register */
  flash_psr_set(FLASH_WAIT_CYCLE_4);

  /* enable pwc periph clock */
  crm_periph_clock_enable(CRM_PWC_PERIPH_CLOCK, TRUE);

  /* config ldo voltage */
  pwc_ldo_output_voltage_set(PWC_LDO_OUTPUT_1V3);

  /* enable lick */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_LICK, TRUE);

  /* wait till lick is ready */
  while (crm_flag_get(CRM_LICK_STABLE_FLAG) != SET)
  {
  }

  /* enable hick */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_HICK, TRUE);

  /* wait till hick is ready */
  while (crm_flag_get(CRM_HICK_STABLE_FLAG) != SET)
  {
  }

  /* config pll clock resource
  common frequency config list: pll source selected  hick or hext(8mhz)
  _____________________________________________________________________________
  |        |         |         |         |         |         |        |        |
  | sysclk |   150   |   144   |   120   |   108   |   96    |   72   |   36   |
  |________|_________|_________|_________|_________|_________|_________________|
  |        |         |         |         |         |         |        |        |
  |pll_ns  |   75    |   72    |   120   |   108   |   96    |   72   |   72   |
  |        |         |         |         |         |         |        |        |
  |pll_ms  |   1     |   1     |   1     |   1     |   1     |   1    |   1    |
  |        |         |         |         |         |         |        |        |
  |pll_fr  |   FR_2  |   FR_2  |   FR_4  |   FR_4  |   FR_4  |   FR_4 |   FR_8 |
  |________|_________|_________|_________|_________|_________|________|________|

  if pll clock source selects hext with other frequency values, or configure pll to other
  frequency values, please use the at32 new clock  configuration tool for configuration. */
  crm_pll_config(CRM_PLL_SOURCE_HICK, 75, 1, CRM_PLL_FR_2);

  /* enable pll */
  crm_clock_source_enable(CRM_CLOCK_SOURCE_PLL, TRUE);

  /* wait till pll is ready */
  while (crm_flag_get(CRM_PLL_STABLE_FLAG) != SET)
  {
  }

  /* config ahbclk */
  crm_ahb_div_set(CRM_AHB_DIV_1);

  /* config apb2clk, the maximum frequency of APB2 clock is 150 MHz  */
  crm_apb2_div_set(CRM_APB2_DIV_1);

  /* config apb1clk, the maximum frequency of APB1 clock is 120 MHz  */
  crm_apb1_div_set(CRM_APB1_DIV_2);

  /* enable auto step mode */
  crm_auto_step_mode_enable(TRUE);

  /* select pll as system clock source */
  crm_sysclk_switch(CRM_SCLK_PLL);

  /* wait till pll is used as system clock source */
  while (crm_sysclk_switch_status_get() != CRM_SCLK_PLL)
  {
  }

  /* disable auto step mode */
  crm_auto_step_mode_enable(FALSE);

  /* update system_core_clock global variable */
  system_core_clock_update();
}

/**
 * @}
 */

/**
 * @}
 */
