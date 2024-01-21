#include "stm32f4xx.h"                  // Device header
#include "TIM.h"
#include "LED.h"
#include "Bee.h"

extern int seconds;

/**
  * @brief TIM3��ʱ����ʼ��
  * @param arr�Զ���װ��ֵ
  *			psc Ԥ����ֵ
  */
/*void TIM3_Init(const uint16_t arr,const uint16_t psc)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = arr-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//�򿪶�ʱ���ж�
	TIM_Cmd(TIM3,ENABLE);
}*/

/**
  * @brief TIM4��ʱ����ʼ��
  * @param arr�Զ���װ��ֵ
  *		   pscԤ����ֵ
  */
void TIM4_Init(const uint16_t arr,const uint16_t psc)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = arr-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//�򿪶�ʱ���ж�
	TIM_Cmd(TIM4,ENABLE);
}

/*void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
	{
		
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
}*/

/**
  * @brief ִ��ÿ�����
  * @param seconds��
  */
void Time_Get_seconds(void)
{
	seconds++;
}

/**
  * @brief ÿ�붨ʱ�жϼ���
  * @param ����ʱ����
  */
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET) //����ж�
	{
		Time_Get_seconds();
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update);  //����жϱ�־λ
	}
}
