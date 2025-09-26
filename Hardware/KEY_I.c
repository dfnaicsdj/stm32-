#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "TREE.h"
void Key_operation(int operation);
	
void key_I_INIT(void){
		
		GPIO_InitTypeDef gpio; //��ʼ��������GPIO�ṹ��

	
	//����GPIO
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//����GPIOAʱ��

	
	
		//����PA3
		gpio.GPIO_Pin = GPIO_Pin_3;//��GPIO��������ΪPA3
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//����ģʽ����������
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//�����ٶȣ�50Mhz
		GPIO_Init(GPIOA, &gpio);//���ṹ���е�����д���Ӧ��GPIOA�Ĵ���
	
	//����PA4
		gpio.GPIO_Pin = GPIO_Pin_4;//��GPIO��������ΪPA4
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//����ģʽ����������
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//�����ٶȣ�50Mhz
		GPIO_Init(GPIOA, &gpio);//���ṹ���е�����д���Ӧ��GPIOA�Ĵ���
	
	//����PA5
		gpio.GPIO_Pin = GPIO_Pin_5;//��GPIO��������ΪPA5
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//����ģʽ����������
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//�����ٶȣ�50Mhz	
		GPIO_Init(GPIOA, &gpio);//���ṹ���е�����д���Ӧ��GPIOA�Ĵ���
		
			//����PA6
		gpio.GPIO_Pin = GPIO_Pin_6;//��GPIO��������ΪPA5
	  gpio.GPIO_Mode = GPIO_Mode_IPU;//����ģʽ����������
		gpio.GPIO_Speed = GPIO_Speed_50MHz;//�����ٶȣ�50Mhz	
		GPIO_Init(GPIOA, &gpio);//���ṹ���е�����д���Ӧ��GPIOA�Ĵ���
	
}

/**
  * @brief  ��ⰴ���Ƿ���
  * @param  ������
  * @retval �а������£�flag=1����֮Ϊ0
  */
uint8_t key_GetFlag(uint16_t GPIO_Pin){
	uint8_t flag = 0;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin) == 0){//��⵽��������
		Delay_ms(10);//����
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin) == 0){
		flag = 1;//ȷ�ϰ�������
		//while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin) == 0){}//����̧���˳�ѭ��
		//Delay_ms(10);		
		}
	}
	return flag;
}

/**
  * @brief  ��ⰴ���Ƿ��µ���ת����
  * @param  ��
  * @retval ��
  */

void Key_press(void){
	if (key_GetFlag(GPIO_Pin_3) == 1){
		process_key(2);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3) == 0){process_key(0);}//����̧���˳�ѭ��
			}//�Ҽ����++
	else if (key_GetFlag(GPIO_Pin_4) == 1){
		process_key(1);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4) == 0){process_key(0);}//����̧���˳�ѭ��
	}//������--
	else if (key_GetFlag(GPIO_Pin_5) == 1){
		process_key(3);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5) == 0){process_key(0);}//����̧���˳�ѭ��
	}
	else if (key_GetFlag(GPIO_Pin_6) == 1){
		process_key(4);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6) == 0){process_key(0);}//����̧���˳�ѭ��
	}
	else{process_key(0);}//û�в���������ҳ���͹�꣬ˢ��ʱ��

}
/*
void Key_press(void){
	if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)==0){process_key(2);}//�Ҽ����++
	else if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0){process_key(1);}//������--
	else if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0){process_key(3);}
	else if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0){process_key(4);}
	else{process_key(0);}//û�в���������ҳ���͹�꣬ˢ��ʱ��

}*/



int8_t key_flag = 0;//��ʼ��־λΪ0�����λ��0λ��
uint8_t page = 1;//��ʼҳ��Ϊ1

/**״̬��ʵ��ҳ���л��ĺ�����Ŀǰ���ڶ�����л����˺�������
  * @brief  ���°�����Ĳ�������
  * @param  ��������
  * @retval ��
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
