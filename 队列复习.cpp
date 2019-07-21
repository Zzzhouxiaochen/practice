#include<stdlib.h>
#include<stdio.h>
#include <string>
#include<iostream>
using namespace std;

typedef int QueueDateType;
typedef struct QNode {
	int value;	//链表的值
	struct QNode* next;	//下一个结点
}QNode;

typedef struct Queue {
	 QNode* first;	//第一个结点
	 QNode* end;	//最后一个结点
}Queue; 

//初始化
int BeginQueue(Queue* s) {
	s->end = s->first = NULL;
	return 0;
}

//  销毁
int DeleteQueue(Queue* s) {
	//链表是有空间的，注意释放空间，不然会有一个内存泄漏问题
	QNode* cur;
	QNode* arr;	
	//注意：因为每次都要free 掉cur  那么就不能用cur=cur->next，这样没空间了，所以接用临时变量
	for (cur = s->first; cur != NULL;cur=arr) {
		free(cur);
		arr = cur->next;
	}
	s->end = s->first = NULL;
	return 0;
}

//入队列
//链表的尾插
int PushQueue(Queue* s,int v) {
	//先创结点
	QNode* cur = (QNode*)malloc(sizeof(QNode));
	cur->value = v;
	//边界判断，看是不是空
	if (s->first!=NULL) {
		//不是空，尾插
		s->end->next = cur;
		s->end = cur;
	}
	else {
		s->first = cur;	
		s->end = cur;
	}
	return 0;
}


//出队列
//链表的头删
int PopQueue(Queue* s) {
	//有头节点的位置，即first就很方便
	QNode* cur = s->first->next;
	free(s->first);
	s->first = cur;
	//边界判断
	//如果队列中那个只有一个数据最后一个位置不就改变了
	if (s->first==NULL) {
		s->end = NULL;
	}
	return 0;
}

//获取队列队首元素
int QueueFirst(Queue* s) {
	return s->first->value;
}

//返回队尾元素
int QueueEnd(Queue* s) {
	return s->end->value;
}

//判空
int QueueEmpty(Queue* s) {
	if (s->first!=NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//队列元素个数
int QueueSize(Queue* s) {
	//利用遍历+计数器就很清晰实现数据个数
	QNode* cur=NULL;
	int size = 0;
	for (cur = s->first; cur!= NULL;cur=cur->next) {
		size++;
	}
	return size;
}


