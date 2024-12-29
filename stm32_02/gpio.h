#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

typedef enum {
    LED_OFF = 0,
    LED_ON
} LED_State;
typedef enum {
    BEEP_OFF = 0,
    BEEP_ON
} BEEP_State;

/* USER CODE END Private defines */

void MX_GPIO_Init(void);
void beep_on(void);
void led_toggle(void);
void LED1_TOGGLE(void);
/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

