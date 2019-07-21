#include<queue>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;


typedef int TreeDataType;
typedef struct Tree {
	TreeDataType data;	//结点的数据
	struct Tree* Lchild;	//左孩子结点
	struct Tree* Rchild;	//右孩子节点
};

//前序遍历
int BeforeTree(Tree* s) {
	//边界判断
	//判空
	if (s==NULL) {
		return;	
	}
	printf("%d", s->data);
	BeforeTree(s->Lchild);
	BeforeTree(s->Rchild);
}

//中序遍历
int MiddleTree(Tree* s) {
	//边界判断
	//判空
	if (s == NULL) {
		return;
	}
	BeforeTree(s->Lchild);
	printf("%d", s->data);
	BeforeTree(s->Rchild);
}

//后序遍历
int EndTree(Tree* s) {
	//边界判断
	//判空
	if (s == NULL) {
		return;
	}
	BeforeTree(s->Lchild);
	BeforeTree(s->Rchild);
	printf("%d", s->data);
}

//层序遍历
//数组实现
int  LayerTree(Tree* s) {
	int array[1024];
	int in = 0;
	int out = 0;
	array[in++] = s->data;//保存根结点	//实际是array[in] =data; 然后in++
	while (in>out) {
		if (array[out]) {
			
		}
	}
}
//队列实现
int QueueTree(Tree* s) {
	queue <Tree*> q;
	if (s != NULL)
	{
		q.push(s);   //根节点进队列
	}
}
//层序遍历
void putout4(Tree* T){
	//先定个大数组，就像是用数组形式定了二叉树的存储结构
	Tree* q[100];
	q[0] = T;
	//front就是要输出的游标，rear是新进来点存储的游标
	int front = 0;
	int rear = 1;
	//rear就比front大，说明数组里面还有没输出的节点
	while (front < rear) {
		//front按部就班地往后走，每次加一
		printf("%c ", q[front]->data);
		//只要树节点有左孩子节点那么rear就加1
		if (q[front]->Lchild) {
			q[rear++] = q[front]->Lchild;
		}
		//只要树节点有右孩子节点那么rear就加1
		if (q[front]->Rchild) {
			q[rear++] = q[front]->Rchild;
		}
		//继续往后走
		++front;
	}
}


//队列实现：

//1、首先将二叉树的根节点push到队列中，判断队列不为NULL，就输出队头的元素，

//2、判断节点如果有孩子，就将孩子push到队列中，

//3、遍历过的节点出队列，

//4、循环以上操作，直到Tree == NULL



void LevelOrder1(Tree* s) //层序遍历_队列实现
{
	queue <Tree*> q;
	if (s != NULL)
	{
		q.push(s);   //根节点进队列
	}
	while (q.empty() == false)  //队列不为空判断
	{
		cout << q.front()->data << " → ";
		if (q.front()->Lchild != NULL)   //如果有左孩子，左孩子入队列
		{
			q.push(q.front()->Lchild);
		}
		if (q.front()->Rchild != NULL)   //如果有右孩子，右孩子入队列
		{
			q.push(q.front()->Rchild);
		}
		q.pop();  //已经遍历过的节点出队列
	}
}


//判断两个数是不是相同的
bool SameTree(Tree* s,Tree* q) {
	if (s == NULL&&q==NULL) {	//两个树都是空
		return false;
	}
	return 0;
	if ((s == NULL && q != NULL) || (s != NULL && q == NULL)) {
		// 一棵为空,一棵不为空，肯定是不同的
		return false;
	}

	 if (s->data==q->data) {
	 	//判断根节点
		 return true;
	 }
	 //递归判断左子树和右子树
	 SameTree(s->Lchild, q->Lchild);	
	 SameTree(s->Rchild, q->Rchild);
}

//判断B树是不是A树的子树
bool ASameBTree(Tree* a, Tree* b) {
	//先判空，都是空树，肯定一样的
	if (a==NULL&&b==NULL) {
		return true;
	}
	bool result;
	//不是空树，找和B树根节点一样的值得结点
	if (a!=	NULL&&b!=NULL) {
		if (a->data==b->data) {	//找到了一样得结点，开始同时遍历
			//单独写函数
			result=TrueSameTree(a, b);
		}
		//如果不是就比较A的左子树和B，我们加一个临时变量
		if (!result) {
			ASameBTree(a->Lchild, b);
		}
		//左子树没有找右子树
		if (!result) {
			ASameBTree(a->Rchild, b);
		}
	}
	//都没找到
	return false;
}

bool TrueSameTree(Tree*a, Tree* b) {
	if (b==NULL) {
		return true;	//这时候说明 b 是 a树得结点
	}
	if (a==	NULL) {
		return false;
	}
	if (a->data!=b->data) {
		return false;
	}
	else {
		return TrueSameTree(a->Lchild, b->Lchild) && TrueSameTree(a->Rchild, b->Rchild);	//递归判断
	}
}

//求二叉树最大深度
int DeepTree(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	int left = DeepTree(s->Lchild);	//递归左孩子
	int right = DeepTree(s->Rchild);
	return Max(left, right)+1;	//比较大的数返回
}
int Max(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}

// 求二叉树的最大深度
int Height(Tree* pRoot){	
	if (pRoot == NULL)		
		return; 	
	int left = Height(pRoot->Lchild);	
	int right = Height(pRoot->Rchild); 	
	return (left < right ? right: left)+1;
}


int maxDepth(Tree* s) {
	int max = 0;//存储子树的深度       
	int leftMax=0;        
	int rightMax=0;        
	if (s != NULL) {
		//如果当前子树不为空,非空树            
		max++;//深度加1            
		leftMax = maxDepth(s->Lchild);//左子树深度            
		rightMax = maxDepth(s->Rchild);//右子树深度            
		max += leftMax >= rightMax ? leftMax : rightMax;//当前子树的深度        
	}         
	return max;//返回当前子树的深度            
}

//求二叉树的最小深度
int MinDeepTree(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	if (s->Lchild==NULL&&s->Rchild==NULL) {
		return 1;	//只有根节点
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

//判断是不是平衡二叉树
bool BanlanceTree(Tree* s) {
	if (s == NULL) {
		return 0;
	}
	int left = BanlanceTree(s->Lchild) + 1;	//递归左孩子
	int right = BanlanceTree(s->Rchild) + 1;
	return Compare(left, right);	//比较大的数返回
}
bool Compare(int a, int b) {
	if (a - b <=1) {
		return true;
	}
	else {
		return false;
	}
}


//判断是不是子树
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


//求二叉树的镜像
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

//求对称二叉树
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

//二叉树的构建
Tree* CreatTree(Tree* s, int size) {
	int data;
	printf("请输入数据：\n");
	scanf("%d", &data);

	if (data ==0) {
		s = NULL;
	}
	else {
		//创建存储空间
		s = (Tree*)malloc(sizeof(Tree));
		s->data = data;	//结点数据等于data
		//递归创建
		CreatTree(s->Lchild, size);
		CreatTree(s->Rchild, size);
	}
	return s;
}

Tree* Find(Tree* s, int data) {
	if (s == NULL) { 
		return NULL; 
	} 	// 先去根找	
	if (s->data == data) {
		// 找到了		
		return s;	
	}	
	// 如果根没找到，去左子树找	
	Tree *result = Find(s->Lchild, data);	//递归
	if (result != NULL) {		
		// 左子树里找到了		
		return result;	
	} 	
	// 如果左子树没找到，去右子树找	
	result = Find(s->Rchild, data);
	if (result != NULL) {		
		return result;	}	
	else {		
		return NULL;	
	}
}

//获取结点个数
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

//求二叉树的高度 == 求深度
int Height(Tree* s) {
	if (s==NULL) {
		return 0;
	}
	int left = Height(s->Lchild);
	int right = Height(s->Rchild);
	return (left < right ? right : left) + 1;
}

//求叶子结点个数

// 获取二叉数中叶子节点的个数 
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
	if (K == 1) {	// 隐含的前提是, root != NULL
		return 1;
	}
	return GetKLevelNodeCount(s->Lchild, K - 1)
		+ GetKLevelNodeCount(s->Rchild, K - 1);
}


//前序中序确定二叉树
//四个参数是前序遍历的开始的的位置，前序遍历结束的位置，中序遍历开始位置，中序遍历结束的位置
Tree * build(int s1, int e1, int s2, int e2){    
	//根据前序遍历序列str1和中序遍历序列str2构建树，并返回树的根节点，    
	Tree* s	 = (Tree*)malloc(sizeof(Tree));	//创建根节点
	if (s) {
		s->Lchild = s->Rchild = NULL;
	}
	char str1[1024];	//放前序遍历
	char str2[1024];	//放中序遍历
	s->data = str1[s1];    
	int middleroot;    
	for (int i = s2; i<=e2;i++ ) {        
		if (str2[i]==str1[s1]) {            
			middleroot = i;//在中序遍历序列中找到根节点的下标；            
			break;       
		}    
	}    
	if (middleroot != s2){//说明左子树不为空        
		s->Lchild = build(s1 + 1, s1 + (middleroot - s2), s2, middleroot - 1);
	}   
	if (middleroot != e2) {//说明右子树不为空       
		s->Rchild = build(s1 + (middleroot - s2) + 1, e1, middleroot + 1, e2);
	}    
	return s;
}


//根据中序遍历和后序遍历确认一个树
Tree* buid1(char str1[2014], char str2[1024]) {
	//根据前序遍历序列str1和中序遍历序列str2构建树，并返回树的根节点，
	char str1[1024];	//放前序遍历
	char str2[1024];	//放中序遍历
	int length = strlen(str2);
	if (length == 0) {
		return NULL;
	}
	//1、根据后序，找到根的值，并且创建根节点
	char rootValue = str2[length - 1];
	Tree* root = new Tree(rootValue);

	//2、在中序中找到根的值所在的下标
	int leftSize = Find(str1, rootValue);

	//3、切出左子树的中序和后序
	char leftInorder[] = Arrays.copyOfRange(inorder, 0, leftSize);
	char leftPostorder[] = Arrays.copyOfRange(postorder, 0, leftSize);
	root.left = buildTree(leftInorder, leftPostorder);

	//4、切出右子树的中序和后序
	char[] rightInorder = Arrays.copyOfRange(inorder, leftSize + 1, inorder.length);
	char[] rightPostorder = Arrays.copyOfRange(postorder, leftSize, postorder.length - 1);
	root.right = buildTree(rightInorder, rightPostorder);

	return root;
}