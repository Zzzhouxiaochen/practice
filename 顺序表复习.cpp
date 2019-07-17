#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int SLDateType;

typedef struct SeqList {
	SLDateType* array; //动态数组
	int size;	//有效元素的个数
	int capacity;	//容量
}SeqList;

//功能实现
//初始化
int InsertSeqList(SeqList* Seq) {
	Seq->capacity = MAXSIZE;  //容量
	Seq->array = (SLDateType*)malloc(sizeof(SeqList)*Seq->capacity);		//开辟空间
	Seq->size = 0;	//有效数据个数
	return true;
}

//释放
int DeleteSeqList(SeqList* Seq) {
	free(Seq->array);  //释放空间
	Seq->capacity = 0;
	Seq->size = 0;
}


//插入
int SeqListInit(SeqList* Seq, int i,int date) {  //顺序表Seq 中第i位置，插入数据date   //i是空间下表
	//边界判断
	//1.表是不是满了
	if (Seq->size==Seq->capacity) {  //有效元素个数 = 容量
		printf("表满了，插入失败！");
		return false;
	}
	//2.插入位置是否合理
	if (i<=0 || i>Seq->capacity) {
		printf("插入位置不合理！");
		return false;
	}
	//插入元素，移动i之后的后续数据
	int j;
	for (j = Seq->size; j >= i - 1;j--) {
		Seq->array[j + 1] = Seq->array[j];  //移动
	}
	Seq->array[i - 1] = date;		//插入数据
	Seq->capacity++;		//容量扩大
	return 1;
}

//删除
//一样删除第i个元素
int Delete1(SeqList* Seq,int i) {
	//边界判断
	//这时候表是不是空或者满的无所谓了
	//只用考虑删除位置是否合理化
	if (i <=0 || i>Seq->size) {
		printf("删除位置不合理");
		return false;
	}

	//把i后面的数据向前移动一个，直接覆盖掉第i个元素  //同样i 是空间位置，数组小标就要-1
	int j = 0;
	for (j = i; j < Seq->size;j++) {
		Seq->array[j-1] = Seq->array[j];
	}
	//插入之后相关信息的改变
	Seq->size--; //有效元素个数-1
	return true;
}


//删除第一个数据是date的值
int Delete2(SeqList* Seq, int date) {
	//1.找到第一个数据date的位置
	int j = 0;
	for (j = 0; j < Seq->size;j++) {
		if (Seq ->array[j]==date) {
			Seq->array[j] = Seq->array[j + 1];  
			//找到之后，删除该位置元素，和前面一样，覆盖
			//信息变化
			Seq->size--;
			break;	//只删除一个跳出循环
		}
	}
}


//删除全部数据是date的值
int Delete2(SeqList* Seq, int date) {
	while (1) {
		//1.找到第一个数据date的位置
		int j = 0;
		for (j = 0; j < Seq->size; j++) {
			if (Seq->array[j] == date) {
				Seq->array[j] = Seq->array[j + 1];
				//找到之后，删除该位置元素，和前面一样，覆盖
				//信息变化
				Seq->size--;
				continue;	//注意是continue，只是跳出本次的循环
			}
		}
	}
	
}



//查询
//按值查询
int FindSeqList(SeqList* Seq, int date) {
	//顺序表Seq 中找到数据是date的元素，返回它的位置（空间位置）
	//边界判断
	//表如果是空的就找不到了
	if (Seq->size ==0) {
		printf("表为空，没有所要找的数据!\n");
		return 0;
	}
	//找数据等于date的位置
	int j = 0;
	for (j = 0; j <= Seq->size - 1;j++) {   //注意size -1 ;因为size 是最后一个元素的位置
		if (Seq->array[j] =date ) {
			printf("找到了%d的位置", date);
			return j + 1;  //返回位置
		}
	}
	return -1; //表示没找到
}

//按位置查询
int FindAddressSeqList(SeqList* Seq,int i) {   //i 是空间位置
	//找到位置，返回数据的值
	//注意顺序表顺序存放的，直接返回就好了
	return Seq->array[i - 1];
}

// 获取顺序表有效元素个数 
int SeqListSize(SeqList* Seq)   //i空间下标
{
	return Seq->size;
}
// 获取顺序表的容量 
int SeqListCapacity(SeqList* Seq)   //i空间下标
{
	return Seq->capacity;
}
// 检测顺序表是否为空 
int SeqListEmpty(SeqList* Seq)   //i空间下标
{
	if (Seq->size == 0)
		return 0;
}
// 获取顺序表中第一个元素 
int SeqListFront(SeqList* Seq)  //i空间下标
{
	return Seq->array[0];
}
// 获取顺序表中最后一个元素 
int SeqListBack(SeqList* Seq)   //i空间下标
{
	return Seq->array[Seq->size - 1];
}
