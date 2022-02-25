#ifndef queue_h__
#define queue_h__
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 6
typedef int datatype;
typedef struct node_st{
	datatype data[MAXSIZE];
	int head, tail;
}Queue;

//����
Queue* queue_create();
//�п�
int queue_isempty(Queue*);
//���
int queue_enqueue(Queue*,datatype*);
//����
int queue_dequeue(Queue*,datatype*);
//����
void queue_travel(Queue*);
//���
void queue_clear(Queue*);
//����
void queue_destory(Queue*);

#endif // !queue_h__
