#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyRTC.h"
void Show_UI(uint8_t page,uint8_t key_flag);//函数原型声明

void MENU_Init(void){
	Show_UI(1,0);//初始页数1，光标位于0位置
}

void Show_UI(uint8_t page, uint8_t key_flag)
{	
	OLED_Clear();
	
	switch(page){
		case 1 :
			if (key_flag == 0){
				MyRTC_ReadTime();
				OLED_Printf(0,0,OLED_6X8,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
				OLED_Printf(16,16,OLED_12X24,"%02d:%02d:%02d",MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
				OLED_ShowString(0,48,"菜单",OLED_8X16);
				OLED_ShowString(96,48,"设置",OLED_8X16);
				OLED_ReverseArea(0,48,32,16);
				
			}
			if(key_flag == 1){
				MyRTC_ReadTime();
				OLED_Printf(0,0,OLED_6X8,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
				OLED_Printf(16,16,OLED_12X24,"%02d:%02d:%02d",MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
				OLED_ShowString(0,48,"菜单",OLED_8X16);
				OLED_ShowString(96,48,"设置",OLED_8X16);
				OLED_ReverseArea(96,48,32,16);
				
			}
			OLED_Update();
			break;
			
		
		
	

}
}
