#include<stdio.h>
#include<stdlib.h>
/**
*ָ�����ά����
*/
int main() {
	int a[2][3] = {1,2,3,4,5,6};
	int i, j;
	int(*p)[3] = a;	//a��p���Ի���ʹ�ã�Ψһ�������p�Ǳ�����a�ǳ���

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3;j++) {
			printf("%p-->%d\n",&p[i][j],p[i][j]);
		}
		printf("\n");
	}


	exit(0);
}