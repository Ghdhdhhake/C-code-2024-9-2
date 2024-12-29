
#include "adc.h"



ADC_HandleTypeDef hadc1;   //ADC���
DMA_HandleTypeDef hdma_adc1;   //DMA���
uint16_t adc_flag=0;    //ADC״̬��־
/* ADC1 init function */
void MX_ADC1_Init(void)
{


  ADC_ChannelConfTypeDef sConfig = {0};


  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;   //��ͨ��
  //hadc1.Init.ContinuousConvMode = DISABLE;
	hadc1.Init.ContinuousConvMode = ENABLE;   //��������ת��ģʽ
  hadc1.Init.DiscontinuousConvMode = DISABLE;   //���ò�����ת��ģʽ
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;   //�������
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;   //�����Ҷ���
  hadc1.Init.NbrOfConversion = 1;   //ת��һ��
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();//��ʼ��ʧ�ܡ����ô�������
  }

 
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;   //�¶ȴ�����Ϊ����ͨ��
  sConfig.Rank = ADC_REGULAR_RANK_1;     //ͨ���������е�λ��Ϊ1
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;   //����ʱ������
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)   
  {
    Error_Handler();//������ʧ�ܡ����ô�������
  }
 

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {

    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();

    /* ADC1 DMA Init */
    /* ADC1 Init������ֻ��һ��ͨ������Ҫʹ��DMA�� */
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
    HAL_NVIC_SetPriority(ADC1_2_IRQn, 0, 0);//�����ж����ȼ�
    HAL_NVIC_EnableIRQ(ADC1_2_IRQn);   //�ж�ʹ��

  }
}
//ADC MSP����ʼ���������ͷ�������Դ��ʱ�ӡ�DMA���жϵȣ�
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {

    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();//����ʱ��

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(adcHandle->DMA_Handle);//DMA����ʼ��

    /* ADC1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(ADC1_2_IRQn);//����ADC�ж�

  }
}


