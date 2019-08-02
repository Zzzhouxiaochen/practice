#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <vector>
using namespace std;

bool JingZi(vector<vector<int> > board) {
	int a = board.size();	//确定行列数
	int sum = 0;
	int i, j;
	//判断行总和是不是a
	for (int i=0; i < a;i++) {
		sum = 0;
		for (j = 0; j < a;j++){	//求和
			sum += board[i][j];
		}
		if (sum==a) {
			return true;
		}
	}
	//判断列总和是不是a
	for (int i = 0; i < a; i++) {
		sum = 0;
		for (j = 0; j < a; j++){	//求和
			sum += board[j][i];
		}
		if (sum == a) {
			return true;
		}
	}
	//判断对角线
	//对角线有两个正对角线和副对角线，这拿三行三列距离，数字是数组下标
	//正对角线：0.0   1.1   2.2  数值的变化是每个都加1
	//副对角线：0.2     1.1		2.0	很明显数值的变化是不一样的 

	//正对角线的判断
	for (i = 0; i < a;i++) {
		sum = 0;
		sum += board[i][i];
	}
	if (sum == a) {
		return true;
	}
	//副对角线的判断
	for (i = 0; i < a;i++) {
		sum = 0;
		sum += board[i][a - i-1];
	}
	if (sum == a) {
		return true;
	}
	return false;
}
