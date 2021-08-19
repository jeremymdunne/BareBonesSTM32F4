#include "gpio.h"


void gpioWritePin(GPIO_TypeDef* gpio, uint8_t pin, uint8_t state){
  // set the bit
  gpio->ODR = (gpio->ODR & ~(1UL << pin)) | (state << pin);
}

int gpioGetOutputState(GPIO_TypeDef* gpio, uint8_t pin){
  return (gpio->ODR >> pin) & 1U;
}

int gpioReadPin(GPIO_TypeDef* gpio, uint8_t pin){
  // TODO check input state first?
  return (gpio->IDR >> pin) & 1U;
}

void gpioSetPinMode(GPIO_TypeDef* gpio, uint8_t pin, _gpio_mode_t mode){
  // double bit write
  gpio->MODER = (gpio->MODER & ~(3UL << 2*pin)) | (mode << 2*pin);
}

void gpioSetPUPD(GPIO_TypeDef* gpio, uint8_t pin, _gpio_pull_up_down_t pupd_mode){
  // double bit write
  gpio->PUPDR = (gpio->PUPDR & ~(3UL << 2*pin)) | (pupd_mode << 2*pin);
}

void gpioSetSpeed(GPIO_TypeDef* gpio, uint8_t pin, _gpio_output_speed_t speed){
  // double bit write
  gpio->OSPEEDR = (gpio->OSPEEDR & ~(3UL << 2*pin)) | (speed << 2*pin);
}

void gpioSetOutputType(GPIO_TypeDef* gpio, uint8_t pin, _gpio_output_type_t type){
  // single bit write
  gpio->OTYPER = (gpio->OTYPER & ~(1UL << pin)) | (type << pin);
}
