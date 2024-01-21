#include "stm32f4xx.h"                  // Device header
#include "Bee.h"

/**
  * @brief ·äÃùÆ÷³õÊ¼»¯
  * @param ·äÃùÆ÷ÊÇPB14
  */
void Bee_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}

void Bee_Turn(void)
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)==0)
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
	else GPIO_ResetBits(GPIOB,GPIO_Pin_14);
}
