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
	EXTIX_Init();//外部中断
	TIM3_Int_Init(2499,7199);//定时器中断， 10Khz的计数频率，计数到2500为250ms
  while(1)
	{
		
	}
 }
