#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]) {
	int i;
	printf("%d",argc);
	for (i = 0; i < argc;i++) {
		puts(argv[i]); //����˵�ǰ���������
	}

	return 0;
}