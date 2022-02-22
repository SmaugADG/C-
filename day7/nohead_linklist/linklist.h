#ifndef linklist_h__
#define linklist_h__
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NAMESIZE 32


typedef struct score_st {
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}score;
typedef struct node_st {
	struct score_st data;
	struct node_st* next;
}head_linklist;

typedef int datatype;
//����
int list_insert(head_linklist**,score*);
//ѭ������
int list_cycinsert(head_linklist*);
//��ӡ����
void list_show(head_linklist*);
//ɾ��
int list_delete(head_linklist **);
//����(id)
score* list_find(head_linklist*,int);
//����
void list_destory(head_linklist*);


#endif // !linklist_h__
