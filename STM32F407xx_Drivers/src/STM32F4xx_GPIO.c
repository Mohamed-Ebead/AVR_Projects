/*
 * STM32F4xx_GPIO.c
 *
 *  Created on: Mar 23, 2020
 *      Author: Mohamed  Ebead
 */



#include "STM32F407xx.h"
#include "STD_TYPES.h"
#include "STM32F407xx_GPIO_h.h"


/*d
 * @fn
 *
 * @brief
 *
 * @param[in]     - base address of the GPIO peripheral
 * @param[in]     - Enable or Disable Macro
 * @param[in]
 *
 * @return        - none
 *
 * @Note          - none
 *
 */
void GPIO_PeriCockControl ( GPIO_RegDef_t *pGPIOx , uint8_t ENorDIS )
{
	if (ENorDIS == ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN() ;
		}

		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOC)
		{
		    GPIOC_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOE)
		{
		    GPIOE_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOG)
		{
		    GPIOG_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN() ;
		}
		else if (pGPIOx == GPIOI)
		{
		    GPIOI_PCLK_EN() ;
		}

	}
		else
		{


		}

}


/*
 *   Initialize or De-Initialize
 */
void GPIO_Initalize (GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0 ;  // temp register


	// 1. configure the mode of GPIO pin

	if (pGPIOHandle->GPIO_PinConfig.GPIO_Pin_Mode <= GPIO_MODE_ANALOG)
	{
		 temp = pGPIOHandle->GPIO_PinConfig.GPIO_Pin_Mode << (2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ) ;
		 pGPIOHandle->pGPIOx->MODER  |= temp ;
	}
	else
	{
		// interrupt mode
	}

	temp = 0 ;

	//2. configure the speed
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ;
	pGPIOHandle->pGPIOx->OSPEEDER |= temp ;

	temp = 0 ;

	//3. configure pull up and pull down settings
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ;
	//make sure the required bitfields is clear before settingthem
		pGPIOHandle->pGPIOx->PUPDR &=~ (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ;
		pGPIOHandle->pGPIOx->PUPDR |= temp ;

	temp = 0 ;

	//4. configure the output type

	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << ( pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ;
	//make sure the required bitfields is clear before settingthem
	pGPIOHandle->pGPIOx->OTYPER &=~ (0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) ;
	pGPIOHandle->pGPIOx->OTYPER |= temp ;

	temp = 0 ;

	//5. configure the alternate functionality if required

	if (pGPIOHandle->GPIO_PinConfig.GPIO_Pin_Mode == GPIO_MODE_ALTFN  )
		{
			uint8_t temp1  , temp2  ;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber /8 ;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8 ;

		//make sure the required bitfields is clear before setting them
		pGPIOHandle->pGPIOx->AFR[temp1] &=~ (0xf <<(4 * temp2 ) ) ;
		pGPIOHandle->pGPIOx->AFR[temp1] |= ( pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode <<(4 * temp2 ) ) ;

		}


}


void GPIO_DeInitalize (GPIO_RegDef_t *pGPIOx )
{

		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_RESET() ;
		}

		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_RESET() ;
		}
		else if (pGPIOx == GPIOI)
		{
			GPIOI_PCLK_RESET() ;
		}
		else
		{

	}
}


/*
 * Data Read and Write
 */
uint8_t GPIO_ReadFromInputPin  (GPIO_RegDef_t *pGPIOx ,uint8_t PinNumber , uint8_t Value )
{
	uint8_t value  ;
	value = (uint8_t)( ( pGPIOx->IDR >> PinNumber ) & 0x00000001 );
	return value;
}

uint16_t GPIO_ReadFromInputPort (GPIO_RegDef_t *pGPIOx)
{
		uint16_t value  ;
		value =  (uint16_t )pGPIOx->IDR  ;
		return value;

}


void GPIO_WriteToOutputPin  (GPIO_RegDef_t *pGPIOx , uint8_t PinNumber , uint16_t Value )
{
	if (Value == GPIO_PIN_SET)
	{
		// write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= (1 << PinNumber) ;
	}
	else {
		// write 0 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR &=~ (1 << PinNumber) ;
	}

}


void GPIO_WriteToOutputPort (GPIO_RegDef_t *pGPIOx , uint16_t Value )
{
	pGPIOx->ODR = Value ;
}


void GPIO_ToggleOutputPin   (GPIO_RegDef_t *pGPIOx , uint8_t PinNumber )
{
	pGPIOx->ODR ^= (1<<PinNumber ) ;
}

/*
 *  IRQ configuration and ISR Handling
 */

void GPIO_IRQConfig         (uint8_t IRQNumber , uint8_t IRQpriority , uint8_t ENorDIS  )
{

}



void GPIO_IRQHandling       (uint8_t PinNumber)
{


}

