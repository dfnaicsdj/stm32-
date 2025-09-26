#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyRTC.h"
#include "stdio.h"
#include "stdlib.h"
#include "TREE_UI.h"
// 最大子页面数量（可根据实际需求调整）
#define MAX_CHILDREN 6

/**
  * @brief  页面节点结构体定义（多叉树）
  * @param  无
  * @retval 无
  */
typedef struct PageNode {
    uint8_t id;                  // 页面ID
    uint8_t child_count;         // 子页面数量
    void (*draw)(uint8_t cursor);// 绘制页面函数
    struct PageNode* children[MAX_CHILDREN]; // 子页面数组
    struct PageNode* parent;     // 父页面（用于返回）
} PageNode;


// 全局状态变量
static uint8_t current_cursor = 1;    // 当前光标位置
static PageNode* current_page = NULL; // 当前页面节点



/**
  * @brief  创建页面节点
  * @param  在父节点的所有子节点中节点序号，方便退回菜单时光标保持位置
  * @param  节点的UI函数
  * @param  子节点的总数/光标数
  * @retval 创建的节点
  */
PageNode* create_page_node(uint8_t id, void (*draw)(uint8_t), uint8_t child_count) {
    PageNode* node = (PageNode*)malloc(sizeof(PageNode));
    if (node) {
        node->id = id;
        node->draw = draw;
        node->child_count = child_count;
        node->parent = NULL;
        // 初始化子节点数组
        for (uint8_t i = 0; i < child_count; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}




/**
  * @brief  添加子节点
  * @param  父节点
  * @param  子节点
  * @param  子节点的索引号(在同一个父节点下的相对索引)
  * @retval 无
  */
void add_child_node(PageNode* parent, PageNode* child, uint8_t index) {
    if (parent && child && index < parent->child_count && index < MAX_CHILDREN) {
        parent->children[index] = child;
        child->parent = parent;
    }
}



/**
  * @brief  初始化页面树
  * @param  无
  * @retval 无
  */
void init_page_tree(void) {
	
    // 创建页面节点
    PageNode* page1 = create_page_node(1, draw_first_page, 2);
    PageNode* page2_1 = create_page_node(1, draw_page2_1, 4);
    PageNode* page2_2 = create_page_node(2, draw_page2_2, 6);
    
    // 添加子节点并检查
    add_child_node(page1, page2_1, 0);
    add_child_node(page1, page2_2, 1);
    
    // 创建并添加page2_1的子节点
    PageNode* page3_2 = create_page_node(2, draw_page3_2, 2);
    PageNode* page3_3 = create_page_node(3, draw_page3_3, 2);
    PageNode* page3_4 = create_page_node(4, draw_page3_4, 3);
    
    add_child_node(page2_1, page3_2, 1);    // 索引1
    add_child_node(page2_1, page3_3, 2);    // 索引2  
    add_child_node(page2_1, page3_4, 3);    // 索引3
    
    // 创建并添加page2_2的子节点
    PageNode* page3_5 = create_page_node(1, draw_page3_5, 3);
    PageNode* page3_6 = create_page_node(2, draw_page3_6, 3);
    PageNode* page3_7 = create_page_node(3, draw_page3_7, 3);
    PageNode* page3_8 = create_page_node(4, draw_page3_8, 3);
    PageNode* page3_9 = create_page_node(5, draw_page3_9, 3);
    PageNode* page3_10 = create_page_node(6, draw_page3_10, 3);
    
    // 确保按正确索引添加
    add_child_node(page2_2, page3_5, 0);    // 索引0
    add_child_node(page2_2, page3_6, 1);    // 索引1
    add_child_node(page2_2, page3_7, 2);    // 索引2
    add_child_node(page2_2, page3_8, 3);    // 索引3
    add_child_node(page2_2, page3_9, 4);    // 索引4
    add_child_node(page2_2, page3_10, 5);   // 索引5
    
    // 设置初始页面
    current_page = page1;
    current_page->draw(current_cursor);

}




/**
  * @brief  处理按键输入
  * @param  读取的按下按键序号
  * @retval 无
  */
void process_key(uint8_t key) {
	  if (key == 0) { // 上移不动
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
				current_page->draw(current_cursor);
        }
    if (key == 1) { // 上移光标
        current_cursor--;
        if (current_cursor < 1) {
            current_cursor = current_page->child_count; // 循环到最后一项
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
        current_page->draw(current_cursor);
    } else if (key == 2) { // 下移光标
        current_cursor++;
        if (current_cursor > current_page->child_count) {
            current_cursor = 1; // 循环到第一项
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
        current_page->draw(current_cursor);
    } else if (key == 3) { // 确认进入下一级
        // 光标位置从1开始，数组索引从0开始，需要减1
        PageNode* next_page = current_page->children[current_cursor - 1];
        if (next_page) {
            current_page = next_page;
            current_cursor = 1; // 重置光标位置
            current_page->draw(current_cursor);
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
    } else if (key == 4) { // 返回上一级
        if (current_page->parent) {
						current_cursor = current_page->id;//保持上一页面的光标位置
            current_page = current_page->parent;
            current_page->draw(current_cursor);
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
    }
}
