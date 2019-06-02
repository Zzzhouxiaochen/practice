#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


int main() {
	int x = 0;
	int y = 0;
	cin >> x;
	cin >> y;
	//找最小约数
	int i;
	int count = 0;
	int a = x;
	while (a!=y) {
		for (i = 1; i <= a; i++) {
			if ((i != 1) && (x%i == 0)) {
				a = a + i;
				++count;
				break;
			}
		}

	}
	printf("%d", count);
	system("pause");
	return 0;
}