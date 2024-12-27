#include "main.h"
#include "adc.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"
#include "lcd.h"
#include "stdio.h"
#include <string.h>

#define RX_BUFFER_SIZE 4
char rx_buffer[RX_BUFFER_SIZE];

void SystemClock_Config(void);
uint32_t adc_get_result_average(uint8_t times);

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_FSMC_Init();
    LCD_Init();
    POINT_COLOR = RED;
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
    LCD_Clear(WHITE);
    LCD_ShowString(30, 70, 200, 16, 24, "HELLO!");
    LCD_ShowString(30, 100, 200, 16, 16, "USART Test");
    LCD_ShowString(30, 120, 200, 16, 24, "TEMPERATE: 00.00C");
    HAL_ADCEx_Calibration_Start(&hadc1);
    MX_USART1_UART_Init();
    HAL_UART_Receive_IT(&huart1, (uint8_t *)rx_buffer, RX_BUFFER_SIZE);
    printf("\nhello, welcome:\r\n");

    // 进入主循环
    while (1) {
        // 可以在这里添加其他处理代码
    }
}

void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
        Error_Handler();
    }

    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
    PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;

    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
        Error_Handler();
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART1) {
        rx_buffer[strcspn(rx_buffer, "\r\n")] = 0;
        printf("\nReceived Command: %s\n", rx_buffer);

        if (strncmp(rx_buffer, "on", 2) == 0) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
        } else if (strncmp(rx_buffer, "off", 3) == 0) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
        }

        memset(rx_buffer, 0, RX_BUFFER_SIZE);
        HAL_UART_Receive_IT(huart, (uint8_t *)rx_buffer, RX_BUFFER_SIZE); // 重新启动接收中断
    }
}

void Error_Handler(void) {
    __disable_irq();
    while (1) {}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
}
#endif

uint32_t adc_get_result_average(uint8_t times) {
    uint32_t temp_val = 0;
    for (uint8_t t = 0; t < times; t++) {
        temp_val += HAL_ADC_GetValue(&hadc1);
        HAL_Delay(5);
    }
    return temp_val / times;
}
