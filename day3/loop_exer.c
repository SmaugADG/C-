#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
*Title:A��10%����Ͷ��100����B��5%�ĸ���Ͷ��100��
*��̣���Ҫ���B�ܹ�����A�����棬��Ŀǰ������Ϊ����
*/
static void rates() {
	double fund = 100, rate_a = 0.1, rate_b = 0.05;
	double sum_a=0.0, sum_b=0.0 ,t=1.0;
	while (1) {
		sum_a = fund * rate_a * t;
		sum_b = fund * pow((1 + rate_b), t) - fund;
		t++;
		if (sum_a-sum_b>=-1e-7&&sum_a-sum_b<=1e-7) {
			break;
		}
	}
	printf("sum=%lf,T=%lf",sum_a,t);
}

/*
*Title:���ն��������֣����ż���ĸ����Լ�ƽ��ֵ�������ĸ����Լ�ƽ��ֵ
*/
void eo_num() {
	int arr[10] = { 0 };
	int num=0,i=0,j=0,sum_eve=0,count=0,sum_old=0;
	printf("Input number:\n");
	while (scanf("%d",&num)!=EOF) {
		arr[i] = num;
		i++;
	}
	num = sizeof(arr) / sizeof(int);
	for (j = 0; j <= num;j++) {
		if (arr[j] % 2 == 0) {
			sum_eve += arr[j];
			count++;
		}
		else {
			sum_old += arr[j];
		}
	}
	printf("even_num=%d,even_avg=%d\n",count,sum_eve/count);
	printf("old_num=%d,old_avg=%d\n",num-count,sum_old/(num-count));
}

/**
*Title�����ն�����������ĸ�������е�Ԫ����ĸ����ͳ��
*/

/*
*title�����쳲����������е�ǰ40��
*쳲�����:1,1,2,3,5,8,13...
*/
void fib() {
	int i = 1, j = 1, count = 0;
	while (count<40) {
		printf("%d ",i);

		count++;
	}
	
}

/**
*title:����žų˷���
*/
void mul_tab() {
	
	for (int i = 1; i <= 9;i++) {
		for (int j = i; j <= 9;j++) {
			printf("%d*%d=%d	",i,j,i*j);
		}
		printf("\n");
	}

}


/**
*title����Ǯ��ټ�������һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ����ʼ��̣���ĸ������������
*/

/**
*title:���1000���ڵ�ˮ�ɻ���
*ˮ�ɻ�����
*/

/**
*title:���1000���ڵ�����
*/

/**
*title:�������Ķ�����
*ABCDEF
*BCDEF
*CDEF
*DEF
*EF
*F
*/
void print() {
	char arr[6] = { 'A','B','C','D','E','F' };
	int i , j;
	for (j = 0; j < 6;j++) {
		for (i = j; i < 6;i++) {
			printf("%c",arr[i]);
		}
		printf("\n");
	}

}

int main() {
	//rates();
	//eo_num();
	//print();
	//mul_tab();
	fib(40);
	exit(0);
}