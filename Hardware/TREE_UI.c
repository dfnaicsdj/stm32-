#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyRTC.h"
#include "stdio.h"
#include "stdlib.h"
#include "OLED_Data.h"
#include "DINO.h"
#include "Delay.h"
#include "MPU6050.h"
#include "math.h"
#include "TREE.h"
/**
  * @brief  ������ҳUI
  * @param  ���ֵ
  * @retval ��
  */
void draw_first_page(uint8_t cursor) {
	switch(cursor){
		case 1:
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_Printf(0,0,OLED_6X8,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
				OLED_Printf(16,16,OLED_12X24,"%02d:%02d:%02d",MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
				OLED_ShowString(0,48,"�˵�",OLED_8X16);
				OLED_ShowString(96,48,"����",OLED_8X16);
				OLED_ReverseArea(0,48,32,16);
				OLED_Update();
				break;
		case 2:
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_Printf(0,0,OLED_6X8,"%d-%d-%d",MyRTC_Time[0],MyRTC_Time[1],MyRTC_Time[2]);
				OLED_Printf(16,16,OLED_12X24,"%02d:%02d:%02d",MyRTC_Time[3],MyRTC_Time[4],MyRTC_Time[5]);
				OLED_ShowString(0,48,"�˵�",OLED_8X16);
				OLED_ShowString(96,48,"����",OLED_8X16);
				OLED_ReverseArea(96,48,32,16);
				OLED_Update();
	}
}


/**
  * @brief  ���Ƶڶ����һ���ڵ�UI��4�����״̬
  * @param  ���ֵ
  * @retval ��
  */
void draw_page2_1(uint8_t cursor) {
	switch(cursor){
		case 1:
				//�绰ͼ��
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, phone);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
		case 2:
				//������ͼ��
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, mpu);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
		case 3:
				//С����ͼ��
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, dragon);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
		case 4:
				//���ͼ��
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
  * @brief  ���Ƶڶ���ڶ����ڵ�UI
  * @param  ���ֵ
  * @retval ��
  */
void draw_page2_2(uint8_t cursor) {
	switch(cursor){
		case 1:
			OLED_Clear();
			MyRTC_ReadTime();
			OLED_Printf(30,12,OLED_6X8,"year:%d",MyRTC_Time[0]);
			OLED_Printf(30,20,OLED_6X8,"month:%d",MyRTC_Time[1]);
			OLED_Printf(30,28,OLED_6X8,"day:%d",MyRTC_Time[2]);
			OLED_Printf(30,36,OLED_6X8,"hour:%d",MyRTC_Time[3]);
			OLED_Printf(30,44,OLED_6X8,"min:%d",MyRTC_Time[4]);
			OLED_Printf(30,52,OLED_6X8,"sec:%d",MyRTC_Time[5]);
			OLED_ShowImage(20, 12, 8, 8, rarrow8);//year
			OLED_ReverseArea(30,12,24,8);
			OLED_Update();
			break;
		case 2:
			OLED_Clear();
			MyRTC_ReadTime();
			OLED_Printf(30,12,OLED_6X8,"year:%d",MyRTC_Time[0]);
			OLED_Printf(30,20,OLED_6X8,"month:%d",MyRTC_Time[1]);
			OLED_Printf(30,28,OLED_6X8,"day:%d",MyRTC_Time[2]);
			OLED_Printf(30,36,OLED_6X8,"hour:%d",MyRTC_Time[3]);
			OLED_Printf(30,44,OLED_6X8,"min:%d",MyRTC_Time[4]);
			OLED_Printf(30,52,OLED_6X8,"sec:%d",MyRTC_Time[5]);
			OLED_ShowImage(20, 20, 8, 8, rarrow8);//month
			OLED_ReverseArea(30,20,30,8);
			OLED_Update();
			break;
		case 3:
			OLED_Clear();
			MyRTC_ReadTime();
			OLED_Printf(30,12,OLED_6X8,"year:%d",MyRTC_Time[0]);
			OLED_Printf(30,20,OLED_6X8,"month:%d",MyRTC_Time[1]);
			OLED_Printf(30,28,OLED_6X8,"day:%d",MyRTC_Time[2]);
			OLED_Printf(30,36,OLED_6X8,"hour:%d",MyRTC_Time[3]);
			OLED_Printf(30,44,OLED_6X8,"min:%d",MyRTC_Time[4]);
			OLED_Printf(30,52,OLED_6X8,"sec:%d",MyRTC_Time[5]);
			OLED_ShowImage(20, 28, 8, 8, rarrow8);//day
			OLED_ReverseArea(30,28,18,8);
			OLED_Update();
			break;
		case 4:
			OLED_Clear();
			MyRTC_ReadTime();
			OLED_Printf(30,12,OLED_6X8,"year:%d",MyRTC_Time[0]);
			OLED_Printf(30,20,OLED_6X8,"month:%d",MyRTC_Time[1]);
			OLED_Printf(30,28,OLED_6X8,"day:%d",MyRTC_Time[2]);
			OLED_Printf(30,36,OLED_6X8,"hour:%d",MyRTC_Time[3]);
			OLED_Printf(30,44,OLED_6X8,"min:%d",MyRTC_Time[4]);
			OLED_Printf(30,52,OLED_6X8,"sec:%d",MyRTC_Time[5]);
			OLED_ShowImage(20, 36, 8, 8, rarrow8);//hour
			OLED_ReverseArea(30,36,24,8);
			OLED_Update();
			break;
		case 5:
			OLED_Clear();
			MyRTC_ReadTime();
			OLED_Printf(30,12,OLED_6X8,"year:%d",MyRTC_Time[0]);
			OLED_Printf(30,20,OLED_6X8,"month:%d",MyRTC_Time[1]);
			OLED_Printf(30,28,OLED_6X8,"day:%d",MyRTC_Time[2]);
			OLED_Printf(30,36,OLED_6X8,"hour:%d",MyRTC_Time[3]);
			OLED_Printf(30,44,OLED_6X8,"min:%d",MyRTC_Time[4]);
			OLED_Printf(30,52,OLED_6X8,"sec:%d",MyRTC_Time[5]);
			OLED_ShowImage(20, 44, 8, 8, rarrow8);//min
			OLED_ReverseArea(30,44,18,8);
			OLED_Update();
			break;
		case 6:
			OLED_Clear();
			MyRTC_ReadTime();
			OLED_Printf(30,12,OLED_6X8,"year:%d",MyRTC_Time[0]);
			OLED_Printf(30,20,OLED_6X8,"month:%d",MyRTC_Time[1]);
			OLED_Printf(30,28,OLED_6X8,"day:%d",MyRTC_Time[2]);
			OLED_Printf(30,36,OLED_6X8,"hour:%d",MyRTC_Time[3]);
			OLED_Printf(30,44,OLED_6X8,"min:%d",MyRTC_Time[4]);
			OLED_Printf(30,52,OLED_6X8,"sec:%d",MyRTC_Time[5]);
			OLED_ShowImage(20, 52, 8, 8, rarrow8);//year
			OLED_ReverseArea(30,52,18,8);
			OLED_Update();
			break;
	}
}

/**
  * @brief  ���Ƶ�3���1���ڵ�UI,�绰ͼ��,2-1���ӽڵ�
  * @param  ���ֵ
  * @retval ��
  */
void draw_page3_1(uint8_t cursor) {
				OLED_Clear();
				MyRTC_ReadTime();
				OLED_ShowImage(30, 0, 68, 63, phone);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
}


void MPU6050_Calculation(void);
/**
  * @brief  ���Ƶ�3��ڶ����ڵ�UI��������ͼ��,2-1���ӽڵ�
  * @param  ���ֵ
  * @retval ��
  */
void draw_page3_2(uint8_t cursor) {
	switch(cursor){
		case 1:
			OLED_Clear();
			MyRTC_ReadTime();
			MPU6050_Calculation();
			MPU6050_show();
			OLED_Update();	
			break;
		case 2:
			OLED_Clear();
			MyRTC_ReadTime();
			MPU6050_Calculation();
			MPU6050_gradienter();
			OLED_Update();	
		}
}

/**
  * @brief  ���Ƶ�3���3���ڵ�UI��С������Ϸ,2-1���ӽڵ�
  * @param  ���ֵ
  * @retval ��
  */
uint8_t state=0;//
void draw_page3_3(uint8_t cursor) {
	switch(cursor){
		case 1:
			if((state == 1)||(state == 0 && dino_jump_flag == 1)){//����л�/��Ծ��־λ=1����Ծ
				OLED_Clear();
				MyRTC_ReadTime();
				show_score();
				show_ground();
				show_barrier();
				show_cloud();
				show_dino(1);
				OLED_Update();
			}
			if(state == 0 && dino_jump_flag == 0){
				OLED_Clear();
				MyRTC_ReadTime();
				show_score();
				show_ground();
				show_barrier();
				show_cloud();
				show_dino(0);
				OLED_Update();
			}
			if(isColliding(&dino,&barrier)==1){
				OLED_Clear();
				OLED_ShowString(28,24,"Game Over",OLED_8X16);
				OLED_Update();
				Delay_s(1);
				game_init();
				OLED_Clear();
				OLED_Update();
			};
			state = 0;
			break;
		case 2://��Ծ
			if((state == 0)||(state == 1 && dino_jump_flag == 1)){//����л�/��Ծ��־λ=1����Ծ
				OLED_Clear();
				MyRTC_ReadTime();
				show_score();
				show_ground();
				show_barrier();
				show_cloud();
				show_dino(1);
				OLED_Update();
			}
			if(state == 1 && dino_jump_flag == 0){
				OLED_Clear();
				MyRTC_ReadTime();
				show_score();
				show_ground();
				show_barrier();
				show_cloud();
				show_dino(0);
				OLED_Update();
			}
			state = 1;
			if(isColliding(&dino,&barrier)==1){
				OLED_Clear();
				OLED_ShowString(28,24,"Game Over",OLED_8X16);
				OLED_Update();
				Delay_s(1);
				game_init();
				OLED_Clear();
				OLED_Update();
			};
			break;
	}
				
}



uint8_t hour,min,sec,fraction;
uint8_t history[4];
uint8_t start_timing_flag;
uint8_t flag;
/**
  * @brief  ���Ƶ�3���4���ڵ�UI�������,2-1���ӽڵ�
  * @param  ���ֵ
  * @retval ��
  */
void draw_page3_4(uint8_t cursor) {
	switch(cursor){
		case 1://��ʱ����ʼҳ�棬0h0m0s
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
				OLED_ShowString(8,44,"��ʷ",OLED_8X16);//���ͷ
				OLED_ShowString(88,44,"��ʼ",OLED_8X16);//�Ҽ�ͷ
				OLED_Update();
				break;
		case 2://��ʼ��ʱҳ�棬��ʾ��ʱʱ��
				OLED_Clear();
				MyRTC_ReadTime();
				flag = 1;
				start_timing_flag = 1;
				OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",hour,min,sec,fraction);
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_ShowString(88,44,"ֹͣ",OLED_8X16);//�Ҽ�ͷ
				OLED_ShowString(8,44,"���",OLED_8X16);//���ͷ
				OLED_Update();
				break;
		case 3://ֹͣҳ�棬��ʾֹͣʱ��
				OLED_Clear();
				MyRTC_ReadTime();
				start_timing_flag = 0;
				if(flag == 0){//�ӳ�ʼҳ��鿴�����ʷ
					OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",history[0],history[1],history[2],history[3]);
					OLED_ShowString(8,44,"����",OLED_8X16);//���ͷ
					OLED_ShowString(88,44,"����",OLED_8X16);//�Ҽ�ͷ
				}
				else if(flag == 1){//����case2���˴�ʱ����ͣʱ������0.1s���ҵ��Ӻ󣬳����ж��밴���İ���-̧���ʵ���߼��й�
					//����else if����start_timing_flag�жϣ����¸�while��ѭ���У������ڴ˴���0��������case3��if����У��Ӷ�������ʾelse if��UI
					history[0] = hour;
					history[1] = min;
					history[2] = sec;
					history[3] = fraction;
					OLED_Printf(20,20,OLED_8X16,"%02d:%02d:%02d.%02d",history[0],history[1],history[2],history[3]);
					OLED_ShowString(8,44,"����",OLED_8X16);//���ͷ
					OLED_ShowString(88,44,"���",OLED_8X16);//�Ҽ�ͷ
				}
				OLED_ShowImage(0, 24, 16, 16, larrow);
				OLED_ShowImage(112, 24, 16, 16, rarrow);
				OLED_Update();
				break;
	}

}


/**
  * @brief  ���ʱ����������ΪTIM2�жϺ�����Ƶ��1kHZ
  * @param  ��ʱ��ʼ������1��ʼ��0ֹͣ
  * @retval ��
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
/**
  * @brief  ������
  * @param  ֹ
  * @retval ��
  */

void draw_page3_5(uint8_t cursor) {//����������������������ƶ���ʱ��δ�ı�,����ȷ��ʱ�Ӽ�ʱ�߼�
	static uint8_t temp = 0;
	switch(cursor){
		case 1://��ʼ
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 2){MyRTC_Time[0]--;}
				else if(temp == 3){MyRTC_Time[0]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[0],4,OLED_12X24);
				OLED_Update();
				break;
		case 2://��������
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 3){MyRTC_Time[0]--;}
				else if(temp == 1){MyRTC_Time[0]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[0],4,OLED_12X24);
				OLED_Update();
				break;
		case 3://���ּ���
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 1){MyRTC_Time[0]--;}
				else if(temp == 2){MyRTC_Time[0]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[0],4,OLED_12X24);
				OLED_Update();
				break;
	}

}
/**
  * @brief  ������
  * @param  ֹ
  * @retval ��
  */
	
void draw_page3_6(uint8_t cursor) {//����������������������ƶ���ʱ��δ�ı�,����ȷ��ʱ�Ӽ�ʱ�߼�
	static uint8_t temp = 0;
	switch(cursor){
		case 1://��ʼ
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 2){MyRTC_Time[1]--;}
				else if(temp == 3){MyRTC_Time[1]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[1],2,OLED_12X24);
				OLED_Update();
				break;
		case 2://��������
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 3){MyRTC_Time[1]--;}
				else if(temp == 1){MyRTC_Time[1]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[1],2,OLED_12X24);
				OLED_Update();
				break;
		case 3://���ּ���
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 1){MyRTC_Time[1]--;}
				else if(temp == 2){MyRTC_Time[1]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[1],2,OLED_12X24);
				OLED_Update();
				break;
	}

}
/**
  * @brief  ������
  * @param  ֹ
  * @retval ��
  */

void draw_page3_7(uint8_t cursor) {//����������������������ƶ���ʱ��δ�ı�,����ȷ��ʱ�Ӽ�ʱ�߼�
	static uint8_t temp = 0;
	switch(cursor){
		case 1://��ʼ
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 2){MyRTC_Time[2]--;}
				else if(temp == 3){MyRTC_Time[2]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[2],2,OLED_12X24);
				OLED_Update();
				break;
		case 2://��������
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 3){MyRTC_Time[2]--;}
				else if(temp == 1){MyRTC_Time[2]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[2],2,OLED_12X24);
				OLED_Update();
				break;
		case 3://���ּ���
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 1){MyRTC_Time[2]--;}
				else if(temp == 2){MyRTC_Time[2]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[2],2,OLED_12X24);
				OLED_Update();
				break;
	}

}

/**
  * @brief  ʱ����
  * @param  ֹ
  * @retval ��
  */
void draw_page3_8(uint8_t cursor) {
	static uint8_t temp = 0;
	switch(cursor){
		case 1://��ʼ
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 2){MyRTC_Time[3]--;}
				else if(temp == 3){MyRTC_Time[3]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[3],2,OLED_12X24);
				OLED_Update();
				break;
		case 2://��������
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 3){MyRTC_Time[3]--;}
				else if(temp == 1){MyRTC_Time[3]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[3],2,OLED_12X24);
				OLED_Update();
				break;
		case 3://���ּ���
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 1){MyRTC_Time[3]--;}
				else if(temp == 2){MyRTC_Time[3]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[3],2,OLED_12X24);
				OLED_Update();
				break;
	}

}
/**
  * @brief  ������
  * @param  ֹ
  * @retval ��
  */
void draw_page3_9(uint8_t cursor) {//����������������������ƶ���ʱ��δ�ı�,����ȷ��ʱ�Ӽ�ʱ�߼�
	static uint8_t temp = 0;
	switch(cursor){
		case 1://��ʼ
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 2){MyRTC_Time[4]--;}
				else if(temp == 3){MyRTC_Time[4]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[4],2,OLED_12X24);
				OLED_Update();
				break;
		case 2://��������
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 3){MyRTC_Time[4]--;}
				else if(temp == 1){MyRTC_Time[4]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[4],2,OLED_12X24);
				OLED_Update();
				break;
		case 3://���ּ���
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 1){MyRTC_Time[4]--;}
				else if(temp == 2){MyRTC_Time[4]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[4],2,OLED_12X24);
				OLED_Update();
				break;
	}

}
/**
  * @brief  ������
  * @param  ֹ
  * @retval ��
  */
void draw_page3_10(uint8_t cursor) {//����������������������ƶ���ʱ��δ�ı�,����ȷ��ʱ�Ӽ�ʱ�߼�
	static uint8_t temp = 0;
	switch(cursor){
		case 1://��ʼ
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 2){MyRTC_Time[5]--;}
				else if(temp == 3){MyRTC_Time[5]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[5],2,OLED_12X24);
				OLED_Update();
				break;
		case 2://��������
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 3){MyRTC_Time[5]--;}
				else if(temp == 1){MyRTC_Time[5]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[5],2,OLED_12X24);
				OLED_Update();
				break;
		case 3://���ּ���
				OLED_Clear();
				MyRTC_ReadTime();
				if(temp == 1){MyRTC_Time[5]--;}
				else if(temp == 2){MyRTC_Time[5]++;}
				MyRTC_SetTime();
				temp = cursor;//ˢ��temp
				OLED_ShowNum(40,12,MyRTC_Time[5],2,OLED_12X24);
				OLED_Update();
				break;
	}

}

