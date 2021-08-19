/**
 * @file gpio.h.
 * @author Jeremy Dunne.
 * @date August 2021.
 * @brief Header file for GPIO functionality.
 */

#ifndef _GPIO_H_
#define _GPIO_H_

#include "stm32f40x.h"
#include "stm32f40xRegisters.h"

#define GPIO_HIGH 1
#define GPIO_LOW 0


typedef enum{
  GPIO_MODE_INPUT = 0,
  GPIO_MODE_OUTPUT = 1,
  GPIO_MODE_ALTERNATE_FUNCTION = 2,
  GPIO_MODE_ANALOG = 3
} _gpio_mode_t;

typedef enum{
  GPIO_OUTPUT_PP = 0,
  GPIO_OUTPUT_OD = 1
} _gpio_output_type_t;

typedef enum{
  GPIO_OUTPUT_SPEED_LOW = 0,
  GPIO_OUTPUT_SPEED_MED = 1,
  GPIO_OUTPUT_SPEED_HIGH = 2,
  GPIO_OUTPUT_SPEED_VERY_HIGH = 3
}  _gpio_output_speed_t;

typedef enum{
  GPIO_PUPD_NONE = 0,
  GPIO_PUPD_PU = 1,
  GPIO_PUPD_PD = 2
} _gpio_pull_up_down_t;

typedef struct{
  __reg MODER;
  __reg OTYPER;
  __reg OSPEEDR;
  __reg PUPDR;
  __reg IDR;
  __reg ODR;
  __reg BSRR;
  __reg AFRL;
  __reg AFRH;
} GPIO_TypeDef;

#define GPIOA       ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC       ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD       ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE       ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF       ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG       ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH       ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI       ((GPIO_TypeDef *) GPIOI_BASE)
#define GPIOJ       ((GPIO_TypeDef *) GPIOJ_BASE)
#define GPIOK       ((GPIO_TypeDef *) GPIOK_BASE)


/**
 * @breif Write to a (digital) GPIO Pin.
 * @details Write high or low to a gpio pin, regaurdless of state.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to write to.
 * @param state uint8_t GPIO_HIGH or GPIO_LOW (1 or 0).
 */
void gpioWritePin(GPIO_TypeDef* gpio, uint8_t pin, uint8_t state);

/**
 * @breif Get the output state (GPIO_HIGH or GPIO_LOW) for a gpio pin.
 * @details Reads the ODR register to determine the write state of the pin.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to read the write state on.
 */
int gpioGetOutputState(GPIO_TypeDef* gpio, uint8_t pin);

/**
 * @breif Read a GPIO Pin.
 * @details Get the Input Data Register, regaurdless of pin state.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to read.
 * @return int, 1 for high, 0 for low.
 */
int gpioReadPin(GPIO_TypeDef* gpio, uint8_t pin);

/**
 * @breif Set the pin mode of a GPIO pin.
 * @details Set the MODER register of a pin.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to set the mode on.
 * @param mode _gpio_mode_t mode to set the pin to.
 */
void gpioSetPinMode(GPIO_TypeDef* gpio, uint8_t pin, _gpio_mode_t mode);

/**
 * @breif Set the Pull Up Pull Down (PUPD) pin state.
 * @details Sets the PUPDR register to the desired mode.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to set the mode on.
 * @param pupd_mode _gpio_pull_up_down_t mode to set.
 */
void gpioSetPUPD(GPIO_TypeDef* gpio, uint8_t pin, _gpio_pull_up_down_t pupd_mode);

/**
 * @breif Set the output speed of a GPIO pin.
 * @details Sets the OSPEEDR register to the desired value.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to set the speed on.
 * @param speed _gpio_output_speed_t speed to set.
 */
void gpioSetSpeed(GPIO_TypeDef* gpio, uint8_t pin, _gpio_output_speed_t speed);

/**
 * @breif Set the output type (Open Pull, Open Drain) for a GPIO pin.
 * @details Sets the OTYPER register to the desired value.
 * @param gpio GPIO_TypeDef* pointer to the GPIO registers.
 * @param pin uint8_t pin to set the mode on.
 * @param type _gpio_output_type_t type to set.
 */
void gpioSetOutputType(GPIO_TypeDef* gpio, uint8_t pin, _gpio_output_type_t type);

//TODO implement
void gpioSetAlternateFunction(GPIO_TypeDef* gpio, uint8_t pin); // TODO

#endif
