#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

//定义
typedef int StackDataType;
//因为是动态数组
typedef struct Stack {
	StackDataType* array;
	StackDataType size;	//容量	//有效元素个数
	StackDataType top;	//栈顶	//因为栈顶经常改变所以要特定的指定栈顶
}Stack;


//初始化
int chuStack(Stack* s) {
	s->size = 0;	//动态的数组容量是动态增长的，为0就有栈了 
	return 0;
}

//销毁
int DeleteStack(Stack* s) {
	s->size = 0;	//销毁也是，为0就有什么数据都没有了 
	return 0;
}


//入栈
int InitStack(Stack* s, int date) {
	s->array[s->size++] = date;	//让数组数据最后一个加1个位置存date
	return 0;
}

//出栈
int PushStack(Stack* s) {
	s->size--;	//size -1 就数据-1；数据出栈
	return 0;
}

//返回栈顶元素
int ReturnTop(Stack* s) {
	return s->array[s->size-1];
}

//判空
int EmptyStack(Stack* s) {
	 if (s->size!=0) {
		return 1;
	}
	else {
		return 0;
	}
	
}

//括号匹配
bool Bracket(Stack* s, string a) {
	//输入字符串
	int size = a.size();	//求字符串长度的
	int i = 0;
	for (i = 0; i < size; i++) {	//遍历字符串
		//开始判断是左括号还是右括号
		char arr = a[i];
		switch (arr) {
		case '(':
		case '{':
		case '[':
			InitStack(s,a[i]);	//入栈
			break;
		case ')':
		case '}':
		case ']': {
					if (EmptyStack(s))  {	//右括号，如果栈里没有元素就是失败，不对称 
						return false;
					}
					char left = ReturnTop(s);	//返回栈顶元素
					if (!((left == '(' && arr == ')')  //右括号多于左括号	
						|| (left == '[' && arr == ']')
						|| (left == '{' && arr == '}'))) {

						return false;
					}
					PushStack(s);
					break;
		}
			if (EmptyStack(s))  {	//匹配结束之后，看是不是有剩余
				return true;
			}
			else {
				return false;
			}
		}
	}
}