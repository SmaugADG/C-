#ifndef lnstack_h__
#define lnstack_h__
#include<stdio.h>
#include<stdlib.h>
#include"dllist.h"
typedef LLIST STACK;
STACK* stack_create(int);//����
int stack_push(STACK*,void* data);//��ջ
int stack_pop(STACK*,void* data);//��ջ
void stack_destory(STACK*);//����
#endif // !lnstack_h__

