#ifndef dllist_h__
#define dllist_h__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LLIST_FORWARD 1 //ͷ�巨
#define LLIST_BACKWORD 2 //β�巨

typedef void dllist_op(const void *);//�ص�����
typedef int  dllinst_cmp(const void *,const void *);//�ص�����

typedef struct dllist_node_st {
	struct dllist_node_st* prev;
	struct dllist_node_st* next;
	char data[1];//C99��׼����Ϊ0��֮ǰ�İ汾����Ϊ0
}list_node;

typedef struct linklist_st{
	int size;
	struct dllist_node_st head;
	int (*insert)(struct linklist_st*, const void* data, int mod);//����
	void* (*find)(struct linklist_st*, const void* key, dllinst_cmp*);//����
	int (*delete)(struct linklist_st*, const void* key, dllinst_cmp*);//ɾ��
	int (*fetch)(struct linklist_st*, const void* key, dllinst_cmp*, void* data);//��ȡԪ��
	void (*travel)(struct linklist_st*, dllist_op*);//����
	void (*destory)(struct linklist_st*);//����
}LLIST;

//��������
LLIST *dllist_create(int initsize);
#endif // !dllist_h__
