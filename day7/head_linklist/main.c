#include"linklist.h"
/**
*��ͷ�ڵ㵥����
*/

int main() {
	int ret,k;
	datatype arr[] = {3,4,7,9,0,1,2,5};
	linklist* list = NULL;
	//��������
	list=list_create();
	ret=list_cycinsert(list,0,sizeof(arr)/sizeof(arr[0]),arr);
	
	if (ret < 0) {
		fprintf(stderr,"error parameter!\n");//�����Ƿ�
	}
	list_display(list);
	//��ֵɾ��
	scanf("%d",&k);
	ret=list_delete(list,&k);
	if (ret==-1) {
		fprintf(stderr,"no such value!\n");
	}
	list_display(list);
	//��λ��ɾ��
	list_delete_at(list,3,&ret);
	printf("%d \n",ret);
	list_display(list);

	list_destory(list);
	exit(0);
}