#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int SLDateType;

typedef struct SeqList {
	SLDateType* array; //��̬����
	int size;	//��ЧԪ�صĸ���
	int capacity;	//����
}SeqList;

//����ʵ��
//��ʼ��
int InsertSeqList(SeqList* Seq) {
	Seq->capacity = MAXSIZE;  //����
	Seq->array = (SLDateType*)malloc(sizeof(SeqList)*Seq->capacity);		//���ٿռ�
	Seq->size = 0;	//��Ч���ݸ���
	return true;
}

//�ͷ�
int DeleteSeqList(SeqList* Seq) {
	free(Seq->array);  //�ͷſռ�
	Seq->capacity = 0;
	Seq->size = 0;
}


//����
int SeqListInit(SeqList* Seq, int i,int date) {  //˳���Seq �е�iλ�ã���������date   //i�ǿռ��±�
	//�߽��ж�
	//1.���ǲ�������
	if (Seq->size==Seq->capacity) {  //��ЧԪ�ظ��� = ����
		printf("�����ˣ�����ʧ�ܣ�");
		return false;
	}
	//2.����λ���Ƿ����
	if (i<=0 || i>Seq->capacity) {
		printf("����λ�ò�����");
		return false;
	}
	//����Ԫ�أ��ƶ�i֮��ĺ�������
	int j;
	for (j = Seq->size; j >= i - 1;j--) {
		Seq->array[j + 1] = Seq->array[j];  //�ƶ�
	}
	Seq->array[i - 1] = date;		//��������
	Seq->capacity++;		//��������
	return 1;
}

//ɾ��
//һ��ɾ����i��Ԫ��
int Delete1(SeqList* Seq,int i) {
	//�߽��ж�
	//��ʱ����ǲ��ǿջ�����������ν��
	//ֻ�ÿ���ɾ��λ���Ƿ����
	if (i <=0 || i>Seq->size) {
		printf("ɾ��λ�ò�����");
		return false;
	}

	//��i�����������ǰ�ƶ�һ����ֱ�Ӹ��ǵ���i��Ԫ��  //ͬ��i �ǿռ�λ�ã�����С���Ҫ-1
	int j = 0;
	for (j = i; j < Seq->size;j++) {
		Seq->array[j-1] = Seq->array[j];
	}
	//����֮�������Ϣ�ĸı�
	Seq->size--; //��ЧԪ�ظ���-1
	return true;
}


//ɾ����һ��������date��ֵ
int Delete2(SeqList* Seq, int date) {
	//1.�ҵ���һ������date��λ��
	int j = 0;
	for (j = 0; j < Seq->size;j++) {
		if (Seq ->array[j]==date) {
			Seq->array[j] = Seq->array[j + 1];  
			//�ҵ�֮��ɾ����λ��Ԫ�أ���ǰ��һ��������
			//��Ϣ�仯
			Seq->size--;
			break;	//ֻɾ��һ������ѭ��
		}
	}
}


//ɾ��ȫ��������date��ֵ
int Delete2(SeqList* Seq, int date) {
	while (1) {
		//1.�ҵ���һ������date��λ��
		int j = 0;
		for (j = 0; j < Seq->size; j++) {
			if (Seq->array[j] == date) {
				Seq->array[j] = Seq->array[j + 1];
				//�ҵ�֮��ɾ����λ��Ԫ�أ���ǰ��һ��������
				//��Ϣ�仯
				Seq->size--;
				continue;	//ע����continue��ֻ���������ε�ѭ��
			}
		}
	}
	
}



//��ѯ
//��ֵ��ѯ
int FindSeqList(SeqList* Seq, int date) {
	//˳���Seq ���ҵ�������date��Ԫ�أ���������λ�ã��ռ�λ�ã�
	//�߽��ж�
	//������ǿյľ��Ҳ�����
	if (Seq->size ==0) {
		printf("��Ϊ�գ�û����Ҫ�ҵ�����!\n");
		return 0;
	}
	//�����ݵ���date��λ��
	int j = 0;
	for (j = 0; j <= Seq->size - 1;j++) {   //ע��size -1 ;��Ϊsize �����һ��Ԫ�ص�λ��
		if (Seq->array[j] =date ) {
			printf("�ҵ���%d��λ��", date);
			return j + 1;  //����λ��
		}
	}
	return -1; //��ʾû�ҵ�
}

//��λ�ò�ѯ
int FindAddressSeqList(SeqList* Seq,int i) {   //i �ǿռ�λ��
	//�ҵ�λ�ã��������ݵ�ֵ
	//ע��˳���˳���ŵģ�ֱ�ӷ��ؾͺ���
	return Seq->array[i - 1];
}

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(SeqList* Seq)   //i�ռ��±�
{
	return Seq->size;
}
// ��ȡ˳�������� 
int SeqListCapacity(SeqList* Seq)   //i�ռ��±�
{
	return Seq->capacity;
}
// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(SeqList* Seq)   //i�ռ��±�
{
	if (Seq->size == 0)
		return 0;
}
// ��ȡ˳����е�һ��Ԫ�� 
int SeqListFront(SeqList* Seq)  //i�ռ��±�
{
	return Seq->array[0];
}
// ��ȡ˳��������һ��Ԫ�� 
int SeqListBack(SeqList* Seq)   //i�ռ��±�
{
	return Seq->array[Seq->size - 1];
}
