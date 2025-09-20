#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Key.h"
#include "MENU.h"
#include "KEY_I.h"
#include "MyRTC.h"
#include "OLED_Data.h"
#include "TREE.h"
/**
  * 坐标轴定义：
  * 左上角为(0, 0)点
  * 横向向右为X轴，取值范围：0~127
  * 纵向向下为Y轴，取值范围：0~63
  * 
  *       0             X轴           127 
  *      .------------------------------->
  *    0 |
  *      |
  *      |
  *      |
  *  Y轴 |
  *      |
  *      |
  *      |
  *   63 |
  *      v
  * 
  */
void MENU_Init(void);

int main(void)
{	
	MyRTC_Init();
	Timer_Init();
	key_I_INIT();
	OLED_Init();
	init_page_tree();


	//MENU_Init();
	while(1){
		Key_press();
	}
}



