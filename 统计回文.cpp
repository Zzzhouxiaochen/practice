#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

//�жϻ����ַ���
bool palindrome(const string& str) {	//������
	int begin = 0;
	int end = str.size() - 1;
	while (begin<end) {
		if (str[begin]!=str[end]) {
			return false;
		}
		begin++;
		end--;
	}
	return true;
}
int main() {
	std::string str1, str2;    
	getline(cin, str1);    
	getline(cin, str2);
	int count = 0;
	for (int i = 0; i <= str1.size(); ++i) { 
		// ���ַ���2���뵽�ַ���1��ÿ��λ�ã����ж��Ƿ��ǻ���        
		string str = str1;       
		str.insert(i, str2);        
		if (palindrome(str)) {
			++count;
		}
	}        
	cout<<count<<endl;
	system("pause");
	return 0;
}