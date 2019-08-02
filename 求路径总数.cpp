#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


int Lujing(int a, int b) {
	if (a>1&&b>1) {
		//都大于1的情况
		return Lujing(a - 1, b) + Lujing(a, b - 1);//递归
	}
	else if ((a==1)||(b==1)) {
		//有一个等于1
		return a + b;
	}
	else {	//为0的情况
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