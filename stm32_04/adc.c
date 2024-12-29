
#include "adc.h"



ADC_HandleTypeDef hadc1;   //ADC句柄
DMA_HandleTypeDef hdma_adc1;   //DMA句柄
uint16_t adc_flag=0;    //ADC状态标志
/* ADC1 init function */
void MX_ADC1_Init(void)
{


  ADC_ChannelConfTypeDef sConfig = {0};


  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;   //单通道
  //hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.ContinuousConvMode = ENABLE;   //启用连续转换模式
  hadc1.Init.DiscontinuousConvMode = DISABLE;   //禁用不连续转换模式
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;   //软件触发
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;   //数据右对齐
  hadc1.Init.NbrOfConversion = 1;   //转换一次
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();//初始化失败、调用错误处理函数
  }

 
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;   //温度传感器为输入通道
  sConfig.Rank = ADC_REGULAR_RANK_1;     //通道在序列中的位置为1
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;   //采样时钟设置
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)   
  {
    Error_Handler();//若配置失败、调用错误处理函数
  }
 

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {

    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();

    /* ADC1 DMA Init */
    /* ADC1 Init（由于只有一个通道不需要使用DMA） */
//    hdma_adc1.Instance = DMA1_Channel1;
//    hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
//    hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
//    hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
//    hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
//    hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
//    hdma_adc1.Init.Mode = DMA_NORMAL;
//    hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
//    if (HAL_DMA_Init(&hdma_adc1) != HAL_OK)
//    {
//      Error_Handler();
//    }

//    __HAL_LINKDMA(adcHandle,DMA_Handle,hdma_adc1);

    /* ADC1 interrupt Init */
    HAL_NVIC_SetPriority(ADC1_2_IRQn, 0, 0);//配置中断优先级
    HAL_NVIC_EnableIRQ(ADC1_2_IRQn);   //中断使能

  }
}
//ADC MSP反初始化函数、释放外设资源（时钟、DMA、中断等）
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {

    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();//禁用时钟

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(adcHandle->DMA_Handle);//DMA反初始化

    /* ADC1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(ADC1_2_IRQn);//禁用ADC中断

  }
}


