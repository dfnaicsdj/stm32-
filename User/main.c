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
  * �����ᶨ�壺
  * ���Ͻ�Ϊ(0, 0)��
  * ��������ΪX�ᣬȡֵ��Χ��0~127
  * ��������ΪY�ᣬȡֵ��Χ��0~63
  * 
  *       0             X��           127 
  *      .------------------------------->
  *    0 |
  *      |
  *      |
  *      |
  *  Y�� |
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



