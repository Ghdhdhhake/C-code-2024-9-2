
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"


void Error_Handler(void);


#define EXTI_KEY_Pin GPIO_PIN_4
#define EXTI_KEY_GPIO_Port GPIOE
#define EXTI_KEY_EXTI_IRQn EXTI4_IRQn
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOE



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
