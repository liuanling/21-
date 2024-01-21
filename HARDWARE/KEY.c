#include "stm32f4xx.h"
#include "KEY.h"

/**
  * @brief ������ʼ�������ڶ�ȡPD3��PD4���ŵ�ƽ�仯
  * @param ������PD3,PD4
  */
void KEY_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	GPIO_InitTypeDef GPIO_InitStucture;
	GPIO_InitStucture.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStucture.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStucture.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStucture.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStucture.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOD,&GPIO_InitStucture);
}



