#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;


typedef int SListDataType;
typedef struct  SListNode {
	SListDataType	value;	// �����ֵ
	struct SListNode* next;	// ������һ�����ĵ�ַ
} SListNode;

typedef struct SHead {
	SListNode* 	first;
}SHead;

//����ʵ��
//1.��ʼ��
int chushihua(SHead* f) {
	assert(f!=NULL);
	f->first = NULL;
}

//2.ͷ��
int HeadInsert(SHead* s, SListDataType date) {
	//�ȸ����ݴ������µĽ��
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->value = date;		//����������5
	node->next = s->first;		//������һ����ַ��ͷ���ŵľ��ǵ�һ��Ԫ�صĵ�ַ��ע��first�ǵ�ַ
	s->first = node;	//��ʱ���ͷ�ڵ�firstָ���²����node
	return 0;
}	

//3.β��
int EndInsert(SHead* s,SListDataType date) {
	//�ȸ����ݴ������µĽ��
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->value = date;
	node->next = NULL;
	//�߽��ж�
	//����Ϊ�յ�ʱ��
	if (s->first==NULL) {
		s->first = node;	//�������ݣ��͵�һ������
		return;
	}

	//����������һ���ڵ�����
	//��ʱ��Ѱ�����һ���ڵ��λ��
	SListNode* arr = s->first;  //��ʱ����
	while (arr->next!=NULL) {
		arr = arr->next;
	}
	// arr->next һ����  NULL��Ҳ�������һ�����
	//�ҵ�֮�����һ�����ָ���²��������
	arr->next = node;
}

//4.ͷɾ
int HeadDelete(SHead* s) {
	//�߽��ж�
	//����������ڣ��������û�н�㣬û����ɾ����
	assert(s != NULL);  //���������ж�
	assert(s->first != NULL);	//����û�н���ж�

	SListNode* cur = s->first->next; //����һ����ʱ����
	free(s->first); //�ͷŵ�ͷ�ڵ�
	s->first = cur; //ͷ�ڵ����¸�ֵ
	return 0;
}


//5.βɾ
int EndDelete(SHead* s) {
	//�߽��ж�
	//1.����Ϊ��
	assert(s->first != NULL);
	//2.��������
	assert(s != NULL);
	//3.����ֻ��һ��Ԫ��
	if (s->first->next==NULL) {
		free(s->first);
		s->first = NULL;
		return;
	}
	//�ҵ����ڶ�����㣬������ʱ������
	SListNode* arr = s->first;
	while (arr->next->next!=NULL) {
		arr = arr->next;
	}
	//��ʱ��arr���ǵ����ڶ������
	arr->next = NULL;//ָ���
	free(arr->next);
	return 0;
}

//6.��ֵ��ѯ
struct SListNode* SearchSList(SHead* s,SListDataType date) {   
	//�߽��ж�
	//1.��������
	assert(s != NULL);
	//2.����Ϊ��
	assert(s->first != NULL);

	//ע�ⷵ��ֵ������ֵ�ǵ�ַ�������õ�struct SListNode* ������nextһ�� �ŵĵ�ַ
	SListNode* cur = s->first;
	for (cur = s->first; cur->next != NULL;cur=cur->next) {
		if (cur->value = date) {
			return cur;
		}
		
	}
}


//7.ɾ���ڵ������dateֵ
int DeleteAllDate(SHead* s,SListDataType date) {
	//�߽��ж�
	//1.��������
	assert(s != NULL);
	//2.����Ϊ��
	assert(s->first != NULL);
	//ע���������ۣ���һ�������date ��ͷ�ڵ�ı䣻
	//���һ�������date��β���ı䣬����ͷɾβɾ��

	//��dateֵ�����н��
	//����ǰ�ֵ����
	SListNode* cur = s->first;
	SListNode* arr;
	while (cur->next!=NULL) {
		//��һ�����������date����ͷɾ
		if (cur->value==date) {
			cur = cur->next;
			free(s->first);
			s->first = cur;
			continue;
		}
		//���һ���ڵ�������date����βɾ
		if (cur->next->value==date&&cur->next==NULL) {
			cur->next = NULL;
			free(cur->next);
		}
		//�����ڵ�ɾ�����
		if (cur->next->value==date) {	//�ҵ�ֵ��date�Ľ�㣬������ʱ��cur������ֵ��date����һ����㡣
			arr = cur->next;	//arr����ֵ��date�Ľ��
			cur->next = arr->next;	//date���ϸ����ָ��date����һ�����
			free(arr);
		}
		else {
			cur = cur->next; //û�ҵ�������
		}
	
	}
	return 0;
}

//8.��ת����
int ReverseSListNode(SHead* s) {
	//�߽��ж�
	//��������
	if (s!=NULL) {
		return;
	}
	SListNode* cur;
	SListNode* arr;
	cur = s->first;
	while (cur->next!=NULL) {	//������ʵ�֣�ע�⻭ͼ����ͼ���ܿ�������
		arr = cur->next;
		arr->next = s->first;
		s->first = arr;

	}
	return 0;
}


//9.����������м���
SListNode* zhongSListNode(SHead* s) {
	//�߽��ж�
	//1.��������
	assert(s != NULL);
	//2.����Ϊ��
	assert(s->first1 + NULL);

	//������
	int count = 0;
	//�ж��Ƿ��м��㣬��ΪҪ��ӡ�м�������
	int count1 = 0;
	//�ȱ�����������
	SListNode* cur = s->first;
	for (cur = s->first; cur->next != NULL;cur=cur->next) {
		count++;
	}
	//��ʱ��count����������
	count1 = count / 2 + 1;
	//��ʼ�����м���
	while (count != count1) {
		cur = cur->next;
		count++;
	}//�˳�ѭ����ʱ�򣬾��ҵ��м����
	return cur;	//���ص��ǵ�ַ
	//return cur->value; //���ص�����ֵ�������㺯�����ͣ������int���ͷ�����ֵ
}


//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
SListNode* compaerSListNode(SHead* s, SListDataType date) {	//date��Ϊ��׼ֵ
	//������������
	SListNode* small=NULL;	//��С��
	SListNode* sl = NULL;	//С��������һ�����
	SListNode* big=NULL;	//�Ŵ��
	SListNode* bl = NULL;	//����������һ�����
	//��ʱ��ʼ�Ƚ�
	//���ñ���ԭ����ͻ�׼ֵ�ȣ��Ƚ�һ����һ��
	SListNode* cur = s->first;
	for (cur = s->first; cur->next != NULL;cur=cur->next) {
		if (cur->value<date) {	//С��
			//��ʱ��Ҫע�ⵥ��ֻ�������ĸ�ֵ�����������͸����ˣ���������Ҫ��һ����׼
			if (sl->next==NULL) {	//�տ�ʼ�����ʱ��
				small = sl = cur;
			}
			else {	//���������ʱ��
				sl->next = cur;	//���һ���������
				sl = cur;	//�ı����һ�����λ��
			}
	
		}
		//����������ͬ��
		else {
			if (bl->next == NULL) {	//�տ�ʼ�����ʱ��
				big = bl = cur;
			}
			else {	//���������ʱ��
				bl->next = cur;	//���һ���������
				bl = cur;	//�ı����һ�����λ��
			}

		}
	}
	//����������ʼ�ϲ���������
	if (sl != NULL) {
		sl->next = big;
	}
	//�ϲ�����ע�������Ľ�β��û��ָ��NULL 
	if (bl != NULL) {
		bl->next = NULL;
	}
	//��û�ᣬ���С�����һ������ǿ��أ�Ҳ�������е�ֵ���Ȼ�׼ֵ������ж�������û�С�
	if (sl == NULL) {	//��ʱ�򷵻ش�����ͺ���
		return big;
	}
	else {
		return small;	//��Ϊ���ǰѴ������������֮��ģ����Է���small
	}
}


//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷ ָ��
SListNode* chongfuSListNode(SHead* s) {
	//�ȴ���������ʱ�ڵ�
	SListNode* begin = NULL;
	SListNode* end = NULL;
	//��ʼ����ָ��
	begin = s->first;
	if (begin->next != NULL) {	//�ų�ֻ��һ�����
		if (begin->value == begin->next->value) {	//��ʼ�жϽ�㣬�����������ҵ��ظ���
			int a = begin->value;	//��ʱ������һ���ظ���ֵ
			//������ȵ��ˣ�����ѭ�����ظ���Ľ���λ��
			while (begin->next != NULL&&begin->next->value == a) {
				begin = begin->next;	//��ʼ����
			}
			//ѭ������ �ҵ����һ���ظ������Ľ��
			end = begin->next;	
		}
		else {	//û�ҵ��ظ���
			end = begin;
		}
	}
}
	
