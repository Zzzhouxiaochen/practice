#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


int Lujing(int a, int b) {
	if (a>1&&b>1) {
		//������1�����
		return Lujing(a - 1, b) + Lujing(a, b - 1);//�ݹ�
	}
	else if ((a==1)||(b==1)) {
		//��һ������1
		return a + b;
	}
	else {	//Ϊ0�����
		return 0;
	}
}

int main() {
	int a, b;
	int result = Lujing(a, b);
	while (cin>>a>>b) {
		cout << result << endl;
	}
	system("pause");
	return 0;
}