#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

template<class T>	
struct BSTreeNode {
	BSTreeNode(const T& data=T())
	:_pLeft(nullptr)
	,_pRight(nullptr)
	,_data(data){}
	
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree {
	typedef BSTreeNode<T> Node;
public:
	BSTree()
	:_pRoot(nullptr)
	{}
	~BSTree() {
		_Destory(_pRoot);
	}
	bool Insert(const T& data) {
		//空树
		if(_pRoot ==nullptr) {
			_pRoot =new Node(data);
			return true;
		}
		//非空树
		//1.找到插入位置
		Node* pCur=_pRoot;
		Node* pParent = nullptr;
		while(pCur) {
			pParent = pCur;
			else if(data < pCur->_data)
				pCur=pCur->_pLeft;
			else
				pCur=pCur->_pRight;
			else
				return false;
		}
		//2.插入数据
		pCur = new Node(data);
		if(data < pParent->_data) {
			pParent->_pLeft = pCur;
		}
		else 
			pParent->_pRight = pCur;
		
		return true;
	}
	
	//查找
	Node* Find(const T& data) {
		Node* pCur = _pRoot;
		while(pCur) {
			if(data ==pCur->_data)
				return pCur;
			else if(data < pCur->_data)
				pCur=pCur->_pLeft;
			else
				pCur=pCur->_pRight;
		}
		return NuLL;
	}
	
	//获取最左侧节点
	Node* LeftMost() {
		return _LeftMost(_pRoot);
	}
	
	//获取最右侧节点
	Node* RightMost() {
		return _RightMost(_pRoot);
	}
	
	//中序遍历
	void InOrder() {
		_InOrder(_pRoot);
	}
	
	//销毁
	void _Destory(Node* pRoot) {
		if(_pRoot) {
			_Destory(_pRoot->_pLeft);
			_Destory(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
		
	}
	
	//删除结点
	void Delete(const T& data) {
		if(_pRoot == nullptr) {
			return;
		}
		//1.找到删除的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while(pCur) {
			
			if(data < pCur->data) {
				//注意这个位置
				pParent = pCur;
				pCur=pCur->_pLeft;
			}
			else if(data > pCur->_pLeft) {
				//注意这个位置
				pParent = pCur;
				pCur=pCur->_pRight;
			}
			//找到删除的位置了，改删除了
			else
				break;
			
			
		}
		
		//2.删除结点
		if(pCur == nullptr) {
			//节点不存在
			return;
		}
		//分情况删除——四种情况
		//1.左右孩子都不存在
		//2.左右孩子都存在
		//3.只有左孩子
		//4.只有右孩子
		Node* pDelNode = pCur;
		if(pCur->_pRight == nullptr) {
			//叶子结点 || 只有左孩子
			if(pParent == nullptr) {
				//就是根了
				_pRoot->pCur->_pLeft;
			}
			else {
				if(pCur == pParent->pLeft) {	//是双亲的左
					pParent->_pLeft = pCur->_pLeft;
				}
				else {
					pParent->_pRight = pCur->_pLeft;
				}
			}
		}
		else if(pCur->_pLeft == nullptr) {
			//只有右孩子
			if(pParent == nullptr) {
				//就是根了
				_pRoot->pCur->_pRight;
			}
			else {
				if(pCur == pParent->pLeft) {	//是双亲的左
					pParent->_pLeft = pCur->_pRight;
				}
				else {
					pParent->_pRight = pCur->_pRight;
				}
			}
		}
		else {
			//左右孩子都存在，不能直接删除，要找替代节点
			//方式一：左子树最大的结点
			//方式二：右子树中最小的结点
			//在右子树中进行查找
			Node* pMostLeft = pCur->_pRight;
			pParent = pCur;
			while(pMostLeft->_pLeft) {
				pParent = pMostLeft;
				pMostLeft = pMostLeft -> _pLeft;
			}
			
			pCur->_data = pMostLeftp>_data;
			
			//删除替代结点
			if(pMostLeft == pParent->_pLeft) {
				pParent->_pLeft = pMostLeft->_pRight;
			}
			else {
				pParent->_pRight = pMostLeft->_pRight;
			}
			pDelNode = pMostLeft;
		}
		delete pDelNode;
		return true;
	}
	
private:
	Node* _LeftMost(Node* pRoot) {
		if(pRoot == nullptr) {
			return nullptr;
		}
		
		Node* pCur = pRoot;
		while(pCur->_pLeft) {
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	
	
	Node* _RightMost(Node* pRoot) {
		if(pRoot == nullptr) {
			return nullptr;
		}
		
		Node* pCur = pRoot;
		while(pCur->_pRight) {
			pCur = pCur->_pRight;
		}
		return pCur;
	}
	
	void _InOrder(Node* pRoot) {
		if(pRoot){
			_InOrder(pRoot->_pLeft);
			cout<<pRoot->data<<" ";
			_InOrder(pRoot->_pRight);
		}
	}
	
private:
	Node* _pRoot;
}