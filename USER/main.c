#include "stm32f4xx.h"
#include "sys.h"
#include "TIM.h"
#include "OLED.h"

#define Line 2			//时钟行数
#define First_Column 5	//时钟第一个数字在第几列
#define Max_Num1 60		//分，秒最大数值
#define Max_Num2 24		//小时最大数值
#define Start_Num 0		//时，分，秒初始值
#define Medium_Num 10	//优化时钟显示，使显示的是00:00:00
#define Hide_Num 0		//优化时钟显示，使显示的是00:00:00
#define arr 10000		//定时器arr的值
#define psc 8400		//定时器psc的值

int hours, minutes,seconds;		//设置参数时，分，秒

/**
  * @brief 进制转化，60秒=1分钟，60分钟=1小时，24小时就归零
  * @param hours小时
  *		   minutes分钟
  *		   seconds秒
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
  * @brief OLED显示时间
  * @param 宏定义已说明，不再赘述
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
  * @brief 主函数，时钟显示
  * @param arr自动重装载值
  *		   psc预分屏值
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

