#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "MyRTC.h"
#include "stdio.h"
#include "stdlib.h"
#include "TREE_UI.h"
// �����ҳ���������ɸ���ʵ�����������
#define MAX_CHILDREN 10

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
  * @param  �ӽڵ������
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
        for (uint8_t i = 0; i < MAX_CHILDREN; i++) {
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
    // ������ҳ�棨ʾ����

    
    // ������һҳ��һ���ڵ㣬�����ӽڵ�.1
    PageNode* page1 = create_page_node(1, draw_first_page, 2);
	  //�ڶ���ĵ�һ���ڵ㣺2-1
	  PageNode* page2_1 = create_page_node(1, draw_page2_1, 4); // 4��Ů
		//�ڶ���ĵڶ����ڵ㣺2-2
    PageNode* page2_2 = create_page_node(2, draw_page2_2, 0); // 0����ҳ��
		//�ڵ�1����ӽڵ�
    add_child_node(page1, page2_1, 0); // ��һ���ӽڵ�
    add_child_node(page1, page2_2, 1); // �ڶ����ӽڵ�
    /*
    // ����2-1��4���ӽڵ�
    //3-1
		PageNode* page3_1 = create_page_node(1, draw_page3_1, 0);
		add_child_node(page2_1, page3_1, 0);
		//3-2
		PageNode* page3_2 = create_page_node(2, draw_page3_2, 0);
		add_child_node(page2_1, page3_2, 1);	
		//3-3
		PageNode* page3_3 = create_page_node(3, draw_page3_3, 0);
		add_child_node(page2_1, page3_3, 2);*/
		//3-4stopwatch
		PageNode* page3_4 = create_page_node(4, draw_page3_4, 3);
		//�͸��ڵ�����
		add_child_node(page2_1, page3_4, 3);
		/*PageNode* page3_4_1 = create_page_node(1, draw_page3_4_1, 0);
		PageNode* page3_4_2 = create_page_node(2, draw_page3_4_2, 0);
		PageNode* page3_4_3 = create_page_node(3, draw_page3_4_3, 0);
		add_child_node(page3_4, page3_4_1, 0);
		add_child_node(page3_4, page3_4_2, 1);
		add_child_node(page3_4, page3_4_3, 2);*/
    
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
				current_page->draw(current_cursor);
        }
    if (key == 1) { // ���ƹ��
        current_cursor--;
        if (current_cursor < 1) {
            current_cursor = current_page->child_count; // ѭ�������һ��
        }
        current_page->draw(current_cursor);
    } else if (key == 2) { // ���ƹ��
        current_cursor++;
        if (current_cursor > current_page->child_count) {
            current_cursor = 1; // ѭ������һ��
        }
        current_page->draw(current_cursor);
    } else if (key == 3) { // ȷ�Ͻ�����һ��
        // ���λ�ô�1��ʼ������������0��ʼ����Ҫ��1
        PageNode* next_page = current_page->children[current_cursor - 1];
        if (next_page) {
            current_page = next_page;
            current_cursor = 1; // ���ù��λ��
            current_page->draw(current_cursor);
        }
    } else if (key == 4) { // ������һ��
        if (current_page->parent) {
						current_cursor = current_page->id;//������һҳ��Ĺ��λ��
            current_page = current_page->parent;
            current_page->draw(current_cursor);
        }
    }
}
