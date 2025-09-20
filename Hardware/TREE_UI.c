#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyRTC.h"
#include "stdio.h"
#include "stdlib.h"
#include "OLED_Data.h"

/**
  * @brief  绘制首页UI
  * @param  光标值
  * @retval 无
  */
void draw_first_page(uint8_t cursor) {
	switch(cursor){
		case 1:
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_Printf(0,0,OLED_6X8,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
				OLED_Printf(16,16,OLED_12X24,"%02d:%02d:%02d",MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
				OLED_ShowString(0,48,"菜单",OLED_8X16);
				OLED_ShowString(96,48,"设置",OLED_8X16);
				OLED_ReverseArea(0,48,32,16);
				OLED_Update();
				break;
		case 2:
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_Printf(0,0,OLED_6X8,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
				OLED_Printf(16,16,OLED_12X24,"%02d:%02d:%02d",MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
				OLED_ShowString(0,48,"菜单",OLED_8X16);
				OLED_ShowString(96,48,"设置",OLED_8X16);
				OLED_ReverseArea(96,48,32,16);
				OLED_Update();
	}
}


/**
  * @brief  绘制第二层第一个节点UI，4个光标状态
  * @param  光标值
  * @retval 无
  */
void draw_page2_1(uint8_t cursor) {
	switch(cursor){
		case 1:
				//电话图标
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, phone);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
		case 2:
				//陀螺仪图标
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, mpu);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
		case 3:
				//小恐龙图标
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, dragon);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
		case 4:
				//秒表图标
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, stopwatch);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;			
	
	}
}

/**
  * @brief  绘制第二层第二个节点UI
  * @param  光标值
  * @retval 无
  */
void draw_page2_2(uint8_t cursor) {
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowString(0,48,"菜单",OLED_8X16);
				OLED_ShowString(96,48,"设置",OLED_8X16);
				OLED_ReverseArea(0,48,32,16);
				OLED_Update();
}

/**
  * @brief  绘制第3层第1个节点UI,电话图标,2-1的子节点
  * @param  光标值
  * @retval 无
  */
void draw_page3_1(uint8_t cursor) {
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, phone);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
}
/**
  * @brief  绘制第3层第二个节点UI，陀螺仪图标,2-1的子节点
  * @param  光标值
  * @retval 无
  */
void draw_page3_2(uint8_t cursor) {
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_ShowImage(30, 0, 68, 63, mpu);
				OLED_Update();
}
/**
  * @brief  绘制第3层第3个节点UI，小恐龙图标,2-1的子节点
  * @param  光标值
  * @retval 无
  */
void draw_page3_3(uint8_t cursor) {
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_ShowImage(30, 0, 68, 63, dragon);
				OLED_Update();
}



uint8_t hour,min,sec,fraction;
uint8_t history[4];
uint8_t start_timing_flag;
uint8_t flag;
/**
  * @brief  绘制第3层第4个节点UI，秒表图标,2-1的子节点
  * @param  光标值
  * @retval 无
  */
void draw_page3_4(uint8_t cursor) {
	switch(cursor){
		case 1://计时器初始页面，0h0m0s
				flag = 0;
				OLED_Clear();
				MyRTC_ReadTime();
				start_timing_flag = 0;
				hour = 0;
				min = 0;
				sec = 0;
				fraction = 0;
				OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",hour,min,sec,fraction);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_ShowString(8,44,"历史",OLED_8X16);//左箭头
				OLED_ShowString(88,44,"开始",OLED_8X16);//右箭头
				OLED_Update();
				break;
		case 2://开始计时页面，显示计时时间
				OLED_Clear();
				MyRTC_ReadTime();
				flag = 1;
				start_timing_flag = 1;
				OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",hour,min,sec,fraction);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_ShowString(88,44,"停止",OLED_8X16);//右箭头
				OLED_ShowString(8,44,"清除",OLED_8X16);//左箭头
				OLED_Update();
				break;
		case 3://停止页面，显示停止时间
				OLED_Clear();
				MyRTC_ReadTime();
				start_timing_flag = 0;
				if(flag == 0){//从初始页面查看最近历史
					OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",history[0],history[1],history[2],history[3]);
					OLED_ShowString(8,44,"继续",OLED_8X16);//左箭头
					OLED_ShowString(88,44,"返回",OLED_8X16);//右箭头
				}
				else if(flag == 1){//当从case2到此处时间暂停时，会有0.1s左右的延后，初步判断与按键的按下-抬起的实现逻辑有关
					//上面else if若用start_timing_flag判断，在下个while主循环中，会由于此处置0导致跳到case3的if语句中，从而不会显示else if的UI
					history[0] = hour;
					history[1] = min;
					history[2] = sec;
					history[3] = fraction;
					OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",history[0],history[1],history[2],history[3]);
					OLED_ShowString(8,44,"继续",OLED_8X16);//左箭头
					OLED_ShowString(88,44,"清除",OLED_8X16);//右箭头
				}
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
	}

}


/**
  * @brief  秒表定时函数，配置为TIM2中断函数，频率1kHZ
  * @param  计时开始参数，1开始，0停止
  * @retval 无
  */
void StopWatch_Tick(void)
{
	static uint16_t Count;
	Count++;
	if(Count>=10)
	{
		Count=0;
			if(start_timing_flag==1)
		{
			fraction++;
				if(fraction >99)
			{
				fraction = 0;
				sec++;
				if(sec>=60)
				{
					sec=0;
					min++;
					if(min>=60)
					{
						min=0;
						hour++;
						if(hour>99)hour=0;
					}
				}
			}
		}
	}
	
}





