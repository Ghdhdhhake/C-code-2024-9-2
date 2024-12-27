#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTEʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE4,3

	//��ʼ�� WK_UP-->GPIOA.0	  ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
}


// ����һ����̬����key_up�����ڼ�¼�����Ƿ��Ѿ����𡣳�ʼֵΪ1��ʾ��������δ����״̬��
static u8 key_up = 1;

// ����һ������KEY_Scan������ɨ�谴����״̬������mode����ָ���Ƿ����ð���״̬��
u8 KEY_Scan(u8 mode)
{
    // ���mode��Ϊ0��������key_upΪ1����ʾ�������µİ��������¼���
    if (mode) key_up = 1;  
    
    // ��key_upΪ1����һ���������£����谴������ʱ��Ӧ�����ŵ�ƽΪ0����
    // ����KEY_UP�������ͷţ����谴���ͷ�ʱ��Ӧ�����ŵ�ƽΪ1��ʱִ�����²�����
    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY_UP == 1))
    {
        // ��ʱ10���룬����ȥ������
        delay_ms(10);
        // ����key_upΪ0����ʾ�Ѽ�⵽���������¼�����ֹ�ظ�������
        key_up = 0;   
        
        // ���ݲ�ͬ�İ���״̬������Ӧ��ֵ��
        if (KEY0 == 0) return KEY0_PRES; // ����KEY0������
        else if (KEY1 == 0) return KEY1_PRES; // ����KEY1������
        else if (KEY_UP == 1) return KEY_UP_PRES; // ����KEY_UP���ͷ�
    }
    // �����а�����δ������ʱ������key_upΪ1��׼����һ�εİ�����⡣
    if (KEY0 == 1 && KEY1 == 1 && KEY_UP == 0)
    {
        key_up = 1; 
    }
    
    // ���û�а����¼�����������0��
    return 0; 
}
