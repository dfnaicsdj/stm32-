#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "OLED_Data.h"
#include <stdlib.h>
#include <math.h>
#include "Delay.h"

struct object_position{
	uint8_t x_min;
	uint8_t x_max;
	uint8_t y_min;
	uint8_t y_max;
};
	
	
int score;
void show_score(void){
	OLED_ShowNum(95,0,score,5,OLED_6X8);
}

uint8_t ground_pose;//gorund背景移动的距离
void show_ground(void){
	if (ground_pose<128){
		for(uint8_t i = 0;i<128;i++){
			OLED_DisplayBuf[7][i] = Ground[ground_pose + i];}
		}
	else{
		for(uint8_t i =0 ;i<256-ground_pose;i++){
			OLED_DisplayBuf[7][i] = Ground[ground_pose + i];
		}
		for(uint8_t i =0 ;i<ground_pose-128;i++){
			OLED_DisplayBuf[7][i+256-ground_pose] = Ground[i];
		}				
	}

}
uint8_t barrier_flag,barrier_pose;
struct object_position barrier;
void show_barrier(void){
	if(barrier_pose == 144)	barrier_flag = rand()%3;
	OLED_ShowImage(127-barrier_pose,45,16,18,Barrier[barrier_flag]);
	barrier.x_min=127-barrier_pose;
	barrier.x_max=143-barrier_pose;
	barrier.y_min=45;
	barrier.y_max=63;
}
uint8_t cloud_pose;
void show_cloud(void){
	OLED_ShowImage(127-cloud_pose,9,16,8,Cloud);
}


uint8_t dino_jump_flag,jump_pose;
uint16_t jump_t;
struct object_position dino;
void show_dino(uint8_t flag)
{	
	dino_jump_flag = flag;
	if(dino_jump_flag==1){
		jump_pose=28*sin((float)(3.1415926*jump_t/1000));
		OLED_ShowImage(0,45-jump_pose,16,18,Dino[2]);
	}
	else if(dino_jump_flag==0)
	{
		if(cloud_pose%2==0)OLED_ShowImage(0,45,16,18,Dino[0]);
		else OLED_ShowImage(0,45,16,18,Dino[1]);
	}
	dino.x_max=16;
	dino.x_min=0;
	dino.y_min=44-jump_pose;
	dino.y_max=63-jump_pose;
	
}

int isColliding(struct object_position *a,struct object_position *b){//判断碰撞函数
	if(a->x_max>b->x_min&&a->x_min<b->x_max&&a->y_max>b->y_min&&a->y_min<b->y_max){
		return 1;
	}
	else{return 0;}
}

void game_init(void){
	score=barrier_pose=ground_pose=cloud_pose=jump_pose=0;
}
//中断函数
void dino_tick(void){
	static uint8_t score_count;
	static uint8_t	ground_count;
	static uint8_t	barrier_count;
	static uint8_t	cloud_count;
	score_count++;
	ground_count++;
	barrier_count++;
	cloud_count++;
	if(score_count > 99){//0.1s刷新
		score_count = 0;
		score++;
	}
	if(ground_count > 20){//20毫秒刷新
		ground_count = 0;
		if(ground_pose <= 255){ground_pose++;}
		else{ground_pose = 0;}
	}
	if(barrier_count > 20){//20毫秒刷新
		barrier_count=0;
		if(barrier_pose <= 144){barrier_pose++;}
		else{barrier_pose = 0;}
	}
	if(cloud_count > 40){//40毫秒刷新
		cloud_count=0;
		if(cloud_pose <= 144){cloud_pose++;}
		else{cloud_pose = 0;}
	}
	if(dino_jump_flag==1){
		jump_t++;
		if(jump_t>=1000){//跳跃到落地耗时1s
			jump_t = 0;
			dino_jump_flag = 0;
		}
	}
}
