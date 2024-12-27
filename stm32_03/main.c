#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "bsp.h"
#include "key.h"
#include "extix.h"
#include "timer.h"


 int main(void)
 {
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	KEY_Init();
  LED_Init();
	BEEP_Init();
	EXTIX_Init();//�ⲿ�ж�
	TIM3_Int_Init(2499,7199);//��ʱ���жϣ� 10Khz�ļ���Ƶ�ʣ�������2500Ϊ250ms
  while(1)
	{
		
	}
 }
