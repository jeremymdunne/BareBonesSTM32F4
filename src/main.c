

#include "stm32f40x_system.h"
#include "gpio.h"



int main(void){
  stm32f4SystemInit();

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
  // enable_all_gpio_peripheral_clocks();
  // RCC->AHB1ENR |= 1<<0;
  // RCC->AHB1ENR |= 1<<4;

  // setup PA6 as an output
  gpioSetPinMode(GPIOA, 6, GPIO_MODE_OUTPUT);
  // setup PA7 as an output
  gpioSetPinMode(GPIOA, 7, GPIO_MODE_OUTPUT);
  // setup PE4 as an input
  gpioSetPinMode(GPIOE, 4, GPIO_MODE_INPUT);
  // PU mode
  gpioSetPUPD(GPIOE, 4, GPIO_PUPD_PU);



  // setupTimer();


  while(1){
    if(gpioReadPin(GPIOE, 4)){
    // if(GPIOE->IDR & (1<<4)){
      // button pressed, turn on PA7
      // GPIOA->ODR = 1<<7;
      gpioWritePin(GPIOA, 7, GPIO_LOW);
    }
    else{
      gpioWritePin(GPIOA, 7, GPIO_HIGH);
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
