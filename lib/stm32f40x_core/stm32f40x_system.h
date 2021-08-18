/**
 * @file stm32f40x_system.h.
 * @author Jeremy Dunne.
 * @date August 2021.
 * @brief Collection of useful system functions and definitions that are commonly called.
 */

#ifndef _STM32F40X_SYSTEM_H_
#define _STM32F40X_SYSTEM_H_

#include "stm32f40x.h"
#include "stm32f40xRegisters.h"

/**
 * @breif Struct describing the clock settings to be used by the device.
 * @details Stores clock settings (prescalers, etc.) used to set the system clocks.
 */
typedef struct{
  uint8_t AHB_Prescaler;
  uint8_t APB1_Prescaler;
  uint8_t APB2_Prescaler;
  uint8_t PLLM;
  uint8_t PLLN;
  uint8_t PLLP;
} _stm32f4_clock_settings_t;

_stm32f4_clock_settings_t *_system_clock_settings;      /**< system clock settings to be used. */

/**
 * @breif Set the hse clock using the system settings.
 * @details Uses the _system_clock_settings to set the hse clock.
 */
void stm32f4_hse_clock_startup();

/**
 * @breif Initalize the microcontroller for general use.
 * @details Uses the HSE clock, allows peripherals, etc.
 */
void stm32f4_system_init();







#endif
