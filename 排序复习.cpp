#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


//排序的七大排序
//1，冒泡排序
void bubbling(int a[],int length) {	//a:装数据的数组	length:数据的长度
	int i = 0;
	for (i = 1; i < length; i++) {	//length是数据长度	//数据要变换多少趟
		int j = 0;
		for (j = 0; j < length - 1;j++) {	//数据内部的交换
			if (a[j]>a[j+1]) {	//交换数据
				int x = 0;
				x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
		}
	}
}

//2.插入排序
//插入数据
void Inister(int a[], int length) {	//a:装数据的数组	length:数据的长度
	int i = 0;
	for (i = 1; i < length;i++) {	//第二个数据开始，因为第一个数据不需要找位置
		int j = 0;
		int k = a[i];
		//给数据k找位置
		for (j = i - 1; j >= 0;j--) {
			if (a[j] <= k) {	// 1 2 3这样的顺序,由小到大
				break;
			}
			else {
				a[j + 1] = a[j];
			}
		}
		a[j + 1] = k;
	}
}

//3.希尔排序
void Hill(int a[], int length, int grep) {	
	//三个参数：存放数据的数组，数据长度，间隔
	//数据长度的确定可以:
	//int length = sizeof(array) / sizeof(array[0]);
	int grep = length / 3 + 1;	//	确定间隔数
	while (grep) {
		int i = 0;
		for (i = grep; i < length;i++) {		//查找数据的循环
			int j = 0;
			int k = a[i];
		//给数据找位置
			for (j = i - grep; j >= 0; j = j - grep) {
				if (a[j] <= k) {	// 1 2 3这样的顺序,由小到大
					break;
				}
				else {
					a[j + grep] = a[j];
				}
			}
		a[j + grep] = k;
		}
	grep--;	//间隔减1
	}
}

//4.直接选择排序
void choose(int a[], int length) {
	//两个参数：存放数据的数组，数据长度
	int i = 0;
	for (i = 0; i < length; i++) {	//确定调整色位置
		int j = 0;
		int min = i;
		for (j = i + 1; j < length - i;j++) {	//无序数找到最小的
			if (a[min]>a[j]) {	//最小的下标可能会变很多次，我们加一个变量min
				min = j;	//找到最小的下标
			}
		}
		//找到之后最小的下标交换和正在调整的数据
		Swap(a+min, a+i);
	}
}
void Swap(int* a, int* b) {
	int arr = *a;
	*a = *b;
	*b = arr;
}


//5.堆排序
void Heap(int a[], int length) {
	//两个参数：存放数据的数组，数据长度
	//1.建大堆
	CreatHeap();	//这里没有写  后面再写
	//2.开始排序
	for (int i = 0; i < length - 1;i++) {
		Swap(&a[0], a + length - i);	//交换根节点和最后一个数据
		AdjustDown(a,length-1-i,0);	//向下调整，保证调整成一直是大堆
	}
}
void Swap(int* a, int* b) {
	int arr = *a;
	*a = *b;
	*b = arr;
}


void AdjustDown(int array[], int length,int root) {	//核心：向下调整
	//三个参数：存放数据的数组，数据长度，要调整的数据
	while (1) {
		//看root，根节点就是0
		//判断root是否是叶子节点		
		//因为堆是完全二叉树 ，没有左孩子一定没有有孩子		
		//堆是顺序存储，找到左孩子的下标，如果左孩子下标越界，则没有左孩子		
		int left = 2 * root + 1;		//这个要记住的，这个是固定的	/* 数组从0索引，因此左孩子索引为i * 2 + 1 */
		if (left >= length) {  //不要漏掉等于					
			//是叶子结点			
			return;		
		} 		
		//找到左右孩子中最小的一个		
		//这里一定有左孩子，判断是否有右孩子		
		int right = 2 * root + 2;	//这个要记住的，这个是固定的	/* 数组从0索引，因此右孩子索引为i * 2 + 2 */
		int min = left;	
		if (right < length  //有右孩子			
			&&array[right] < array[left])  	{
			//右孩子值小于左孩子			
			//&& array[right] > array[left])  //大堆					
			min = right;		
		} 		//比较array[min]  array[root]		
		if (array[min] <= array[root])			
			//if (array[min] >= array[root])  //大堆		
		{			
			return;		
		} 		
		//交换		
		int t = array[root];		
		array[min] = array[root];		
		array[min] = t; 		
		//继续向下调整，以min作为结点 		
		AdjustDown(array, length, min);
		}
} 


//快速排序取值分开的三种方法
//Hover法
int Hover(int array[], int right, int left) {	//left，right是数据的下标
	int  begin = left;
	int end = right;
	//基准值是array[right]	//选择区间的最右边的数据作为基准值
	while (begin < end) {	//终止条件
		if (begin<end&&array[begin]<=array[right]) {	//左边值小于等于右边的值
			begin++;
		}
		//这时候就卡住了，就走右边
		if (begin<end&&array[end]>=array[right]) {
			end++;
		}
		Swap(array + begin, array + end);
	}
	//区间被分成小，基准，大
	Swap(array + begin, array + right);
	//返回当前基准值
	return array[right];
}

//挖坑法
//时间复杂度 O(1)
int Hole(int array[], int left, int right) {
	//left  right  是数组的下标
	int begin = left;
	int end = right;
	int hole = array[right];  //基准值
	while (begin < end) {	//优先走左边
		while (begin < end&&array[begin] <= hole) {
			begin++;
		}
		//卡住了,填坑
		array[end] = array[begin];
		//走右边
		while (begin < end&&array[end] >= hole) {
			end++;
		}
		//右边也卡住了
		array[begin] = array[end];
	}
	//区间被分成小，大，基准
	Swap(array + begin, &hole);
	//返回当前基准值
	return hole;
}


//前后下标法
int BeforeAfter(int array[], int left, int right) {
	//left  right  是数组的下标
	int i = left;
	int d = left;
	while (i != right) {	//i先走
		while (array[i] >= array[right]) {	//i停止条件
			i++;
		}
		//交换array[i],array[d]
		Swap(array + d, array + i);
		i++;
		d++;
	}
	Swap(array + d, array + i);
	//返回当前基准值
	return array[right];

	/*
	//for循环的
	for (int i = left; i < right; i++) {
		if (array[i] < array[right]) {
			Swap(array + d, array + i);
			d++;
		}
	}
	Swap(array + d, array + i);
	//返回当前基准值
	return array[right];
	*/
}

//三数取中方法，返回合适的下标
int PickMid(int array[], int left, int right) {
	int mid = (left + right) / 2;
	if (array[left] > array[right] && array[left] > array[mid]) {
		if (array[mid] > array[right]) {
			return mid;
		}
		else {
			return right;
		}
	}
	else if (array[mid] > array[right]) {
		if (array[left] > array[right]) {
			return left;
		}
		else {
			return right;
		}
	}
	else
	if (array[mid] > array[left]) {
		return mid;
	}
	else {
		return left;
	}
}

//快排完整代码
//空间复杂度  log n --- n
//递归调用的深度 （二叉树的高度）
void __QuickSort(int array[], int left, int right)  {
	//基本以右边为基准
	//终止条件 size==1 ||  size ==0
	//left==right  剩余一个数
	//left>right  区间内没有数
	if (left == right) {
		return;
	}

	if (left == right) {
		return;
	}
	//选三个数取中
	int pivot_index = PickMid(array, left, right);
	Swap(array + pivot_index, array + right);

	//  基准值所在下标 
	int div; //  比基准值小的数放到基准值左侧     比基准值大的数放到基准值右侧
	div = Hover(array, left, right);  //遍历array[left,right]，把小的放左，大的放右边
	//div = Hole(array, left, right);  //遍历array[left,right]，把小的放左，大的放右边
	//div = BeforeAfter(array, left, right);  //遍历array[left,right]，把小的放左，大的放右边

	//类似二叉树的前序遍历
	__QuickSort(array, left, div - 1);  //分治算法
	__QuickSort(array, div + 1, right);
}


//归并排序
void __MergeSort(int array[], int left, int right, int* extra) {
	if (right == left + 1) {
		//剩余一个数，有序
		return;
	}
	if (left >= right) {
		//区间没有数
		return;
	}

	int mid = left + (right - left) / 2;
	//区间分成左右两个小区间
	//[left,mid)
	//[mid,right)
	//先把两个小区间进行排序，分治算法，递归解决
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	//左右小区间已经有序
	//合并有序数组
	Merge(array, left, mid, right, extra);
}

//合并有序数组
//array[left,mid)
//array[mid,right)
//时间复杂度 O(n)  
//空间复杂度 O(n)
void Merge(int array[], int left, int mid, int right, int* extra) {
	//需要一个额外的空间去实现
	int size = right - left;
	int* extra = (int*)malloc(sizeof(int)* size);

	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid&&right_index < right) {	
		if (array[left_index] <= array[right_index]) {
			extra[extra_index] = array[left_index];
			left_index++;
		}
		else {
			extra[extra_index] = array[right_index];
			right_index++;
		}
		extra_index++;
	}
	//将左边元素填充
	while (left_index < mid) {
		extra[extra_index++] = array[left_index];
	}
	//将右边元素填充
	while (right_index < mid) {
		extra[extra_index++] = array[right_index];
	}

	for (int i = 0; i < size; i++) {
		array[left + i] = extra_index[i];
	}
	free(extra);
}



//分组归并
void _Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp){	
	int index = begin1;	
	int i = begin1, j = begin2;	//注意:当划分的区间足够小时,begin1==end1,begin2==end2	
	while (i <= end1&&j <= end2){		
		if (a[i]<=a[j])			
			tmp[index++] = a[i++];		
		else			
			tmp[index++] = a[j++];	
	}	
	//将左边元素填充到tmp中	
	while (i <= end1)		
		tmp[index++] = a[i++];	
	//将右边元素填充的tmp中	
	while (j <= end2)		
		tmp[index++] = a[j++];	
	//将tmp中的数据拷贝到原数组对应的序列区间	//注意:end2-begin1+1	
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}
