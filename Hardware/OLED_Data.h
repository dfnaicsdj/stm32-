#ifndef __OLED_DATA_H_
#define __OLED_DATA_H_

#include <stdint.h>

/*�ַ�������*/
/*���������궨��ֻ�ɽ������һ����ע��*/
//#define OLED_CHARSET_UTF8			//�����ַ���ΪUTF8
#define OLED_CHARSET_GB2312		//�����ַ���ΪGB2312

/*��ģ������Ԫ*/
typedef struct 
{
	
#ifdef OLED_CHARSET_UTF8			//�����ַ���ΪUTF8
	char Index[5];					//�����������ռ�Ϊ5�ֽ�
#endif
	
#ifdef OLED_CHARSET_GB2312			//�����ַ���ΪGB2312
	char Index[3];					//�����������ռ�Ϊ3�ֽ�
#endif
	
	uint8_t Data[32];				//��ģ����
} ChineseCell_t;

/*ASCII��ģ��������*/
extern const uint8_t OLED_F8x16[][16];
extern const uint8_t OLED_F6x8[][6];
extern const uint8_t OLED_F12x24[][36];
/*������ģ��������*/
extern const ChineseCell_t OLED_CF16x16[];

/*ͼ����������*/
extern const uint8_t Diode[];
/*��������ĸ�ʽ�������λ�ü����µ�ͼ����������*/
//...
extern uint8_t phone[];
extern uint8_t mpu[];
extern uint8_t dragon[];
extern uint8_t stopwatch[];
extern uint8_t larrow[];
extern uint8_t rarrow[];
extern uint8_t Ground[];
extern uint8_t Barrier[][48];
extern uint8_t Cloud[];
extern uint8_t Dino[][48];
extern uint8_t rarrow8[];
#endif


/*****************��Э�Ƽ�|��Ȩ����****************/
/*****************jiangxiekeji.com*****************/
