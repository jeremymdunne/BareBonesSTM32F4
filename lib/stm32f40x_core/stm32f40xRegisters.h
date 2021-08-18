/**

Definitions of all registers used

*/


#ifndef _STM32F4_REGISTERS_H_
#define _STM32F4_REGISTERS_H_


// memory mapped sections
#define TIM2_BASE               0x40000000UL
#define TIM3_BASE               0x40000400UL
#define TIM4_BASE               0x40000800UL
#define TIM5_BASE               0x40000C00UL
#define TIM6_BASE               0x40001000UL
#define TIM7_BASE               0x40001400UL
#define TIM12_BASE              0x40001800UL
#define TIM13_BASE              0x40001C00UL
#define TIM14_BASE              0x40002000UL
#define RTC_BKP_BASE            0x40002800UL
#define WWDG_BASE               0x40002C00UL
#define IWDG_BASE               0x40003000UL
#define I2S2EXT_BASE            0x40003400UL
#define SPI2_BASE               0x40003800UL
#define SPI3_BASE               0x40003C00UL
#define I2S3EXT_BASE            0x40004000UL
#define USART2_BASE             0x40004400UL
#define USART3_BASE             0x40004800UL
#define UART4_BASE              0x40004C00UL
#define UART5_BASE              0x40005000UL
#define I2C1_BASE               0x40005400UL
#define I2C2_BASE               0x40005800UL
#define I2C3_BASE               0x40005C00UL
#define CAN1_BASE               0x40006400UL
#define CAN2_BASE               0x40006800UL
#define PWR_BASE                0x40007000UL
#define DAC_BASE                0x40007400UL
#define UART7_BASE              0x40007800UL
#define UART8_BASE              0x40007C00UL
#define TIM1_BASE               0x40010000UL
#define TIM8_BASE               0x40010400UL
#define USART1_BASE             0x40011000UL
#define USART6_BASE             0x40011400UL
#define ADC1_ADC2_ADC3_BASE     0x40012000UL
#define SDIO_BASE               0x40012C00UL
#define SPI1_BASE               0x40013000UL
#define SPI4_BASE               0x40013400UL
#define SYSCFG_BASE             0x40013800UL
#define EXTI_BASE               0x40013C00UL
#define TIM9_BASE               0x40014000UL
#define TIM10_BASE              0x40014400UL
#define TIM11_BASE              0x40014800UL
#define SPI5_BASE               0x40015000UL
#define SPI6_BASE               0x40015400UL
#define SAI1_BASE               0x40015800UL
#define LCD_TFT_BASE            0x40016800UL
#define GPIOA_BASE              0x40020000UL
#define GPIOB_BASE              0x40020400UL
#define GPIOC_BASE              0x40020800UL
#define GPIOD_BASE              0x40020C00UL
#define GPIOE_BASE              0x40021000UL
#define GPIOF_BASE              0x40021400UL
#define GPIOG_BASE              0x40021800UL
#define GPIOH_BASE              0x40021C00UL
#define GPIOI_BASE              0x40022000UL
#define GPIOJ_BASE              0x40022400UL
#define GPIOK_BASE              0x40022800UL
#define CRC_BASE                0x40023000UL
#define RCC_BASE                0x40023800UL
#define FLASH_BASE              0x40023C00UL
#define BKPSRAM_BASE            0x40024000UL
#define DMA1_BASE               0x40026000UL
#define DMA2_BASE               0x40026400UL
#define ETHERNET_MAC_BASE       0x40028000UL
#define DMA2D_BASE              0x4002B000UL
#define USB_OTG_HS_BASE         0x40040000UL
#define USB_OTG_FS_BASE         0x50000000UL
#define DCMI_BASE               0x50050000UL
#define CRYP_BASE               0x50060000UL
#define HASH_BASE               0x50064000UL
#define RNG_BASE                0x50060800UL
#define FSMC_BASE               0xA0000000UL

#define STK_BASE               0xE000E010UL    // SysTick
#define NVIC_BASE              0xE000E010UL

// FLASH_BASE Interface Registers
#define FLASH_ACR         (FLASH_BASE + 0x00)
#define FLASH_KEYR        (FLASH_BASE + 0x04)
#define FLASH_OPT_KEYR    (FLASH_BASE + 0x08)
#define FLASH_SR          (FLASH_BASE + 0x0C)
#define FLASH_CR          (FLASH_BASE + 0x10)
#define FLASH_OPTCR       (FLASH_BASE + 0x14)



// CRC_BASE Registers
#define CRC_DR            (CRC_BASE + 0x00)
#define CRC_IDR           (CRC_BASE + 0x04)
#define CRC_CR            (CRC_BASE + 0x08)


// Power (PWR) Registers
#define PWR_CR            (PWR_BASE + 0x00)
#define PWR_CSR           (PWR_BASE + 0x04)


// RCC_BASE Registers
#define RCC_CR            (RCC_BASE + 0x00)
#define RCC_PLLCFGR       (RCC_BASE + 0x04)
#define RCC_CFGR          (RCC_BASE + 0x08)
#define RCC_CIR           (RCC_BASE + 0x0C)
#define RCC_AHB1RSTR      (RCC_BASE + 0x10)
#define RCC_AHB2RSTR      (RCC_BASE + 0x14)
#define RCC_AHB3RSTR      (RCC_BASE + 0x18)
#define RCC_APB1RSTR      (RCC_BASE + 0x20)
#define RCC_APB2RSTR      (RCC_BASE + 0x24)
#define RCC_AHB1ENR       (RCC_BASE + 0x30)
#define RCC_AHB2ENR       (RCC_BASE + 0x34)
#define RCC_AHB3ENR       (RCC_BASE + 0x38)
#define RCC_APB1ENR       (RCC_BASE + 0x40)
#define RCC_APB2ENR       (RCC_BASE + 0x44)
#define RCC_AHB1LPENR     (RCC_BASE + 0x50)
#define RCC_AHB2LPENR     (RCC_BASE + 0x54)
#define RCC_AHB3LPENR     (RCC_BASE + 0x58)
#define RCC_APB1LPENR     (RCC_BASE + 0x60)
#define RCC_APB2LPENR     (RCC_BASE + 0x64)
#define RCC_BDCR          (RCC_BASE + 0x70)
#define RCC_CSR           (RCC_BASE + 0x74)
#define RCC_SSCGR         (RCC_BASE + 0x80)
#define RCC_PLLI2SCFGR    (RCC_BASE + 0x84)
#define RCC_PLLSAICFGR    (RCC_BASE + 0x88)
#define RCC_DCKCFGR       (RCC_BASE + 0x8C)


// GPIO Registers
//GPIOA
#define GPIOA_MODER       (GPIOA_BASE + 0x00)
#define GPIOA_OTYPER      (GPIOA_BASE + 0x04)
#define GPIOA_OSPEEDR     (GPIOA_BASE + 0x08)
#define GPIOA_PUPDR       (GPIOA_BASE + 0x0C)
#define GPIOA_IDR         (GPIOA_BASE + 0x10)
#define GPIOA_ODR         (GPIOA_BASE + 0x14)
#define GPIOA_BSRR        (GPIOA_BASE + 0x18)
#define GPIOA_LCKR        (GPIOA_BASE + 0x1C)
#define GPIOA_AFRL        (GPIOA_BASE + 0x20)
#define GPIOA_AFRH        (GPIOA_BASE + 0x24)
//GPIOB
#define GPIOB_MODER       (GPIOB_BASE + 0x00)
#define GPIOB_OTYPER      (GPIOB_BASE + 0x04)
#define GPIOB_OSPEEDR     (GPIOB_BASE + 0x08)
#define GPIOB_PUPDR       (GPIOB_BASE + 0x0C)
#define GPIOB_IDR         (GPIOB_BASE + 0x10)
#define GPIOB_ODR         (GPIOB_BASE + 0x14)
#define GPIOB_BSRR        (GPIOB_BASE + 0x18)
#define GPIOB_LCKR        (GPIOB_BASE + 0x1C)
#define GPIOB_AFRL        (GPIOB_BASE + 0x20)
#define GPIOB_AFRH        (GPIOB_BASE + 0x24)
//GPIOC
#define GPIOC_MODER       (GPIOC_BASE + 0x00)
#define GPIOC_OTYPER      (GPIOC_BASE + 0x04)
#define GPIOC_OSPEEDR     (GPIOC_BASE + 0x08)
#define GPIOC_PUPDR       (GPIOC_BASE + 0x0C)
#define GPIOC_IDR         (GPIOC_BASE + 0x10)
#define GPIOC_ODR         (GPIOC_BASE + 0x14)
#define GPIOC_BSRR        (GPIOC_BASE + 0x18)
#define GPIOC_LCKR        (GPIOC_BASE + 0x1C)
#define GPIOC_AFRL        (GPIOC_BASE + 0x20)
#define GPIOC_AFRH        (GPIOC_BASE + 0x24)
//GPIOD
#define GPIOD_MODER       (GPIOD_BASE + 0x00)
#define GPIOD_OTYPER      (GPIOD_BASE + 0x04)
#define GPIOD_OSPEEDR     (GPIOD_BASE + 0x08)
#define GPIOD_PUPDR       (GPIOD_BASE + 0x0C)
#define GPIOD_IDR         (GPIOD_BASE + 0x10)
#define GPIOD_ODR         (GPIOD_BASE + 0x14)
#define GPIOD_BSRR        (GPIOD_BASE + 0x18)
#define GPIOD_LCKR        (GPIOD_BASE + 0x1C)
#define GPIOD_AFRL        (GPIOD_BASE + 0x20)
#define GPIOD_AFRH        (GPIOD_BASE + 0x24)
//GPIOE
#define GPIOE_MODER       (GPIOE_BASE + 0x00)
#define GPIOE_OTYPER      (GPIOE_BASE + 0x04)
#define GPIOE_OSPEEDR     (GPIOE_BASE + 0x08)
#define GPIOE_PUPDR       (GPIOE_BASE + 0x0C)
#define GPIOE_IDR         (GPIOE_BASE + 0x10)
#define GPIOE_ODR         (GPIOE_BASE + 0x14)
#define GPIOE_BSRR        (GPIOE_BASE + 0x18)
#define GPIOE_LCKR        (GPIOE_BASE + 0x1C)
#define GPIOE_AFRL        (GPIOE_BASE + 0x20)
#define GPIOE_AFRH        (GPIOE_BASE + 0x24)
//GPIOF
#define GPIOF_MODER       (GPIOF_BASE + 0x00)
#define GPIOF_OTYPER      (GPIOF_BASE + 0x04)
#define GPIOF_OSPEEDR     (GPIOF_BASE + 0x08)
#define GPIOF_PUPDR       (GPIOF_BASE + 0x0C)
#define GPIOF_IDR         (GPIOF_BASE + 0x10)
#define GPIOF_ODR         (GPIOF_BASE + 0x14)
#define GPIOF_BSRR        (GPIOF_BASE + 0x18)
#define GPIOF_LCKR        (GPIOF_BASE + 0x1C)
#define GPIOF_AFRL        (GPIOF_BASE + 0x20)
#define GPIOF_AFRH        (GPIOF_BASE + 0x24)
//GPIOG
#define GPIOG_MODER       (GPIOG_BASE + 0x00)
#define GPIOG_OTYPER      (GPIOG_BASE + 0x04)
#define GPIOG_OSPEEDR     (GPIOG_BASE + 0x08)
#define GPIOG_PUPDR       (GPIOG_BASE + 0x0C)
#define GPIOG_IDR         (GPIOG_BASE + 0x10)
#define GPIOG_ODR         (GPIOG_BASE + 0x14)
#define GPIOG_BSRR        (GPIOG_BASE + 0x18)
#define GPIOG_LCKR        (GPIOG_BASE + 0x1C)
#define GPIOG_AFRL        (GPIOG_BASE + 0x20)
#define GPIOG_AFRH        (GPIOG_BASE + 0x24)
//GPIOH
#define GPIOH_MODER       (GPIOH_BASE + 0x00)
#define GPIOH_OTYPER      (GPIOH_BASE + 0x04)
#define GPIOH_OSPEEDR     (GPIOH_BASE + 0x08)
#define GPIOH_PUPDR       (GPIOH_BASE + 0x0C)
#define GPIOH_IDR         (GPIOH_BASE + 0x10)
#define GPIOH_ODR         (GPIOH_BASE + 0x14)
#define GPIOH_BSRR        (GPIOH_BASE + 0x18)
#define GPIOH_LCKR        (GPIOH_BASE + 0x1C)
#define GPIOH_AFRL        (GPIOH_BASE + 0x20)
#define GPIOH_AFRH        (GPIOH_BASE + 0x24)
//GPIOI
#define GPIOI_MODER       (GPIOI_BASE + 0x00)
#define GPIOI_OTYPER      (GPIOI_BASE + 0x04)
#define GPIOI_OSPEEDR     (GPIOI_BASE + 0x08)
#define GPIOI_PUPDR       (GPIOI_BASE + 0x0C)
#define GPIOI_IDR         (GPIOI_BASE + 0x10)
#define GPIOI_ODR         (GPIOI_BASE + 0x14)
#define GPIOI_BSRR        (GPIOI_BASE + 0x18)
#define GPIOI_LCKR        (GPIOI_BASE + 0x1C)
#define GPIOI_AFRL        (GPIOI_BASE + 0x20)
#define GPIOI_AFRH        (GPIOI_BASE + 0x24)
//GPIOJ
#define GPIOJ_MODER       (GPIOJ_BASE + 0x00)
#define GPIOJ_OTYPER      (GPIOJ_BASE + 0x04)
#define GPIOJ_OSPEEDR     (GPIOJ_BASE + 0x08)
#define GPIOJ_PUPDR       (GPIOJ_BASE + 0x0C)
#define GPIOJ_IDR         (GPIOJ_BASE + 0x10)
#define GPIOJ_ODR         (GPIOJ_BASE + 0x14)
#define GPIOJ_BSRR        (GPIOJ_BASE + 0x18)
#define GPIOJ_LCKR        (GPIOJ_BASE + 0x1C)
#define GPIOJ_AFRL        (GPIOJ_BASE + 0x20)
#define GPIOJ_AFRH        (GPIOJ_BASE + 0x24)


// TIM2
#define TIM2_CR1          (TIM2_BASE + 0x00)
#define TIM2_CR2          (TIM2_BASE + 0x04)
#define TIM2_SMCR         (TIM2_BASE + 0x08)
#define TIM2_DIER         (TIM2_BASE + 0x0C)
#define TIM2_SR           (TIM2_BASE + 0x10)
#define TIM2_EGR          (TIM2_BASE + 0x14)
#define TIM2_CCMR1        (TIM2_BASE + 0x18)
#define TIM2_CCMR2        (TIM2_BASE + 0x1C)
#define TIM2_CCER         (TIM2_BASE + 0x20)
#define TIM2_CNT          (TIM2_BASE + 0x24)
#define TIM2_PSC          (TIM2_BASE + 0x28)
#define TIM2_ARR          (TIM2_BASE + 0x2C)
#define TIM2_CCR1         (TIM2_BASE + 0x34)
#define TIM2_CCR2         (TIM2_BASE + 0x38)
#define TIM2_CCR3         (TIM2_BASE + 0x3C)
#define TIM2_CCR4         (TIM2_BASE + 0x40)
#define TIM2_DCR          (TIM2_BASE + 0x48)
#define TIM2_DMAR         (TIM2_BASE + 0x4C)
#define TIM2_TIM2_OR      (TIM2_BASE + 0x50)



// SysTick
#define STK_CTRL          (STK_BASE + 0x00)
#define STK_LOAD          (STK_BASE + 0x04)
#define STK_VAL           (STK_BASE + 0x08)
#define STK_CALIB         (STK_BASE + 0x0C)


// NVIC
#define NVIC_ISER0        (NVIC_BASE + 0x100)
#define NVIC_ISER1        (NVIC_BASE + 0x104)
// TODO Fill out ISER2-7
#define NVIC_ICER0        (NVIC_BASE + 0x180)
#define NVIC_ICER1        (NVIC_BASE + 0x184)
// TODO Fill out ICER2-7
#define NVIC_ISPR0        (NVIC_BASE + 0x200)
#define NVIC_ISPR1        (NVIC_BASE + 0x204)
// TODO Fill out ISPR2-7
#define NVIC_ICPR0        (NVIC_BASE + 0x280)
#define NVIC_ICPR1        (NVIC_BASE + 0x284)
// TODO Fill out ICPR2-7
#define NVIC_IABR0        (NVIC_BASE + 0x300)
#define NVIC_IABR1        (NVIC_BASE + 0x304)
// TODO Fill out IABR2-7
#define NVIC_IPR0         (NVIC_BASE + 0x400)
#define NVIC_IPR1         (NVIC_BASE + 0x404)
// TODO Fill out IABR2-59
#define NVIC_STIR         (NVIC_BASE + 0xE00)


#endif
