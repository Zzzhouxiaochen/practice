#include<queue>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;


typedef int TreeDataType;
typedef struct Tree {
	TreeDataType data;	//��������
	struct Tree* Lchild;	//���ӽ��
	struct Tree* Rchild;	//�Һ��ӽڵ�
};

//ǰ�����
int BeforeTree(Tree* s) {
	//�߽��ж�
	//�п�
	if (s==NULL) {
		return;	
	}
	printf("%d", s->data);
	BeforeTree(s->Lchild);
	BeforeTree(s->Rchild);
}

//�������
int MiddleTree(Tree* s) {
	//�߽��ж�
	//�п�
	if (s == NULL) {
		return;
	}
	BeforeTree(s->Lchild);
	printf("%d", s->data);
	BeforeTree(s->Rchild);
}

//�������
int EndTree(Tree* s) {
	//�߽��ж�
	//�п�
	if (s == NULL) {
		return;
	}
	BeforeTree(s->Lchild);
	BeforeTree(s->Rchild);
	printf("%d", s->data);
}

//�������
//����ʵ��
int  LayerTree(Tree* s) {
	int array[1024];
	int in = 0;
	int out = 0;
	array[in++] = s->data;//��������	//ʵ����array[in] =data; Ȼ��in++
	while (in>out) {
		if (array[out]) {
			
		}
	}
}
//����ʵ��
int QueueTree(Tree* s) {
	queue <Tree*> q;
	if (s != NULL)
	{
		q.push(s);   //���ڵ������
	}
}
//�������
void putout4(Tree* T){
	//�ȶ��������飬��������������ʽ���˶������Ĵ洢�ṹ
	Tree* q[100];
	q[0] = T;
	//front����Ҫ������α꣬rear���½�����洢���α�
	int front = 0;
	int rear = 1;
	//rear�ͱ�front��˵���������滹��û����Ľڵ�
	while (front < rear) {
		//front�����Ͱ�������ߣ�ÿ�μ�һ
		printf("%c ", q[front]->data);
		//ֻҪ���ڵ������ӽڵ���ôrear�ͼ�1
		if (q[front]->Lchild) {
			q[rear++] = q[front]->Lchild;
		}
		//ֻҪ���ڵ����Һ��ӽڵ���ôrear�ͼ�1
		if (q[front]->Rchild) {
			q[rear++] = q[front]->Rchild;
		}
		//����������
		++front;
	}
}


//����ʵ�֣�

//1�����Ƚ��������ĸ��ڵ�push�������У��ж϶��в�ΪNULL���������ͷ��Ԫ�أ�

//2���жϽڵ�����к��ӣ��ͽ�����push�������У�

//3���������Ľڵ�����У�

//4��ѭ�����ϲ�����ֱ��Tree == NULL



void LevelOrder1(Tree* s) //�������_����ʵ��
{
	queue <Tree*> q;
	if (s != NULL)
	{
		q.push(s);   //���ڵ������
	}
	while (q.empty() == false)  //���в�Ϊ���ж�
	{
		cout << q.front()->data << " �� ";
		if (q.front()->Lchild != NULL)   //��������ӣ����������
		{
			q.push(q.front()->Lchild);
		}
		if (q.front()->Rchild != NULL)   //������Һ��ӣ��Һ��������
		{
			q.push(q.front()->Rchild);
		}
		q.pop();  //�Ѿ��������Ľڵ������
	}
}


//�ж��������ǲ�����ͬ��
bool SameTree(Tree* s,Tree* q) {
	if (s == NULL&&q==NULL) {	//���������ǿ�
		return false;
	}
	return 0;
	if ((s == NULL && q != NULL) || (s != NULL && q == NULL)) {
		// һ��Ϊ��,һ�ò�Ϊ�գ��϶��ǲ�ͬ��
		return false;
	}

	 if (s->data==q->data) {
	 	//�жϸ��ڵ�
		 return true;
	 }
	 //�ݹ��ж���������������
	 SameTree(s->Lchild, q->Lchild);	
	 SameTree(s->Rchild, q->Rchild);
}

//�ж�B���ǲ���A��������
bool ASameBTree(Tree* a, Tree* b) {
	//���пգ����ǿ������϶�һ����
	if (a==NULL&&b==NULL) {
		return true;
	}
	bool result;
	//���ǿ������Һ�B�����ڵ�һ����ֵ�ý��
	if (a!=	NULL&&b!=NULL) {
		if (a->data==b->data) {	//�ҵ���һ���ý�㣬��ʼͬʱ����
			//����д����
			result=TrueSameTree(a, b);
		}
		//������ǾͱȽ�A����������B�����Ǽ�һ����ʱ����
		if (!result) {
			ASameBTree(a->Lchild, b);
		}
		//������û����������
		if (!result) {
			ASameBTree(a->Rchild, b);
		}
	}
	//��û�ҵ�
	return false;
}

bool TrueSameTree(Tree*a, Tree* b) {
	if (b==NULL) {
		return true;	//��ʱ��˵�� b �� a���ý��
	}
	if (a==	NULL) {
		return false;
	}
	if (a->data!=b->data) {
		return false;
	}
	else {
		return TrueSameTree(a->Lchild, b->Lchild) && TrueSameTree(a->Rchild, b->Rchild);	//�ݹ��ж�
	}
}

//�������������
int DeepTree(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	int left = DeepTree(s->Lchild);	//�ݹ�����
	int right = DeepTree(s->Rchild);
	return Max(left, right)+1;	//�Ƚϴ��������
}
int Max(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}

// ���������������
int Height(Tree* pRoot){	
	if (pRoot == NULL)		
		return; 	
	int left = Height(pRoot->Lchild);	
	int right = Height(pRoot->Rchild); 	
	return (left < right ? right: left)+1;
}


int maxDepth(Tree* s) {
	int max = 0;//�洢���������       
	int leftMax=0;        
	int rightMax=0;        
	if (s != NULL) {
		//�����ǰ������Ϊ��,�ǿ���            
		max++;//��ȼ�1            
		leftMax = maxDepth(s->Lchild);//���������            
		rightMax = maxDepth(s->Rchild);//���������            
		max += leftMax >= rightMax ? leftMax : rightMax;//��ǰ���������        
	}         
	return max;//���ص�ǰ���������            
}

//�����������С���
int MinDeepTree(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	if (s->Lchild==NULL&&s->Rchild==NULL) {
		return 1;	//ֻ�и��ڵ�
	}
	int result = 0;
	int left = MinDeepTree(s->Lchild)+1;
	int right = MinDeepTree(s->Rchild)+1;
	if (s->Lchild != NULL&&s->Rchild != NULL){
		result = Min(left, right);
	}
	else{
		result = Max(left, right);
	}
	return result;

}
int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int Min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

//�ж��ǲ���ƽ�������
bool BanlanceTree(Tree* s) {
	if (s == NULL) {
		return 0;
	}
	int left = BanlanceTree(s->Lchild) + 1;	//�ݹ�����
	int right = BanlanceTree(s->Rchild) + 1;
	return Compare(left, right);	//�Ƚϴ��������
}
bool Compare(int a, int b) {
	if (a - b <=1) {
		return true;
	}
	else {
		return false;
	}
}


//�ж��ǲ�������
bool isSameTree(Tree  *p, Tree *q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	if (p == NULL || q == NULL) {
		return false;
	}
	return p->data == q->data
		&& isSameTree(p->Lchild, q->Rchild)
		&& isSameTree(p->Lchild, q->Rchild);
}


//��������ľ���
bool Mirror(Tree* a, Tree* b){ 
	if (a == NULL&&b == NULL)	{ 
		return 1; 
	} 	if (a == NULL || b == NULL)	{ 
		return 0; 
	} 	
	return a->data == b->data	
			&& Mirror(b->Lchild, b->Rchild) 
			&& Mirror(a->Lchild, b->Rchild); 
}

//��Գƶ�����
void MirrorRecursively(Tree *pRoot)
{
	if ((pRoot == NULL) || (pRoot->Lchild == NULL && pRoot->Rchild == NULL))
		return;

	Tree *pTemp = pRoot->Lchild;
	pRoot->Lchild = pRoot->Rchild;
	pRoot->Rchild = pTemp;

	if (pRoot->Lchild)
		MirrorRecursively(pRoot->Lchild);

	if (pRoot->Rchild)
		MirrorRecursively(pRoot->Rchild);
}

//�������Ĺ���
Tree* CreatTree(Tree* s, int size) {
	int data;
	printf("���������ݣ�\n");
	scanf("%d", &data);

	if (data ==0) {
		s = NULL;
	}
	else {
		//�����洢�ռ�
		s = (Tree*)malloc(sizeof(Tree));
		s->data = data;	//������ݵ���data
		//�ݹ鴴��
		CreatTree(s->Lchild, size);
		CreatTree(s->Rchild, size);
	}
	return s;
}

Tree* Find(Tree* s, int data) {
	if (s == NULL) { 
		return NULL; 
	} 	// ��ȥ����	
	if (s->data == data) {
		// �ҵ���		
		return s;	
	}	
	// �����û�ҵ���ȥ��������	
	Tree *result = Find(s->Lchild, data);	//�ݹ�
	if (result != NULL) {		
		// ���������ҵ���		
		return result;	
	} 	
	// ���������û�ҵ���ȥ��������	
	result = Find(s->Rchild, data);
	if (result != NULL) {		
		return result;	}	
	else {		
		return NULL;	
	}
}

//��ȡ������
int SizeTree(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	int size = 0;
	size++;

	SizeTree(s->Lchild);
	SizeTree(s->Rchild);
	return size;
}

int SizeTree1(Tree* s) {
	if (s == NULL) {
		return 0;
	}
	int left=SizeTree1(s->Lchild);
	int right=SizeTree1(s->Rchild);
	return left+right+1;
}

//��������ĸ߶� == �����
int Height(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	int left = Height(s->Lchild);
	int right = Height(s->Rchild);
	return (left < right ? right : left) + 1;
}

//��Ҷ�ӽ�����

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(Tree* pRoot) {
	if (pRoot == NULL) {
		return 0;
	}
	if (pRoot->Lchild == NULL&&pRoot->Rchild == NULL)
		return 1;
	int left = GetLeafNodeCount(pRoot->Lchild);
	int right = GetLeafNodeCount(pRoot->Rchild);
	return left + right + 1;

}


int GetKLevelNodeCount(Tree* s, int K) {

	if (s == NULL) {
		return 0;
	}
	if (K == 1) {	// ������ǰ����, root != NULL
		return 1;
	}
	return GetKLevelNodeCount(s->Lchild, K - 1)
		+ GetKLevelNodeCount(s->Rchild, K - 1);
}


//ǰ������ȷ��������
//�ĸ�������ǰ������Ŀ�ʼ�ĵ�λ�ã�ǰ�����������λ�ã����������ʼλ�ã��������������λ��
Tree * build(int s1, int e1, int s2, int e2){    
	//����ǰ���������str1�������������str2�����������������ĸ��ڵ㣬    
	Tree* s	 = (Tree*)malloc(sizeof(Tree));	//�������ڵ�
	if (s) {
		s->Lchild = s->Rchild = NULL;
	}
	char str1[1024];	//��ǰ�����
	char str2[1024];	//���������
	s->data = str1[s1];    
	int middleroot;    
	for (int i = s2; i<=e2;i++ ) {        
		if (str2[i]==str1[s1]) {            
			middleroot = i;//����������������ҵ����ڵ���±ꣻ            
			break;       
		}    
	}    
	if (middleroot != s2){//˵����������Ϊ��        
		s->Lchild = build(s1 + 1, s1 + (middleroot - s2), s2, middleroot - 1);
	}   
	if (middleroot != e2) {//˵����������Ϊ��       
		s->Rchild = build(s1 + (middleroot - s2) + 1, e1, middleroot + 1, e2);
	}    
	return s;
}


//������������ͺ������ȷ��һ����
Tree* buid1(char str1[2014], char str2[1024]) {
	//����ǰ���������str1�������������str2�����������������ĸ��ڵ㣬
	char str1[1024];	//��ǰ�����
	char str2[1024];	//���������
	int length = strlen(str2);
	if (length == 0) {
		return NULL;
	}
	//1�����ݺ����ҵ�����ֵ�����Ҵ������ڵ�
	char rootValue = str2[length - 1];
	Tree* root = new Tree(rootValue);

	//2�����������ҵ�����ֵ���ڵ��±�
	int leftSize = Find(str1, rootValue);

	//3���г�������������ͺ���
	char leftInorder[] = Arrays.copyOfRange(inorder, 0, leftSize);
	char leftPostorder[] = Arrays.copyOfRange(postorder, 0, leftSize);
	root.left = buildTree(leftInorder, leftPostorder);

	//4���г�������������ͺ���
	char[] rightInorder = Arrays.copyOfRange(inorder, leftSize + 1, inorder.length);
	char[] rightPostorder = Arrays.copyOfRange(postorder, leftSize, postorder.length - 1);
	root.right = buildTree(rightInorder, rightPostorder);

	return root;
}