#include<stdio.h>
#include<stdlib.h>

int main() {
	const float pi = 3.14;

//	pi = 3.1415;     //error�������޸�
	
	float* p = &pi;
	*p = 3.1415;   //�������

	exit(0);
}