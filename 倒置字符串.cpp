#include <iostream> 
#include <string> 
#include <algorithm>
using namespace std; 


int main() {    
	string s;

	//1.�����ַ���
	getline(cin, s);

	//2.���ӵ���
	reverse(s.begin(), s.end());

	//3.���ʵ���
	//���õ��ж�������1.���ʿ�ʼ�������    2.�����ո�
	auto start = s.begin();

	//�ؼ����ҵ����ʵ�end
	while (start!=s.end()) {
		auto end = start;
		while (end!=s.end()&& *end!=' ') {
			end++;   //�ҵ�end
			
		}
		reverse(start, end);  //��תһ��������

		//�ƶ�start���ٴμ������õڶ���
		if (end!=s.end()) {
			start = end + 1;
		}
		else {
			start = end;
		}
	}

	//4.��ӡ���ú���ַ���
	cout << s << endl;

	system("pause");
	return 0; 
}