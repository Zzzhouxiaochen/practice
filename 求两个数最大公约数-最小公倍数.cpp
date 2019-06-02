#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main() {

	int a = 0, b = 0;
	scanf("%d %d",&a,&b);
	int temp;
	int i = 0;
	//求最大公约数
	if (a > b) {
		temp = b;
	}
	else {
		temp = a;
	}
	for (i = temp; i >= 1;i--) {
		if ((a%i==0)&&(b%i==0)) {
			printf("最大公约数：%d\n", i);
			break;
		}
	}
	int gy = a*b / i;
	printf("最大公倍数：%d", gy);
	system("pause");
	return 0;
}