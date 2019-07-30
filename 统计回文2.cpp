
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define Max 200

bool IsPalin(char * str, int length) {
	int cnt = 0;
	for (int i = 0; i < (length / 2); i++) {
		if (str[i] != str[length - i - 1]) {
			++cnt;
			break;
		}
	}
	if (cnt)
		return false;
	else
		return true;
}

int main()
{

	char *A = (char *)malloc(100);
	char *B = (char *)malloc(100);
	int count = 0;
	cin >> A;
	cin >> B;
	int ALen = strlen(A);
	int BLen = strlen(B);
	for (int i = 0; i <= ALen; i++) {
		char *C = (char *)malloc(100);
		if (i == 0) {
			memcpy(C, B, BLen);
			memcpy(C + BLen, A + i, ALen);
			if (IsPalin(C, strlen(C)))
				++count;
		}
		else {
			memcpy(C, A, i);
			memcpy(C + i, B, BLen);
			memcpy(C + i + BLen, A + i, ALen - i);
			if (IsPalin(C, ALen + BLen))
				++count;
		}
		free(C);
		C = NULL;
	}
	cout << count << endl;
	free(A);
	free(B);
	return 0;
}
