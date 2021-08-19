#include "stm32f40x_system.h"


void stm32f4SystemInit(){
  // enable HSE
  _system_clock_settings->AHB_Prescaler = 1;
  _system_clock_settings->APB1_Prescaler = 4;
  _system_clock_settings->APB2_Prescaler = 2;
  _system_clock_settings->PLLM = 5;
  _system_clock_settings->PLLN = 210;
  _system_clock_settings->PLLP = 0;
  stm32f4HseClockStartup();

  // configure systick
  configure_systick(); 

  // enable all GPIO clocks
  enableGpioPeripheralClocks();
}

void stm32f4HseClockStartup(){
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

void enableGpioPeripheralClocks(){
  RCC->AHB1ENR |= 0b111111111;
}

void configure_systick(){
  /*
  Enable SysTick for time keeping
  Steps:
  1. Disable SysTick
  2. Set the reload register
  3. Set the NVIC priority (to least urgent)
  4. Reset the counter value (this is randomly set at startup and should be cleared)
  5. Set the Clock Source, Interrupt enable, and enable sysTick
  */


  // 1. Disable SysTick
  STK->CTRL = 0;
  // 2. Set the reload register
  STK->LOAD = 167999; // 1 ms ticks
  // 3. Set the NVIC priority level (TODO)
  // *(volatile uint32_t*)
  // *(volatile uint32_t*)NVIC_ISER0
  // 4. Reset the counter value
  STK->VAL = 0;
  // 5. Set the Clock Source, Interrupt enable, and enable sysTick
  STK->CTRL = 1<<2|1<<1|1<<0;
}

// exceptions
void SysTick_Handler(void){
  _msTicks++;
}
