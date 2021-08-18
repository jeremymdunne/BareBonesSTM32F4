#include "stm32f40x_system.h"

void stm32f4_hse_clock_startup(){
  /*
  Steps:
  1. Enable HSE and wait for ready
  2. Set Power Enable and Voltage Regulator
  3. Configure flash
  4. Configure prescalers
  5. Configure main PLL
  6. Enable PLL and wait for ready
  7. Select clock source
  */

  // 1. Enable HSE and wait for ready
  RCC->CR |= 1<<16;
  while(!(RCC->CR & (1<<17)));

  // 2. Set Power Enable and Voltage Regulator
  RCC->APB1ENR |= 1<<28;

  // 3. Configure flash
  FLASH->ACR |= (1<<9) | (1<<10) | (1<<8) | (5);

  // 4. Configure prescalers
  RCC->CFGR |= _system_clock_settings->AHB_Prescaler << 4; // AHB Prescaler to 1
  RCC->CFGR |= _system_clock_settings->APB1_Prescaler << 10; // APB1 Prescaler to 4
  RCC->CFGR |= _system_clock_settings->APB2_Prescaler << 13; // APB2 Prescaler to 2

  // 5. Configure main PLL
  RCC->PLLCFGR = (_system_clock_settings->PLLM<<0); // PLLM
  RCC->PLLCFGR |= (_system_clock_settings->PLLN<<6); // PLLN
  RCC->PLLCFGR |= (_system_clock_settings->PLLP<<16); // PLLP
  RCC->PLLCFGR |= (1<<22); // Select HSE as source

  // 6. Enable PLL and wait for ready
  RCC->CR |= 1<<24;
  while(!(RCC->CR & (1<<25)));

  // 7. Select clock source
  RCC->CFGR |= 2;
  // wait for ready
  while(!(RCC->CFGR & (2<<2)));
}
