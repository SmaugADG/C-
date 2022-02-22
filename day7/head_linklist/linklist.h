#ifndef linklist_h__
#define linklist_h__
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;

typedef struct node_st{
	datatype data;
	struct node_st* next;

}linklist;
//�����б�
linklist* list_create();
//��λ�ò���
int list_insert_at(linklist*,int i,datatype*);
//ѭ������
int list_cycinsert(linklist*,int i,int size,datatype*);
//�������
int list_order_insert(linklist*,datatype*);
//��λ��ɾ��
int list_delete_at(linklist*,int i,datatype*);
//�������
int list_delete(linklist*,datatype*);
//��ӡ����
void list_display(linklist*);
//��������
void list_destory(linklist*);
//�п�
int list_isempty(linklist*);



#endif // !_linklist_h__
