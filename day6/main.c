#include"sqlist.h"
/**
*���Ա�˳��洢
*/
int main() {
	int i,ret,k;
	datatype arr[] = {1,2,5,3,7,6};
	sqlist* list=NULL;
//	list = sqlist_create(list); //ʹ��������ͬ�ķ�������ʼ��
	sqlist_create1(&list);
	if (list==NULL) {
		fprintf(stderr,"sqlist_create() fail!");
		exit(1);
	}

	//��ʼ����������
	sqlist_cycinsert(list,0, sizeof(arr) / sizeof(arr[0]),arr);
	sqlist_display(list);

	//��λ��ɾ��
	scanf("%d",&k);
	ret = sqlist_delete(list,k);
	if (ret==-1) {
		fprintf(stderr,"Error site!");
	}
	sqlist_display(list);

	//��ֵ����
	scanf("%d",&k);
	ret = (sqlist_find(list,&k));
	if (ret==-1) {
		fprintf(stderr,"no such member!\n");
	}
	else {
		printf("site is :%d",ret);
	}


/*
*ʵ������list�ϲ�
*/

	//����list2
	datatype arr2[] = { 2,8,9,0,11,12 };
	sqlist* list2 = NULL;
	sqlist_create1(&list2);

	sqlist_cycinsert(list2,0,sizeof(arr2)/sizeof(arr2[0]),arr2);

	sqlist_display(list2);
	//�ϲ�
	ret = sqlist_union(list,list2);
	if (ret!=-1) {
		sqlist_display(list);
	}
	//����
	sqlist_destory(list);
	sqlist_destory(list2);
	list = NULL;
	list2 = NULL;

	exit(0);
}