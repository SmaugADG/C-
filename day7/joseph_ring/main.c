#include"joseph_ring.h"
/**
*Լɪ��---��ѭ����
*/
int main() {
	int n;
	jospher_st* list;
	list = josp_creat(JOP_NUM);
	if(list==NULL){
		exit(-1);
	}

	josp_show(list);
	scanf("%d",&n);
	josp_delete(&list,n);

	josp_show(list);
	josp_destory(list);
	exit(0);
}