#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;


typedef int SListDataType;
typedef struct  SListNode {
	SListDataType	value;	// 保存的值
	struct SListNode* next;	// 保存下一个结点的地址
} SListNode;

typedef struct SHead {
	SListNode* 	first;
}SHead;

//功能实现
//1.初始化
int chushihua(SHead* f) {
	assert(f!=NULL);
	f->first = NULL;
}

//2.头插
int HeadInsert(SHead* s, SListDataType date) {
	//先给数据船创建新的结点
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->value = date;		//结点的数据是5
	node->next = s->first;		//结点的下一个地址，头结点放的就是第一个元素的地址，注意first是地址
	s->first = node;	//这时候把头节点first指向新插入的node
	return 0;
}	

//3.尾插
int EndInsert(SHead* s,SListDataType date) {
	//先给数据船创建新的结点
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->value = date;
	node->next = NULL;
	//边界判断
	//链表为空的时候
	if (s->first==NULL) {
		s->first = node;	//插入数据，就第一个就是
		return;
	}

	//链表至少有一个节点的情况
	//这时候寻找最后一个节点的位置
	SListNode* arr = s->first;  //临时变量
	while (arr->next!=NULL) {
		arr = arr->next;
	}
	// arr->next 一定是  NULL，也就是最后一个结点
	//找到之后，最后一个结点指向新插入的数据
	arr->next = node;
}

//4.头删
int HeadDelete(SHead* s) {
	//边界判断
	//如果链表不存在？如果链表没有结点，没东西删除？
	assert(s != NULL);  //链表不存在判断
	assert(s->first != NULL);	//链表没有结点判断

	SListNode* cur = s->first->next; //创建一个临时变量
	free(s->first); //释放掉头节点
	s->first = cur; //头节点重新赋值
	return 0;
}


//5.尾删
int EndDelete(SHead* s) {
	//边界判断
	//1.链表为空
	assert(s->first != NULL);
	//2.链表不存在
	assert(s != NULL);
	//3.链表只有一个元素
	if (s->first->next==NULL) {
		free(s->first);
		s->first = NULL;
		return;
	}
	//找倒数第二个结点，利用临时结点变量
	SListNode* arr = s->first;
	while (arr->next->next!=NULL) {
		arr = arr->next;
	}
	//这时候arr就是倒数第二个结点
	arr->next = NULL;//指向空
	free(arr->next);
	return 0;
}

//6.按值查询
struct SListNode* SearchSList(SHead* s,SListDataType date) {   
	//边界判断
	//1.链表不存在
	assert(s != NULL);
	//2.链表为空
	assert(s->first != NULL);

	//注意返回值，返回值是地址，所以用的struct SListNode* ，就是next一样 放的地址
	SListNode* cur = s->first;
	for (cur = s->first; cur->next != NULL;cur=cur->next) {
		if (cur->value = date) {
			return cur;
		}
		
	}
}


//7.删除节点的所有date值
int DeleteAllDate(SHead* s,SListDataType date) {
	//边界判断
	//1.链表不存在
	assert(s != NULL);
	//2.链表为空
	assert(s->first != NULL);
	//注意分情况讨论：第一个结点是date ，头节点改变；
	//最后一个结点是date，尾结点改变，就是头删尾删，

	//找date值得所有结点
	//这就是按值查找
	SListNode* cur = s->first;
	SListNode* arr;
	while (cur->next!=NULL) {
		//第一个结点数据是date——头删
		if (cur->value==date) {
			cur = cur->next;
			free(s->first);
			s->first = cur;
			continue;
		}
		//最后一个节点数据是date——尾删
		if (cur->next->value==date&&cur->next==NULL) {
			cur->next = NULL;
			free(cur->next);
		}
		//其他节点删除情况
		if (cur->next->value==date) {	//找到值是date的结点，但是这时候cur还是在值是date的上一个结点。
			arr = cur->next;	//arr代表值是date的结点
			cur->next = arr->next;	//date的上个结点指向date的下一个结点
			free(arr);
		}
		else {
			cur = cur->next; //没找到继续找
		}
	
	}
	return 0;
}

//8.反转链表
int ReverseSListNode(SHead* s) {
	//边界判断
	//链表不存在
	if (s!=NULL) {
		return;
	}
	SListNode* cur;
	SListNode* arr;
	cur = s->first;
	while (cur->next!=NULL) {	//交换的实现，注意画图，画图就能看出来了
		arr = cur->next;
		arr->next = s->first;
		s->first = arr;

	}
	return 0;
}


//9.返回链表的中间结点
SListNode* zhongSListNode(SHead* s) {
	//边界判断
	//1.链表不存在
	assert(s != NULL);
	//2.链表为空
	assert(s->first1 + NULL);

	//计数器
	int count = 0;
	//判断是否到中间结点，因为要打印中间结点数据
	int count1 = 0;
	//先遍历求链表长度
	SListNode* cur = s->first;
	for (cur = s->first; cur->next != NULL;cur=cur->next) {
		count++;
	}
	//这时候count就是链表长度
	count1 = count / 2 + 1;
	//开始返回中间结点
	while (count != count1) {
		cur = cur->next;
		count++;
	}//退出循环的时候，就找到中间的了
	return cur;	//返回的是地址
	//return cur->value; //返回的是数值，根据你函数类型，如果是int，就返回数值
}


//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
SListNode* compaerSListNode(SHead* s, SListDataType date) {	//date作为基准值
	//创建两个链表
	SListNode* small=NULL;	//放小的
	SListNode* sl = NULL;	//小链表的最后一个结点
	SListNode* big=NULL;	//放大的
	SListNode* bl = NULL;	//大链表的最后一个结点
	//这时候开始比较
	//利用遍历原链表和基准值比，比较一个放一个
	SListNode* cur = s->first;
	for (cur = s->first; cur->next != NULL;cur=cur->next) {
		if (cur->value<date) {	//小于
			//这时候要注意单单只是这样的赋值，后面再来就覆盖了，所以我们要加一个标准
			if (sl->next==NULL) {	//刚开始插入的时候
				small = sl = cur;
			}
			else {	//后续插入的时候
				sl->next = cur;	//最后一个后面插入
				sl = cur;	//改变最后一个结点位置
			}
	
		}
		//大链表下面同理
		else {
			if (bl->next == NULL) {	//刚开始插入的时候
				big = bl = cur;
			}
			else {	//后续插入的时候
				bl->next = cur;	//最后一个后面插入
				bl = cur;	//改变最后一个结点位置
			}

		}
	}
	//遍历结束开始合并两个链表
	if (sl != NULL) {
		sl->next = big;
	}
	//合并结束注意大链表的结尾还没有指向NULL 
	if (bl != NULL) {
		bl->next = NULL;
	}
	//还没结，如果小的最后一个结点是空呢？也就是所有的值都比基准值大，这个判断条件里没有。
	if (sl == NULL) {	//这时候返回大链表就好了
		return big;
	}
	else {
		return small;	//因为我们把大链表接在链表之后的，所以返回small
	}
}


//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针
SListNode* chongfuSListNode(SHead* s) {
	//先创建两个临时节点
	SListNode* begin = NULL;
	SListNode* end = NULL;
	//开始遍历指针
	begin = s->first;
	if (begin->next != NULL) {	//排除只有一个结点
		if (begin->value == begin->next->value) {	//开始判断结点，进入条件是找到重复的
			int a = begin->value;	//临时变量存一下重复的值
			//遇到相等的了，进入循环找重复点的结束位置
			while (begin->next != NULL&&begin->next->value == a) {
				begin = begin->next;	//开始遍历
			}
			//循环结束 找到最后一个重复结束的结点
			end = begin->next;	
		}
		else {	//没找到重复的
			end = begin;
		}
	}
}
	
