#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p = NULL;
	p = malloc(sizeof(int));
	if (p==NULL) {
		exit(1);
	}
	*p = 10;
	printf("%p-->%d\n",p,*p);
	free(p);
	p = NULL;//��ʱ�ÿ�
	/**p = 13;
	printf("%p-->%d\n",p,*p);*/ //p���ÿջ���Ұָ�룬�ٴθ�ֵ��������ش���
	exit(0);
}