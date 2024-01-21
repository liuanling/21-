#include "stm32f4xx.h"
#include "KEY.h"

/**
  * @brief 按键初始化，用于读取PD3和PD4引脚电平变化
  * @param 按键是PD3,PD4
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



