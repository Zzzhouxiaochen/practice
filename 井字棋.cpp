#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <vector>
using namespace std;

bool JingZi(vector<vector<int> > board) {
	int a = board.size();	//ȷ��������
	int sum = 0;
	int i, j;
	//�ж����ܺ��ǲ���a
	for (int i=0; i < a;i++) {
		sum = 0;
		for (j = 0; j < a;j++){	//���
			sum += board[i][j];
		}
		if (sum==a) {
			return true;
		}
	}
	//�ж����ܺ��ǲ���a
	for (int i = 0; i < a; i++) {
		sum = 0;
		for (j = 0; j < a; j++){	//���
			sum += board[j][i];
		}
		if (sum == a) {
			return true;
		}
	}
	//�ж϶Խ���
	//�Խ������������Խ��ߺ͸��Խ��ߣ������������о��룬�����������±�
	//���Խ��ߣ�0.0   1.1   2.2  ��ֵ�ı仯��ÿ������1
	//���Խ��ߣ�0.2     1.1		2.0	��������ֵ�ı仯�ǲ�һ���� 

	//���Խ��ߵ��ж�
	for (i = 0; i < a;i++) {
		sum = 0;
		sum += board[i][i];
	}
	if (sum == a) {
		return true;
	}
	//���Խ��ߵ��ж�
	for (i = 0; i < a;i++) {
		sum = 0;
		sum += board[i][a - i-1];
	}
	if (sum == a) {
		return true;
	}
	return false;
}
