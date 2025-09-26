#ifndef _DINO_H_
#define _DINO_H_
struct object_position{
	uint8_t x_min;
	uint8_t x_max;
	uint8_t y_min;
	uint8_t y_max;
};
void show_score(void);
void dino_tick(void);
void show_ground(void);
void show_barrier(void);
void show_cloud(void);
void show_dino(uint8_t flag);
int isColliding(struct object_position *a,struct object_position *b);//1Åö×²£¬0¼ÌÐø
void game_init(void);
extern uint8_t dino_jump_flag;
extern struct object_position dino;
extern struct object_position barrier;
#endif
