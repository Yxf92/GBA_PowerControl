#include "at32f423.h"
#include "target.h"
#include "wdt.h"

void WDT_Init(void)
{
  wdt_register_write_enable(TRUE);
  wdt_divider_set(WDT_CLK_DIV_4);
  wdt_reload_value_set(0xBB7);
  wdt_counter_reload();
  /* if enabled, please feed dog */
  //wdt_enable();
}
