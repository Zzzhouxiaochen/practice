//红黑树：最长路径的个数 不会 多最短路径的两倍
// 性质：
// 1. 每个结点不是红色就是黑色 比特科技
// 2. 根节点是黑色的  
// 3. 如果一个节点是红色的，则它的两个孩子结点是黑色的  
// 4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均 包含相同数目的黑色结点  
// 5. 每个叶子结点都是黑色的(此处的叶子结点指的是空结点)


template<class ValueType> 
class RBTree {    
	//……    
	bool Insert(const ValueType& data)    
	{  
		PNode& pRoot = GetRoot();        
		if (nullptr == pRoot)        
		{            
		pRoot = new Node(data, BLACK);  // 根的双亲为头节点 
		pRoot->_pParent = _pHead;  
		_pHead->_pParent = pRoot;  
		} 
		else  
		{   
		// 1. 按照二叉搜索的树方式插入新节点
		  // 2. 检测新节点插入后，红黑树的性质是否造到破坏， 
		  //    若满足直接退出，否则对红黑树进行旋转着色处理 
		}
		 
		   
		// 根节点的颜色可能被修改，将其改回黑色  
		pRoot->_color = BLACK;   
		_pHead->_pLeft = LeftMost();   
		_pHead->_pRight = RightMost();    
		return true;  
	} 
private:
	PNode& GetRoot(){ 
		return _pHead->_pParent;
	}    // 获取红黑树中小节点，即左侧节点   
	PNode LeftMost();    // 获取红黑树中大节点，即右侧节点  
	PNode RightMost(); 
private:   
	PNode _pHead;
}; 



bool Insert(const ValueType& data)
{
	PNode& pRoot = GetRoot();
	// 1. 按照二叉搜索的树方式插入新节点
	if (nullptr == pRoot)
	{
		pRoot = new Node(data, BLACK);
		// 根的双亲为头节点
		pRoot->_pParent = _pHead;
	}
	else
	{
		// 按照二叉搜索树的特性，找节点在红黑树中的插入位置
		PNode pCur = pRoot;
		PNode pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		// 插入新节点
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;
		// 更新新节点的双亲
		pCur->_pParent = pParent;
		// 2. 检测新节点插入后，红黑树的性质是否造到破坏，
		// 若满足直接退出，否则对红黑树进行旋转着色处理
		//..............................这块需要进一步操作
	}
	// 根节点的颜色可能被修改，将其改回黑色
	pRoot->_color = BLACK;
	_pHead->_pLeft = LeftMost();
	_pHead->_pRight = RightMost();
	return true;
}




 // 新节点插入后，如果其双亲节点的颜色为空色，则违反性质3：不能有连在一起的红色结点    
 while(pParent && RED == pParent->_color) {        
	// 注意：grandFather一定存在        
	// 因为pParent存在，且不是黑色节点，则pParent一定不是根，则其一定有双亲        
	PNode grandFather = pParent->_pParent;        
	// 先讨论左侧情况        
	if(pParent == grandFather->_pLeft) {            
		PNode unclue = grandFather->_pRight;            
		// 情况三：叔叔节点存在，且为红          
		if(unclue && RED == unclue->_color)  {            
			pParent->_color = BLACK;      
			unclue->_color = BLACK;      
			grandFather->_color = RED;     
			pCur = grandFather;           
			pParent = pCur->_pParent;       
		}      
		else  {      
			// 情况五：叔叔节点不存在，或者叔叔节点存在且为黑        
			if(pCur == pParent->_pRight)  {               
				_RotateLeft(pParent);          
				swap(pParent, pCur);         
			}
			// 情况五后转化成情况四  
			grandFather->_color = RED; 
			pParent->_color = BLACK;     
			_RotateRight(grandFather);   
		}     
	}  
	else  {     
		// 右侧请学生们自己动手完成    
	}  
} 


bool _IsRBTree(PNode pRoot, size_t blackCount, size_t pathBlack) {
	if (nullptr == pRoot)
		return true;
	if (BLACK == pRoot->_color)
		pathBlack++;
	
	PNode pParent = pRoot->_pParent;
	if (pParent && pRoot->_color == RED && RED == pParent->_color) {
		cout << "违反性质3：有连在一起的红色节点" << endl;
		return false;
	}
	if (pRoot->_pLeft == nullptr && nullptr == pRoot->_pRight)  {
		if (blackCount != pathBlack)  {
			cout << "违反性质4：路径中黑色节点的个数不相同" << endl;
			return false;
		}
	}
	return _IsRBTree(pRoot->_pLeft, blackCount, pathBlack) 
			&& _IsRBTree(pRoot->_pRight, blackCount, pathBlack);
}
