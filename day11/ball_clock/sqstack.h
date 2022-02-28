#ifndef sqstack_h__
#define sqstack_h__
#include<stdio.h>
#include<stdlib.h>

#define SIZE 32

typedef int type;

typedef struct{
	type data[SIZE];
	int top;
}sqstack;
//����
sqstack* st_create(void);
//�п�
int st_isempty(sqstack*);
//��ջ
int st_push(sqstack*,type*);
//��ջ
int st_pop(sqstack*,type*);
//ȡջ��
int st_top(sqstack*,type*);
//����
void st_travel(sqstack*);
//����
void st_destory(sqstack*);

#endif // !sqstack_h__
