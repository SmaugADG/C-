#include<stdio.h>
#include<stdlib.h>
/**
*�������:addr%sizeof(int),
*�����ĵ�ǰ��ַ�����������ȡ��,
*�������Ϊ0�ʹ���,
*���������Ϊ0,addr++,Ȼ����ȡ��,ֱ������Ϊ0
*/
struct simp_st {
	int i;
	char ch;
	float f;
	char ch1;
};
int main() {
	struct simp_st simp;
	printf("%d\n",sizeof(simp));
	exit(0);
}