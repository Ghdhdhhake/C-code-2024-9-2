
#include "usart.h"
#include "stdio.h"



UART_HandleTypeDef huart1;



void MX_USART1_UART_Init(void)
{


  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;   //���ò�����
  huart1.Init.WordLength = UART_WORDLENGTH_8B;   //����֡����Ϊ8
  huart1.Init.StopBits = UART_STOPBITS_1;   //ֹͣλΪ1
  huart1.Init.Parity = UART_PARITY_NONE;   //������żУ��λ
  huart1.Init.Mode = UART_MODE_TX_RX;     //���÷��ͺͽ���ģʽ
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;   //����Ӳ������
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;   //���ù�����λ16��
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }


}
//MSP ��Ƭ���ײ����
void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {

    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();   //ʹ��USARTʱ��

    __HAL_RCC_GPIOA_CLK_ENABLE();   //ʹ��GPIOʱ��
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;   //TX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;   //�����������
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;   //RX
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;   //����ģʽ
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}
//UART ����ʼ��
void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {

    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);

  }
}

/* USER CODE BEGIN 1 */
//�˿��ض����ض���printf������USART1�� ���ڵ�����Ϣ���
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);   //���͵����ַ�
  return ch;
}
//�ض���scanf������USART1, �Ա��ڴӴ��ڽ�������
int fgetc(FILE *f)
{
  uint8_t ch = 0;
  HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
  return ch;
}

