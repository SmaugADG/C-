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
	void* data;
	struct dllist_node_st* prev;
	struct dllist_node_st* next;
}list_node;

typedef struct {
	int size;
	struct dllist_node_st head;
}LLIST;

//��������
LLIST *dllist_create(int initsize);
//����
int dllist_insert(LLIST*,const void* data,int mod);
//����(������)
void *dllist_find(LLIST*,const void *key, dllinst_cmp*);
//ɾ��
int dllist_delete(LLIST*,const void *key,dllinst_cmp*);
//��ȡԪ��
int dllist_fetch(LLIST*,const void* key,dllinst_cmp*,void* data);
//����
void dllist_travel(LLIST*,dllist_op*);
//����
void dllist_destory(LLIST*);

#endif // !dllist_h__
