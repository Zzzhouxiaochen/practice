完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1 style="">、2、4 style="">、7、14 style="">、28，除去它本身28 style="">外，其余 5个数相加，1+2+4+7+14=28。
给定函数count(int n), style="">用于计算n以内( style="">含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1
 
 
#include<iostream>
#include<algorithm>
using namespace std;

int count(int n) {
	//数据判断
	if((n < 0) || ( n > 500000)) {
		return -1;
	}
	int arr = 0;
	for(int i = 2;i <= n;i++) {	//输入数的范围
		int a = 0;
		//开始遍历每一个数
		int cur = sqrt(i);
		//sqrt是根号i的含义;
        //最多遍历到它根号的结果，
        //例如4到2 就好了，9到3就好了;28到5就好了
        //再多就重复了
		for(int j = 2;j <= cur;j++) {
			if(j % i == 0) {				
				if(j / i == i) {	//4 = 2 * 2这种  //找到一样的
					a += j;
				}
				else {
					a += j + (i / j);
				}
			}
		}
		if(a + 1 == i) {
			arr++;
		}
		return arr;
	}
}

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	//输入两手牌
	string array;
	getline(cin,array);
	//先输出王炸
	if(array.find("joker JOKER") != -1) {
		cout << "joker JOKER" << endl;
	}
	else {
		//两手牌分开
		//这时候注意牌数是不是相等
		int a = array.find('-');
		string car1 = line.substr(0, a); 
		string car2 = line.substr(a + 1);
		
		//获取空格的次数，牌数为空格数加1
		//algorithm头文件定义了一个count的函数
		//其功能类似于find。
		//这个函数使用一对迭代器和一个值做参数，返回这个值出现次数的统计结果。
		int c1 = count(car1.begin(), car1.end(), ' '); 
		int c2 = count(car2.begin(), car2.end(), ' '); //拿到第一张牌 string first1 = car1.substr(0, car1.find(' ')); string first2 = car2.substr(0, car2.find(' ')); 
		string str = "345678910JQKA2jokerJOKER"; 
		if (c1 == c2){ 
			//只要牌数相等，则第一张牌大的即为大 
			if (str.find(first1) >str.find(first2)) 
				cout << car1 << endl; 
			else 
				cout << car2 << endl; 
		} 
		else { 
			//牌数不相同，说明类型不同,只有炸弹可以和其它牌比较 
			//其它类型都是错误的 
			if (c1 == 3) 
				cout << car1 << endl; 
			else if (c2 == 3) 
				cout << car2 << endl; 
			else 
				cout << "ERROR" << endl; 
		}
	}
}
