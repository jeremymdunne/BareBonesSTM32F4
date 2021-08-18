

#include "stm32f40x_system.h"

volatile uint32_t msTicks = 0;
volatile uint32_t tim2_ticks = 0;


int main(void){
  // clock_startup();

  // _stm32f4_clock_settings_t clock_settings;
  _system_clock_settings->AHB_Prescaler = 1;
  _system_clock_settings->APB1_Prescaler = 4;
  _system_clock_settings->APB2_Prescaler = 2;
  _system_clock_settings->PLLM = 5;
  _system_clock_settings->PLLN = 210;
  _system_clock_settings->PLLP = 0;
  stm32f4_hse_clock_startup();
  // configure_systick();

  //enable TIM2
  RCC->APB1ENR |= 1;
  NVIC->IPR[28] |= 0x03 << 4;
  NVIC->ISER[0] |= 1<<28;

  TIM2->PSC = 0;
  TIM2->ARR = 1;
  TIM2->EGR = 1;
  TIM2->DIER = 1;
  TIM2->CR1 |= (1<<7) | 1;


  // enable peripheral clock
  RCC->AHB1ENR |= 1<<0;
  RCC->AHB1ENR |= 1<<4;

  // setup PA6 as an output
  GPIOA->MODER |= 1 << 12;
  GPIOA->ODR = 1<<6;
  // GPIOA->BSRR = 1<<6;
  // setup PA7 as an output
  GPIOA->MODER |= 1 << 14;
  GPIOA->ODR |= 0<<7;
  GPIOA->ODR |= 1<<7;

  // while(1);
  // GPIOA->BSRR = 1<<(7+16);
  // setup PE4 as an input
  GPIOE->MODER |= 0<<4;
  GPIOE->PUPDR |= 1<<8;


  // setupTimer();

  // *(volatile uint32_t *)GPIOA_OSPEEDR |= 0 << 12;
  // *(volatile uint32_t *)GPIOA_OTYPER |= 0 << 6;
  // *(volatile uint32_t *)GPIOA_PUPDR |= 0 << 12;

  while(1){
    if(GPIOE->IDR & (1<<4)){
      // button pressed, turn on PA7
      GPIOA->ODR = 1<<7;
    }
    else{
      GPIOA->ODR = 0;
    }
  }

  while(1){
    GPIOA->ODR = 0 << 7;
    // *(volatile uint32_t *)(GPIOA_BSRR) = 1 << (6 + 16);
    volatile uint32_t cur_time = msTicks;
    while((msTicks - cur_time) < 1000);
    // *(volatile uint32_t *)(GPIOA_BSRR) = 1 << (6);
    GPIOA->ODR = 1 << 7;
    cur_time = msTicks;
    while((msTicks - cur_time) < 1000);
  }

  /*
  *(volatile uint32_t *)RCC_AHB1ENR |= 1<<0;

  // initialize gpio
  *(volatile uint32_t *)GPIOA_MODER |= 1 << 12;
  *(volatile uint32_t *)(GPIOA + 0x08) = 0 << 12;
  *(volatile uint32_t *)(GPIOA + 0x04) = 0 << 6;
  *(volatile uint32_t *)(GPIOA + 0x0C) = 0 << 12;
  // write a 0
  while(1){
      *(volatile uint32_t *)(GPIOA + 0x18) = 1 << 6;
      *(volatile uint32_t *)(GPIOA + 0x18) = 1<<(16+6);

  }
  */
  while(1);
  return 0;
}
