#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

//����
typedef int StackDataType;
//��Ϊ�Ƕ�̬����
typedef struct Stack {
	StackDataType* array;
	StackDataType size;	//����	//��ЧԪ�ظ���
	StackDataType top;	//ջ��	//��Ϊջ�������ı�����Ҫ�ض���ָ��ջ��
}Stack;


//��ʼ��
int chuStack(Stack* s) {
	s->size = 0;	//��̬�����������Ƕ�̬�����ģ�Ϊ0����ջ�� 
	return 0;
}

//����
int DeleteStack(Stack* s) {
	s->size = 0;	//����Ҳ�ǣ�Ϊ0����ʲô���ݶ�û���� 
	return 0;
}


//��ջ
int InitStack(Stack* s, int date) {
	s->array[s->size++] = date;	//�������������һ����1��λ�ô�date
	return 0;
}

//��ջ
int PushStack(Stack* s) {
	s->size--;	//size -1 ������-1�����ݳ�ջ
	return 0;
}

//����ջ��Ԫ��
int ReturnTop(Stack* s) {
	return s->array[s->size-1];
}

//�п�
int EmptyStack(Stack* s) {
	 if (s->size!=0) {
		return 1;
	}
	else {
		return 0;
	}
	
}

//����ƥ��
bool Bracket(Stack* s, string a) {
	//�����ַ���
	int size = a.size();	//���ַ������ȵ�
	int i = 0;
	for (i = 0; i < size; i++) {	//�����ַ���
		//��ʼ�ж��������Ż���������
		char arr = a[i];
		switch (arr) {
		case '(':
		case '{':
		case '[':
			InitStack(s,a[i]);	//��ջ
			break;
		case ')':
		case '}':
		case ']': {
					if (EmptyStack(s))  {	//�����ţ����ջ��û��Ԫ�ؾ���ʧ�ܣ����Գ� 
						return false;
					}
					char left = ReturnTop(s);	//����ջ��Ԫ��
					if (!((left == '(' && arr == ')')  //�����Ŷ���������	
						|| (left == '[' && arr == ']')
						|| (left == '{' && arr == '}'))) {

						return false;
					}
					PushStack(s);
					break;
		}
			if (EmptyStack(s))  {	//ƥ�����֮�󣬿��ǲ�����ʣ��
				return true;
			}
			else {
				return false;
			}
		}
	}
}