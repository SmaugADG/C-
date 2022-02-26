#ifndef sqstack_h__
#define sqstack_h__
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef int datatype;

typedef struct node_st{
	datatype data[MAXSIZE];
	int top;
}sqstack;
//����
sqstack* st_create(void);
//�п�
int st_isempty(sqstack*);
//��ջ
int st_push(sqstack*,datatype*);
//��ջ
int st_pop(sqstack*,datatype*);
//ȡջ��
int st_top(sqstack*,datatype*);
//����
void st_travel(sqstack*);
//����
void st_destory(sqstack*);

#endif // !sqstack_h__
