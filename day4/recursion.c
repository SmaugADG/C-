#include<stdio.h>
#include<stdlib.h>
//�ݹ���׳�
int factorial(int n) {
	if (n>1) {
	
	return n * fun(n - 1);
	}
	else {
		return 1;
	}

}
//�ݹ���fib
int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n-2);

}

int main() {

	printf("%d",fib(10));
	printf("%d", factorial(10));
	return 0;
}