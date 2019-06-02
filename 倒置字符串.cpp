#include <iostream> 
#include <string> 
#include <algorithm>
using namespace std; 


int main() {    
	string s;

	//1.输入字符串
	getline(cin, s);

	//2.句子倒置
	reverse(s.begin(), s.end());

	//3.单词倒置
	//倒置的判断条件：1.单词开始等于最后    2.遇到空格
	auto start = s.begin();

	//关键：找到单词的end
	while (start!=s.end()) {
		auto end = start;
		while (end!=s.end()&& *end!=' ') {
			end++;   //找到end
			
		}
		reverse(start, end);  //反转一个单词了

		//移动start，再次继续倒置第二个
		if (end!=s.end()) {
			start = end + 1;
		}
		else {
			start = end;
		}
	}

	//4.打印倒置后的字符串
	cout << s << endl;

	system("pause");
	return 0; 
}