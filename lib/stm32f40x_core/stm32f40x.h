#ifndef _STM32F40X_
#define _STM32F40X_

#include "stm32f40xRegisters.h"


// #define BIT_SET(a,b,n) ((a) |= (1ULL<<(b)))

typedef unsigned int uint32_t;
typedef unsigned short int uint16_t;
typedef volatile uint32_t vuint32_t;
typedef volatile uint16_t vuint16_t;
typedef volatile unsigned int __reg;
typedef unsigned char uint8_t;

typedef struct{
  __reg ACR;
  __reg KEYR;
  __reg OPT_KEYR;
  __reg SR;
  __reg CR;
  __reg OPTCR;
} FLASH_TypeDef;

#define FLASH       ((FLASH_TypeDef *) FLASH_BASE)

typedef struct{
  __reg CR;
  __reg CSR;
} PWR_TypeDef;

#define PWR         ((PWR_TypeDef *) PWR_BASE)

typedef struct{
  __reg CR;
  __reg PLLCFGR;
  __reg CFGR;
  __reg CIR;
  __reg AHB1RSTR;
  __reg AHB2RSTR;
  __reg AHB3RSTR;
  uint32_t RESERVED0;
  __reg APB1RSTR;
  __reg APB2RSTR;
  uint32_t RESERVED1;
  uint32_t RESERVED2;
  __reg AHB1ENR;
  __reg AHB2ENR;
  __reg AHB3ENR;
  uint32_t RESERVED3;
  __reg APB1ENR;
  __reg APB2ENR;
  uint32_t RESERVED4;
  uint32_t RESERVED5;
  __reg AHB1LPENR;
  __reg AHB2LPENR;
  __reg AHB3LPENR;
  uint32_t RESERVED6;
  __reg APB1LPENR;
  __reg APB2LPENR;
  uint32_t RESERVED7;
  uint32_t RESERVED8;
  __reg BDCR;
  __reg CSR;
  uint32_t RESERVED9;
  uint32_t RESERVED10;
  __reg SSCGR;
  __reg PLLI2SCFGR;
} RCC_TypeDef;

#define RCC         ((RCC_TypeDef *) RCC_BASE)

typedef struct{
  __reg MEMRMP;
  __reg PMC;
  __reg EXTICR1;
  __reg EXTICR2;
  __reg EXTICR3;
  __reg EXTICR4;
  __reg CMPCR;
} SYSCFG_TypeDef;

#define SYSCFG      ((SYSCFG_TypeDef *) SYSCFG_BASE)

typedef struct{
  __reg CTRL;
  __reg LOAD;
  __reg VAL;
  __reg CALIB;
} STK_TypeDef;

#define STK         ((STK_TypeDef *) STK_BASE)

typedef struct{
  __reg CR1;
  __reg CR2;
  __reg SMCR;
  __reg DIER;
  __reg SR;
  __reg EGR;
  __reg CCMR1;
  __reg CCMR2;
  __reg CCER;
  __reg CNT;
  __reg PSC;
  __reg ARR;
  uint32_t RESERVED0;
  __reg CCR1;
  __reg CCR2;
  __reg CCR3;
  __reg CCR4;
  uint32_t RESERVED1;
  __reg DCR;
  __reg DMAR;
  __reg OR;
} TIM2_5_TypeDef;

#define TIM2      ((TIM2_5_TypeDef *)TIM2_BASE)
#define TIM3      ((TIM2_5_TypeDef *)TIM3_BASE)
#define TIM4      ((TIM2_5_TypeDef *)TIM4_BASE)
#define TIM5      ((TIM2_5_TypeDef *)TIM5_BASE)


typedef struct{
  __reg ISER[8];
  uint32_t RESERVED0[24];
  __reg ICER[8];
  uint32_t RSERVED1[24];
  __reg ISPR[8];
  uint32_t RESERVED2[24];
  __reg ICPR[8];
  uint32_t RESERVED3[24];
  __reg IABR[8];
  uint32_t RESERVED4[56];
  volatile uint8_t IPR[240];
  uint32_t RESERVED5[644];
  __reg STIR;
} NVIC_TypeDef;

#define NVIC        ((NVIC_TypeDef *) NVIC_BASE)


#endif
