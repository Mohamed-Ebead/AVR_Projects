/*
 * STM32F4xx_GPIO_h.h
 *
 *  Created on: Mar 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef DRIVERS_INC_STM32F407XX_GPIO_H_H_
#define DRIVERS_INC_STM32F407XX_GPIO_H_H_

#include <STM32F407xx.h>
#include "STD_TYPES.h"


/*
 *   Configuration structure for a GPIO PIN
 */

typedef struct
{
	uint8_t GPIO_PinNumber        ;
	uint8_t GPIO_Pin_Mode         ;         /* !< POSSIBLE VALUES FROM @GPIO_PIN_MODES  */
	uint8_t GPIO_PinSpeed         ;
	uint8_t GPIO_PinPuPdControl   ;
	uint8_t GPIO_PinOPType        ;
	uint8_t GPIO_PinAltFunMode    ;


}GPIO_PinConfig_t;

/*
 *   Handle structure for a GPIO PIN
 */

typedef struct
{

	GPIO_RegDef_t *pGPIOx ;           //hold the base address of the GPIO peripheral
	GPIO_PinConfig_t GPIO_PinConfig ;  // hold GPIO PIN Configuration settings


}GPIO_Handle_t;


/******************************************************************
*					APIs Supported by the driver
*******************************************************************/

/*
 *  Peripheral Clock Set up
 */
void GPIO_PeriCockControl ( GPIO_RegDef_t *pGPIOx , uint8_t ENorDIS ) ;



/*
 *   Initialize or De-Initialize
 */
void GPIO_Initalize (GPIO_Handle_t *pGPIOHandle) ;
void GPIO_DeInitalize (GPIO_RegDef_t *pGPIOx ) ;


/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin  (GPIO_RegDef_t *pGPIOx ,uint8_t PinNumber , uint8_t Value ) ;
uint16_t GPIO_ReadFromInputPort (GPIO_RegDef_t *pGPIOx) ;
void GPIO_WriteToOutputPin  (GPIO_RegDef_t *pGPIOx , uint8_t PinNumber , uint16_t Value ) ;
void GPIO_WriteToOutputPort (GPIO_RegDef_t *pGPIOx , uint16_t Value ) ;
void GPIO_ToggleOutputPin   (GPIO_RegDef_t *pGPIOx , uint8_t PinNumber ) ;


/*
 *  IRQ configuration and ISR Handling
 */
void GPIO_IRQConfig         (uint8_t IRQNumber , uint8_t IRQpriority , uint8_t ENorDIS  ) ;
void GPIO_IRQHandling       (uint8_t PinNumber) ;


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */

#define GPIO_MODE_INPUT         0
#define GPIO_MODE_OUTPUT        1
#define GPIO_MODE_ALTFN         2
#define GPIO_MODE_ANALOG        3
#define GPIO_MODE_IT_FT         4      // INPUT INTERRUPT FALLING EDGE
#define GPIO_MODE_IT_RT         5      // INPUT INTERRUPT RISING EDGE
#define GPIO_MODE_IT_RFT        6


/*
 * GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP        0     // push pull
#define GPIO_OP_TYPE_OD        1     // open drain


/*
 * GPIO pin possible output speeds
 */
#define GPIO_OP_SPEED_LOW           0
#define GPIO_OP_SPEED_MEDIUM        1
#define GPIO_OP_SPEED_FAST          2
#define GPIO_OP_SPEED_HIGH          3


/*
 *  GPIO pin pull up and pull down configuration MACROS
 */

#define GPIO_OP_NO_PUPD              0
#define GPIO_OP_PIN_PU               1
#define GPIO_OP_pIN_PD               2











#endif  /* DRIVERS_INC_STM32F407XX_GPIO_H_H_O_H_H_ */
