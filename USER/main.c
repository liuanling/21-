#include "stm32f4xx.h"
#include "sys.h"
#include "TIM.h"
#include "OLED.h"

#define Line 2			//ʱ������
#define First_Column 5	//ʱ�ӵ�һ�������ڵڼ���
#define Max_Num1 60		//�֣��������ֵ
#define Max_Num2 24		//Сʱ�����ֵ
#define Start_Num 0		//ʱ���֣����ʼֵ
#define Medium_Num 10	//�Ż�ʱ����ʾ��ʹ��ʾ����00:00:00
#define Hide_Num 0		//�Ż�ʱ����ʾ��ʹ��ʾ����00:00:00
#define arr 10000		//��ʱ��arr��ֵ
#define psc 8400		//��ʱ��psc��ֵ

int hours, minutes,seconds;		//���ò���ʱ���֣���

/**
  * @brief ����ת����60��=1���ӣ�60����=1Сʱ��24Сʱ�͹���
  * @param hoursСʱ
  *		   minutes����
  *		   seconds��
  */
void Time_Conversion(void)
{
	if(seconds>=Max_Num1)
	{
		seconds=Start_Num;
		minutes++;
	}
	else if(minutes>=Max_Num1)
	{
		minutes=Start_Num;
		hours++;
	}
	else if(hours>=Max_Num2) hours=Start_Num;
}

/**
  * @brief OLED��ʾʱ��
  * @param �궨����˵��������׸��
  */
void OLED_Display_Time(void)
{
	if(hours<Medium_Num)
	{
		OLED_ShowNum(Line,First_Column+1,hours);
		OLED_ShowNum(Line,First_Column,Hide_Num);
	}
	else OLED_ShowNum(Line,First_Column,hours);
	
	OLED_ShowChar(Line,First_Column+2,':');
	
	if(minutes<Medium_Num)
	{
		OLED_ShowNum(Line,First_Column+4,minutes);
		OLED_ShowNum(Line,First_Column+3,Hide_Num);
	}
	else OLED_ShowNum(Line,First_Column+3,minutes);
		
	OLED_ShowChar(Line,First_Column+5,':');
	
	if(seconds<Medium_Num)
	{
		OLED_ShowNum(Line,First_Column+7,seconds);
		OLED_ShowNum(Line,First_Column+6,Hide_Num);
	}
	else OLED_ShowNum(Line,First_Column+6,seconds);
}

/**
  * @brief ��������ʱ����ʾ
  * @param arr�Զ���װ��ֵ
  *		   pscԤ����ֵ
  */
int main(void)
{
	TIM4_Init(arr,psc);
	OLED_Init();
	
	while(1)
	{
		Time_Conversion();
		OLED_Display_Time();
	}
}

