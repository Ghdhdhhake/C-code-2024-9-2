
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"   //可变静态存储控制器
#include "lcd.h"
#include "stdio.h"



extern uint16_t adc_flag;

void SystemClock_Config(void);
uint32_t adc_get_result_average(uint8_t times);//求采样平均值


int main(void)
{


  HAL_Init();


  SystemClock_Config();


  MX_GPIO_Init();
	//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
  MX_DMA_Init();
  MX_ADC1_Init();
	MX_FSMC_Init();
	LCD_Init();
	POINT_COLOR = BLUE;
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
	LCD_Clear(WHITE);
	//LCD_ShowString(30, 60, 200, 16, 16, "TEMPERATE: 00.00C");
	LCD_ShowString(30, 70, 200, 16, 24, "HELLO!");
	LCD_ShowString(30, 100, 200, 16, 16, "ADC Test");
	LCD_ShowString(30, 120, 200, 16, 24, "TEMPERATE: 00.00C");
	HAL_ADCEx_Calibration_Start(&hadc1);//ADC校准，确保采集准确
  HAL_ADC_Start_IT(&hadc1);//使用ADC中断采样
  MX_USART1_UART_Init();
	
	printf("hello,usart\n");//通过串口发送，LCD显示屏打印
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//	uint32_t AD_Value;
//	float Vol_Value,Temperature;
//	short temp;
  while (1)
  {	
//		HAL_ADC_Start(&hadc1);  //启动ADC转换
//		HAL_ADC_PollForConversion(&hadc1,10);   //等待转换完成，10ms表示超时时间
		//AD_Value=HAL_ADC_GetValue(&hadc1);    //读取ADC转换数据（12位数据）
//		AD_Value =adc_get_result_average(10);
//		Vol_Value = (float)AD_Value*(3.3/4096);    //AD值乘以分辨率即为电压值
//		Temperature = (1.43 - Vol_Value)/0.0043 + 25;   //根据公式算出温度值
//		printf("MCU Internal Temperature: %.2f℃\r\n",Temperature);
//		printf("\r\n");
//		temp=Temperature*=100;
//		if (temp < 0)
//		{
//				temp = -temp;
//			LCD_ShowString(30 + 10 * 12, 120, 16, 16, 24, "-");   /* 显示负号 */
//		}
//		else
//		{
//				LCD_ShowString(30 + 10 * 12, 120, 16, 16, 24, " ");   /* 无符号 */
//		}
//		
//		LCD_ShowxNum(30 + 11 * 12, 120, temp / 100, 2, 24, 0);    /* 显示整数部分 */
//		LCD_ShowxNum(30 + 14 * 12, 120, temp % 100, 2, 24, 0X80); /* 显示小数部分 */
		HAL_GPIO_TogglePin(LED_GPIO_Port,GPIO_PIN_5);
		HAL_Delay(250);
					
		}
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
		uint32_t AD_Value;
		float Vol_Value,Temperature;
		short temp;
		AD_Value=HAL_ADC_GetValue(&hadc1);    //读取ADC转换数据（12位数据）
		//AD_Value =adc_get_result_average(20);
		Vol_Value = (float)AD_Value*(3.3/4096);    //AD值乘以分辨率即为电压值
		Temperature = (1.43 - Vol_Value)/0.0043 + 25;   //根据公式算出温度值
		temp=Temperature*=100;
		if (temp < 0)
		{
				temp = -temp;
			LCD_ShowString(30 + 10 * 12, 120, 16, 16, 24, "-");   /* 显示负号 */
		}
		else
		{
				LCD_ShowString(30 + 10 * 12, 120, 16, 16, 24, " ");   /* 无符号 */
		}
		
		LCD_ShowxNum(30 + 11 * 12, 120, temp / 100, 2, 24, 0);    /* 显示整数部分 */
		LCD_ShowxNum(30 + 14 * 12, 120, temp % 100, 2, 24, 0X80); /* 显示小数部分 */
		 //HAL_ADC_Start_IT(&hadc1);
}
/* USER CODE END 4 */
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
uint32_t adc_get_result_average(uint8_t times)
{
    uint32_t temp_val = 0;
    uint8_t t;

    for (t = 0; t < times; t++)     /* 获取times次数据 */
    {
        temp_val += HAL_ADC_GetValue(&hadc1);
        HAL_Delay(5);
    }

    return temp_val / times;        /* 返回平均值 */
}

