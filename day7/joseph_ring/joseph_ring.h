#ifndef joseph_ring_h__
#define joseph_ring_h__
#include<stdio.h>
#include<stdlib.h>

#define JOP_NUM 8

typedef struct josephring {
	int data;
	struct josephring* next;
}jospher_st;
//����
jospher_st* josp_creat(int);
//��ʾ����
void josp_show(jospher_st*);
//������ɾ��
int josp_delete(jospher_st**,int);
//��������
void josp_destory(jospher_st*);

#endif // !joseph_ring_h__
