#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE4,3

	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0
}


// 定义一个静态变量key_up，用于记录按键是否已经弹起。初始值为1表示按键处于未按下状态。
static u8 key_up = 1;

// 定义一个函数KEY_Scan，用于扫描按键的状态。参数mode用于指定是否重置按键状态。
u8 KEY_Scan(u8 mode)
{
    // 如果mode不为0，则重置key_up为1，表示允许检测新的按键按下事件。
    if (mode) key_up = 1;  
    
    // 当key_up为1且任一按键被按下（假设按键按下时对应的引脚电平为0），
    // 或者KEY_UP按键被释放（假设按键释放时对应的引脚电平为1）时执行以下操作。
    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY_UP == 1))
    {
        // 延时10毫秒，用于去抖动。
        delay_ms(10);
        // 设置key_up为0，表示已检测到按键按下事件，防止重复触发。
        key_up = 0;   
        
        // 根据不同的按键状态返回相应的值。
        if (KEY0 == 0) return KEY0_PRES; // 按键KEY0被按下
        else if (KEY1 == 0) return KEY1_PRES; // 按键KEY1被按下
        else if (KEY_UP == 1) return KEY_UP_PRES; // 按键KEY_UP被释放
    }
    // 当所有按键均未被按下时，设置key_up为1，准备下一次的按键检测。
    if (KEY0 == 1 && KEY1 == 1 && KEY_UP == 0)
    {
        key_up = 1; 
    }
    
    // 如果没有按键事件发生，返回0。
    return 0; 
}
