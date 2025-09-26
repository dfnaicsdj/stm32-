#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "TREE.h"
void Key_operation(int operation);
	
void key_I_INIT(void){
		
		GPIO_InitTypeDef gpio; //初始化，定义GPIO结构体

	
	//配置GPIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//启用GPIOA时钟

	
	
		//配置PA3
		gpio.GPIO_Pin = GPIO_Pin_3;//将GPIO引脚配置为PA3
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//设置模式，上拉输入
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//设置速度，50Mhz
		GPIO_Init(GPIOA, &gpio);//将结构体中的设置写入对应的GPIOA寄存器
	
	//配置PA4
		gpio.GPIO_Pin = GPIO_Pin_4;//将GPIO引脚配置为PA4
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//设置模式，上拉输入
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//设置速度，50Mhz
		GPIO_Init(GPIOA, &gpio);//将结构体中的设置写入对应的GPIOA寄存器
	
	//配置PA5
		gpio.GPIO_Pin = GPIO_Pin_5;//将GPIO引脚配置为PA5
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//设置模式，上拉输入
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//设置速度，50Mhz	
		GPIO_Init(GPIOA, &gpio);//将结构体中的设置写入对应的GPIOA寄存器
		
			//配置PA6
		gpio.GPIO_Pin = GPIO_Pin_6;//将GPIO引脚配置为PA5
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//设置模式，上拉输入
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//设置速度，50Mhz	
		GPIO_Init(GPIOA, &gpio);//将结构体中的设置写入对应的GPIOA寄存器
	
}

/**
  * @brief  检测按键是否按下
  * @param  引脚名
  * @retval 有按键按下，flag=1；反之为0
  */
uint8_t key_GetFlag(uint16_t GPIO_Pin){
	uint8_t flag = 0;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin) == 0){//检测到按键按下
		Delay_ms(10);//消抖
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin) == 0){
		flag = 1;//确认按键按下
		//while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin) == 0){}//按键抬起，退出循环
		//Delay_ms(10);		
		}
	}
	return flag;
}

/**
  * @brief  检测按键是否按下的跳转函数
  * @param  无
  * @retval 无
  */

void Key_press(void){
	if (key_GetFlag(GPIO_Pin_3) == 1){
		process_key(2);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 0){process_key(0);}//按键抬起，退出循环
			}//右键光标++
	else if (key_GetFlag(GPIO_Pin_4) == 1){
		process_key(1);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4) == 0){process_key(0);}//按键抬起，退出循环
	}//左键光标--
	else if (key_GetFlag(GPIO_Pin_5) == 1){
		process_key(3);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5) == 0){process_key(0);}//按键抬起，退出循环
	}
	else if (key_GetFlag(GPIO_Pin_6) == 1){
		process_key(4);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6) == 0){process_key(0);}//按键抬起，退出循环
	}
	else{process_key(0);}//没有操作，保持页数和光标，刷新时间

}
/*
void Key_press(void){
	if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==0){process_key(2);}//右键光标++
	else if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0){process_key(1);}//左键光标--
	else if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0){process_key(3);}
	else if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0){process_key(4);}
	else{process_key(0);}//没有操作，保持页数和光标，刷新时间

}*/



int8_t key_flag = 0;//初始标志位为0，光标位于0位置
uint8_t page = 1;//初始页数为1

/**状态机实现页面切换的函数，目前基于多叉树切换，此函数废弃
  * @brief  按下按键后的操作函数
  * @param  操作参数
  * @retval 无
  */
/*
void Key_operation(int operation){
	switch(operation){
		case 0:
			Show_UI(page, key_flag);
			break;
		case 3:
			key_flag++;
			if(key_flag > 1) key_flag = 0;
			Show_UI(page, key_flag);
			break;
		case 4:
			key_flag--;
			if(key_flag < 0) key_flag = 1;
			Show_UI(page, key_flag);
			break;
		case 5:
			page++;
			if(page>1){page = 1;}
			key_flag = 0;
			Show_UI(page, key_flag);
			break;
			
			}
				
	
	}
	
*/
