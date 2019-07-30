#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

//判断回文字符串
bool palindrome(const string& str) {	//传引用
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
		// 将字符串2插入到字符串1的每个位置，再判断是否是回文        
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