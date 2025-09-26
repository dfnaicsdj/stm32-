#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyRTC.h"
#include "stdio.h"
#include "stdlib.h"
#include "TREE_UI.h"
// �����ҳ���������ɸ���ʵ�����������
#define MAX_CHILDREN 6

/**
  * @brief  ҳ��ڵ�ṹ�嶨�壨�������
  * @param  ��
  * @retval ��
  */
typedef struct PageNode {
    uint8_t id;                  // ҳ��ID
    uint8_t child_count;         // ��ҳ������
    void (*draw)(uint8_t cursor);// ����ҳ�溯��
    struct PageNode* children[MAX_CHILDREN]; // ��ҳ������
    struct PageNode* parent;     // ��ҳ�棨���ڷ��أ�
} PageNode;


// ȫ��״̬����
static uint8_t current_cursor = 1;    // ��ǰ���λ��
static PageNode* current_page = NULL; // ��ǰҳ��ڵ�



/**
  * @brief  ����ҳ��ڵ�
  * @param  �ڸ��ڵ�������ӽڵ��нڵ���ţ������˻ز˵�ʱ��걣��λ��
  * @param  �ڵ��UI����
  * @param  �ӽڵ������/�����
  * @retval �����Ľڵ�
  */
PageNode* create_page_node(uint8_t id, void (*draw)(uint8_t), uint8_t child_count) {
    PageNode* node = (PageNode*)malloc(sizeof(PageNode));
    if (node) {
        node->id = id;
        node->draw = draw;
        node->child_count = child_count;
        node->parent = NULL;
        // ��ʼ���ӽڵ�����
        for (uint8_t i = 0; i < child_count; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}




/**
  * @brief  ����ӽڵ�
  * @param  ���ڵ�
  * @param  �ӽڵ�
  * @param  �ӽڵ��������(��ͬһ�����ڵ��µ��������)
  * @retval ��
  */
void add_child_node(PageNode* parent, PageNode* child, uint8_t index) {
    if (parent && child && index < parent->child_count && index < MAX_CHILDREN) {
        parent->children[index] = child;
        child->parent = parent;
    }
}



/**
  * @brief  ��ʼ��ҳ����
  * @param  ��
  * @retval ��
  */
void init_page_tree(void) {
	
    // ����ҳ��ڵ�
    PageNode* page1 = create_page_node(1, draw_first_page, 2);
    PageNode* page2_1 = create_page_node(1, draw_page2_1, 4);
    PageNode* page2_2 = create_page_node(2, draw_page2_2, 6);
    
    // ����ӽڵ㲢���
    add_child_node(page1, page2_1, 0);
    add_child_node(page1, page2_2, 1);
    
    // ���������page2_1���ӽڵ�
    PageNode* page3_2 = create_page_node(2, draw_page3_2, 2);
    PageNode* page3_3 = create_page_node(3, draw_page3_3, 2);
    PageNode* page3_4 = create_page_node(4, draw_page3_4, 3);
    
    add_child_node(page2_1, page3_2, 1);    // ����1
    add_child_node(page2_1, page3_3, 2);    // ����2  
    add_child_node(page2_1, page3_4, 3);    // ����3
    
    // ���������page2_2���ӽڵ�
    PageNode* page3_5 = create_page_node(1, draw_page3_5, 3);
    PageNode* page3_6 = create_page_node(2, draw_page3_6, 3);
    PageNode* page3_7 = create_page_node(3, draw_page3_7, 3);
    PageNode* page3_8 = create_page_node(4, draw_page3_8, 3);
    PageNode* page3_9 = create_page_node(5, draw_page3_9, 3);
    PageNode* page3_10 = create_page_node(6, draw_page3_10, 3);
    
    // ȷ������ȷ�������
    add_child_node(page2_2, page3_5, 0);    // ����0
    add_child_node(page2_2, page3_6, 1);    // ����1
    add_child_node(page2_2, page3_7, 2);    // ����2
    add_child_node(page2_2, page3_8, 3);    // ����3
    add_child_node(page2_2, page3_9, 4);    // ����4
    add_child_node(page2_2, page3_10, 5);   // ����5
    
    // ���ó�ʼҳ��
    current_page = page1;
    current_page->draw(current_cursor);

}




/**
  * @brief  ����������
  * @param  ��ȡ�İ��°������
  * @retval ��
  */
void process_key(uint8_t key) {
	  if (key == 0) { // ���Ʋ���
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
				current_page->draw(current_cursor);
        }
    if (key == 1) { // ���ƹ��
        current_cursor--;
        if (current_cursor < 1) {
            current_cursor = current_page->child_count; // ѭ�������һ��
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
        current_page->draw(current_cursor);
    } else if (key == 2) { // ���ƹ��
        current_cursor++;
        if (current_cursor > current_page->child_count) {
            current_cursor = 1; // ѭ������һ��
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
        current_page->draw(current_cursor);
    } else if (key == 3) { // ȷ�Ͻ�����һ��
        // ���λ�ô�1��ʼ������������0��ʼ����Ҫ��1
        PageNode* next_page = current_page->children[current_cursor - 1];
        if (next_page) {
            current_page = next_page;
            current_cursor = 1; // ���ù��λ��
            current_page->draw(current_cursor);
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
    } else if (key == 4) { // ������һ��
        if (current_page->parent) {
						current_cursor = current_page->id;//������һҳ��Ĺ��λ��
            current_page = current_page->parent;
            current_page->draw(current_cursor);
        }
				OLED_Printf(70,0,OLED_6X8,"cursor:%d",current_cursor);
				OLED_Update();
    }
}
