#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
//������
//
/**
*title:���Ը�32λ�޷������ĸ�ʮ��λ�͵�ʮ��λ���
*/
union test_un {
	struct {
		uint16_t i;
		uint16_t j;
	}x;
	uint32_t y;
}a;


int main() {
	//����һ��ʹ��λ����
	//uint32_t i = 0x11223344; //uint32_t����һ��32λ�޷�����
	//printf("%x",(i>>16)+i&0xffff);

	//��������ʹ�ù�����
	a.y = 0x11223344;
	printf("%x",a.x.i+a.x.j);

	exit(0);
}