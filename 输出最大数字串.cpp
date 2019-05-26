#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
#define  _CRT_SECURE_NO_WARNINGS

int main() {

	int i = 0, j = 0, k = 0;
	char b[1024];
	char c[1024];
	char a[] = { 0 };
	cout << "请输入字符串：" << endl;
	cin >> a ;

	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] >= '0'&&a[i] <= '9') {
			b[j++] = a[i];
		}
		else {
			b[j] = '\0';
			if (j > k) { 
				k = j;
				strcpy_s(c, b);
			}
			j = 0;
		}
	}
	printf("最大数字：[%s]\n", c);
	system("pause");
	return 0;
}