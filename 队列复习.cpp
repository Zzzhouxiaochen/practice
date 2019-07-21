#include<stdlib.h>
#include<stdio.h>
#include <string>
#include<iostream>
using namespace std;

typedef int QueueDateType;
typedef struct QNode {
	int value;	//�����ֵ
	struct QNode* next;	//��һ�����
}QNode;

typedef struct Queue {
	 QNode* first;	//��һ�����
	 QNode* end;	//���һ�����
}Queue; 

//��ʼ��
int BeginQueue(Queue* s) {
	s->end = s->first = NULL;
	return 0;
}

//  ����
int DeleteQueue(Queue* s) {
	//�������пռ�ģ�ע���ͷſռ䣬��Ȼ����һ���ڴ�й©����
	QNode* cur;
	QNode* arr;	
	//ע�⣺��Ϊÿ�ζ�Ҫfree ��cur  ��ô�Ͳ�����cur=cur->next������û�ռ��ˣ����Խ�����ʱ����
	for (cur = s->first; cur != NULL;cur=arr) {
		free(cur);
		arr = cur->next;
	}
	s->end = s->first = NULL;
	return 0;
}

//�����
//�����β��
int PushQueue(Queue* s,int v) {
	//�ȴ����
	QNode* cur = (QNode*)malloc(sizeof(QNode));
	cur->value = v;
	//�߽��жϣ����ǲ��ǿ�
	if (s->first!=NULL) {
		//���ǿգ�β��
		s->end->next = cur;
		s->end = cur;
	}
	else {
		s->first = cur;	
		s->end = cur;
	}
	return 0;
}


//������
//�����ͷɾ
int PopQueue(Queue* s) {
	//��ͷ�ڵ��λ�ã���first�ͺܷ���
	QNode* cur = s->first->next;
	free(s->first);
	s->first = cur;
	//�߽��ж�
	//����������Ǹ�ֻ��һ���������һ��λ�ò��͸ı���
	if (s->first==NULL) {
		s->end = NULL;
	}
	return 0;
}

//��ȡ���ж���Ԫ��
int QueueFirst(Queue* s) {
	return s->first->value;
}

//���ض�βԪ��
int QueueEnd(Queue* s) {
	return s->end->value;
}

//�п�
int QueueEmpty(Queue* s) {
	if (s->first!=NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//����Ԫ�ظ���
int QueueSize(Queue* s) {
	//���ñ���+�������ͺ�����ʵ�����ݸ���
	QNode* cur=NULL;
	int size = 0;
	for (cur = s->first; cur!= NULL;cur=cur->next) {
		size++;
	}
	return size;
}


