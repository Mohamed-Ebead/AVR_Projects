/*
 * STM32F407xx.h
 *
 *  Created on: Mar 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef DRIVERS_INC_STM32F407XX_H_
#define DRIVERS_INC_STM32F407XX_H_

#include "STD_Types.h"


/*
 *  base addresses of flash and SRAM memories
 */

#define FLASH_BASEADDR  0x0800 0000U
#define SRAM1_BASEADDR  0x2000 0000U
#define SRAM            SRAM1_BASEADDR        // main SRAM
#define SRAM2_BASEADDR  0x2001 C000U
#define ROM_BASEADDR    0x1FFF 0000U   // system memory


/*
 *  AHBx and APB x  peripheral base addresses
 */

#define PERIPHERAL_BASEADDR    0x4000 0000U
#define APB1PERIPH_BASEADDR    PERIPHERAL_BASEADDR
#define APB2PERIPH_BASEADDR    0x4001 0000U
#define AHB1PERIPH_BASEADDR    0x4002 0000U
#define AHB2PERIPH_BASEADDR    0x5000 0000U

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define GPIOA_BASEADDR      (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR      (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR      (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR      (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR      (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR      (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR      (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR      (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR      (AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR        (AHB1PERIPH_BASEADDR + 0x3800)


/*
 *  Base addresses of peripherals which are hanging on APB1 bus
 */

#define I2C1_BASEADDR      (APB1PERIPH_BASEADDR + 0X5400)
#define I2C2_BASEADDR      (APB1PERIPH_BASEADDR + 0X5800)
#define I2C2_BASEADDR      (APB1PERIPH_BASEADDR + 0X5C00)

#define SPI2_BASEADDR      (APB1PERIPH_BASEADDR + 0X3800)
#define SPI3_BASEADDR      (APB1PERIPH_BASEADDR + 0X3C00)

#define UART2_BASEADDR     (APB1PERIPH_BASEADDR + 0X4400)
#define UART3_BASEADDR     (APB1PERIPH_BASEADDR + 0X4800)
#define UART4_BASEADDR     (APB1PERIPH_BASEADDR + 0X4C00)
#define UART5_BASEADDR     (APB1PERIPH_BASEADDR + 0X5000)


/*
 *   Base addresses of peripherals which are hanging on APB2 bus
 */

#define EXTI_BASEADDR         (APB2PERIPH_BASEADDR + 0X3C00)
#define SPI1_BASEADDR         (APB2PERIPH_BASEADDR + 0X3000)
#define SYSCFG_BASEADDR       (APB2PERIPH_BASEADDR + 0X3800)
#define USART1_BASEADDR       (APB2PERIPH_BASEADDR + 0X1000)
#define USART6_BASEADDR       (APB2PERIPH_BASEADDR + 0X3C00)
#define EXTI_BASEADDR         (APB2PERIPH_BASEADDR + 0X3C00)
#define EXTI_BASEADDR         (APB2PERIPH_BASEADDR + 0X3C00)


/** ********** Peripheral register definition structures ********** **/

typedef struct
{
	volatile uint32_t  MODER       ;
	volatile uint32_t  OTYPER      ;
	volatile uint32_t  OSPEEDER    ;
	volatile uint32_t  PUPDR       ;
	volatile uint32_t  IDR         ;
	volatile uint32_t  ODR         ;
	volatile uint32_t  BSRR        ;
	volatile uint32_t  LCKR        ;
	volatile uint32_t  AFR[2]      ;


}GPIO_RegDef_t ;




/*
 *    peripheral register definition structure for RCC
 */

typedef struct
{
	volatile uint32_t  CR           ;
	volatile uint32_t  PLLCFGR      ;
	volatile uint32_t  CIR          ;
	volatile uint32_t  AHB1RSTR     ;
	volatile uint32_t  AHB2RSTR     ;
	volatile uint32_t  AHB3RSTR     ;
	         uint32_t  RESERVED0    ;
	volatile uint32_t  APB1RSTR     ;
    volatile uint32_t  APB2RSTR     ;
	         uint32_t  RESERVED1    ;
			 uint32_t  RESERVED2    ;
    volatile uint32_t  AHB1ENR      ;
	volatile uint32_t  AHB2ENR      ;
	volatile uint32_t  AHB3ENR      ;
	         uint32_t  RESERVED3    ;
	 volatile uint32_t  APB1ENR     ;
	 volatile uint32_t  APB2ENR     ;
	          uint32_t  RESERVED4   ;
			  uint32_t  RESERVED5   ;
	 volatile uint32_t  AHB1LPENR   ;
	 volatile uint32_t  AHB2LPENR   ;
	 volatile uint32_t  AHB3LPENR   ;
	 	 	  uint32_t  RESERVED5   ;
	 volatile uint32_t  APB1LPENR   ;
	 volatile uint32_t  APB2LPENR   ;
	          uint32_t  RESERVED6   ;
			  uint32_t  RESERVED7   ;
	 volatile uint32_t  SSCGR       ;
	 volatile uint32_t  CSR         ;
	 volatile uint32_t  PLLI2SCFGR  ;
	 volatile uint32_t  PLLSAICFGR  ;
	 volatile uint32_t  CKGATENR    ;
	 volatile uint32_t  DCKCFGR2    ;


}RCC_RegDef_t ;




/*
 *   peripheral definitions (peripheral base address type casted to xxx_Reg_Def_t)
 */

#define GPIOA      ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB      ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC      ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD      ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE      ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF      ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG      ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH      ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI      ((GPIO_RegDef_t*)GPIOI_BASEADDR)


#define RCC        ((GPIO_RegDef_t*)RCC_BASEADDR)


/*
 *   Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 7) )
#define GPIOI_PCLK_EN()         ( RCC->AHB1ENR |= (1 << 8) )




/*
 *   Clock Enable Macros for I2C peripherals
 */

#define I2C1_PCLK_EN()         ( RCC->APB1ENR |= (1 << 21) )
#define I2C2_PCLK_EN()         ( RCC->APB1ENR |= (1 << 22) )
#define I2C3_PCLK_EN()         ( RCC->APB1ENR |= (1 << 23) )






/*
 *   Clock Enable Macros for SPI peripherals
 */

#define SPI1_PCLK_EN()         ( RCC->APB1ENR |= (1 << 12) )
#define SPI2_PCLK_EN()         ( RCC->APB1ENR |= (1 << 14) )
#define SPI3_PCLK_EN()         ( RCC->APB1ENR |= (1 << 15) )
#define SPI4_PCLK_EN()         ( RCC->APB1ENR |= (1 << 13) )





/*
 *   Clock Enable Macros for USART peripherals
 */

#define USART1_PCLK_EN()         ( RCC->APB2ENR |= (1 <<  4) )
#define USART2_PCLK_EN()         ( RCC->APB2ENR |= (1 << 17) )
#define USART3_PCLK_EN()         ( RCC->APB2ENR |= (1 << 18) )
#define USART4_PCLK_EN()         ( RCC->APB2ENR |= (1 << 19) )
#define USART5_PCLK_EN()         ( RCC->APB2ENR |= (1 << 20) )
#define USART6_PCLK_EN()         ( RCC->APB2ENR |= (1 << 5 ) )




/*
 *   Clock Enable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_EN()         ( RCC->APB2ENR |= (1 << 14 ) )


/*
 *   Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DIS()
#define GPIOB_PCLK_DIS()
#define GPIOC_PCLK_DIS()
#define GPIOD_PCLK_DIS()
#define GPIOE_PCLK_DIS()
#define GPIOF_PCLK_DIS()
#define GPIOG_PCLK_DIS()
#define GPIOH_PCLK_DIS()
#define GPIOI_PCLK_DIS()



/*
 * macros to reser GPIOx Peripherals
 */

#define GPIOA_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<0) ; RCC->AHB1RSTR &=~(1<<0) ;}  while (0)
#define GPIOB_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<1) ; RCC->AHB1RSTR &=~(1<<1) ;}  while (0)
#define GPIOC_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<2) ; RCC->AHB1RSTR &=~(1<<2) ;}  while (0)
#define GPIOD_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<3) ; RCC->AHB1RSTR &=~(1<<3) ;}  while (0)
#define GPIOE_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<4) ; RCC->AHB1RSTR &=~(1<<4) ;}  while (0)
#define GPIOF_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<5) ; RCC->AHB1RSTR &=~(1<<5) ;}  while (0)
#define GPIOG_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<6) ; RCC->AHB1RSTR &=~(1<<6) ;}  while (0)
#define GPIOH_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<7) ; RCC->AHB1RSTR &=~(1<<7) ;}  while (0)
#define GPIOI_PCLK_RESET()       do {RCC->AHB1RSTR |= (1 <<8) ; RCC->AHB1RSTR &=~(1<<8) ;}  while (0)



/*
 *   Some Generic MACROS
 */
#define ENABLE           1
#define DISABLE          0
#define SET              ENABLE
#define RESET            DISABLE
#define GPIO_PIN_SET     SET
#define GPIO_PIN_RESET   RESET








#endif /* DRIVERS_INC_STM32F407XX_H_ */
