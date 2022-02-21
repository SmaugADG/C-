#ifndef sqlist_h__
#define sqlist_h__
#include<stdio.h>
#include<stdlib.h>

#define DATASIZE 1024

typedef int datatype;

typedef struct node_st{
	datatype data[DATASIZE];
	int last;
}sqlist;

//����
sqlist *sqlist_create();
void sqlist_create1(sqlist **);
//����
int sqlist_destory(sqlist*);
//����
int sqlist_insert(sqlist* ,int i,datatype*);
//ѭ������
int sqlist_cycinsert(sqlist*,int i, int size,datatype*);
//ɾ��(��λ��)
int sqlist_delete(sqlist* ,const int i);
//���ң���ֵ���ң�
int sqlist_find(sqlist*,datatype*);
//�п�
int sqlist_isempty(sqlist*);
//�ÿ�
int sqlist_setempty(sqlist*);
//��ȡԪ�ظ���
int sqlist_getnum(sqlist*);
//�ϲ�
int sqlist_union(sqlist*,sqlist*);
//����
void sqlist_display(sqlist*);

#endif
