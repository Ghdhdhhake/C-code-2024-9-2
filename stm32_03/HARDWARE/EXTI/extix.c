#include "extix.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "bsp.h"

 
void EXTIX_Init(void)
{
 
   	EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;

    KEY_Init();	 //	�����˿ڳ�ʼ��
	  LED_Init();  //LED��ʼ��
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��



   //�ж����Լ��жϳ�ʼ������ �½��ش��� //KEY1
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;//�����ж���
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//ѡ���ж�
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
  	EXTI_Init(&EXTI_InitStructure);	  	

   //GPIOE.4	  �ж����Լ��жϳ�ʼ������  �½��ش���	//KEY0
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;
  	EXTI_Init(&EXTI_InitStructure);	 

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//ʹ�ܰ���KEY1���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	 

  	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�0 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  
 
}

//�ⲿ�ж�3�������
void EXTI3_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY1==0)	 //����KEY1
	{				 
		LED1=!LED1;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE3�ϵ��жϱ�־λ  
}

void EXTI4_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY0==0)	 //����KEY0
	{
		BEEP=!BEEP;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line4);  //���LINE4�ϵ��жϱ�־λ  
}


