#ifndef polynomial_h__
#define polynomial_h__
#include<stdio.h>
#include<stdlib.h>
typedef struct poly_node_st {
	int coef;
	int exp;
	struct poly_node_st* next;

}poly_st;
//��������ʹ��ͷ�ڵ�
poly_st* poly_create(int arr[][2],int i);
//��ӡ����
void poly_show(poly_st*);
//�ϲ�
int poly_union(poly_st*,poly_st*);
//����
void pol_destory(poly_st*);
#endif // !polynomial_h__
