#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
	//��������
	//��  year  
	//��  mouth
	//��  day
	int year, mouth, day;
	int result=0;
	cin >> year;
	cin >> mouth;
	cin >>day;
	//�ж��ǲ�������
	if (((year&4==0)&&(year%100!=0))||(year%400==0)) {
		if (mouth==2&&day>=30) {
			printf("�����ʽ����");
		}
			switch (mouth) {
			case 1:
				result = day;
			case 2:
				result = 31 + day;
			case 3:
				result = 31 + 29 + day;
			case 4:
				result = 31 + 29 + 31 + day;
			case 5:
				result = 31 + 29 + 31 + 30 + day;
			case 6:
				result = 31 + 29 + 31 + 30 + 31 + day;
			case 7:
				result = 31 + 29 + 31 + 30 + 31 + 30 + day;
			case 8:
				result = 31 + 29 + 31 + 30 + 31 + 30 + 31+ day;
			case 9:
				result = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
			case 10:
				result = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
			case 11:
				result = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
			case 12:
				result = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
			default:
				break;
			}
		
		
	}
	else
	{
		if (mouth == 2 && day >= 29) {
			printf("�����ʽ����");
		}
		switch (mouth) {
		case 1:
			result = day;
		case 2:
			result = 31 + day;
		case 3:
			result = 31 + 28 + day;
		case 4:
			result = 31 + 28 + 31 + day;
		case 5:
			result = 31 + 28 + 31 + 30 + day;
		case 6:
			result = 31 + 28 + 31 + 30 + 31 + day;
		case 7:
			result = 31 + 28 + 31 + 30 + 31 + 30 + day;
		case 8:
			result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
		case 9:
			result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
		case 10:
			result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
		case 11:
			result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
		case 12:
			result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
		default:
			break;
		}

	}
	printf("����һ���еģ�%d", result);
	system("pause");
	return 0;
}