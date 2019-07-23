#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;


//������ߴ�����
//1��ð������
void bubbling(int a[],int length) {	//a:װ���ݵ�����	length:���ݵĳ���
	int i = 0;
	for (i = 1; i < length; i++) {	//length�����ݳ���	//����Ҫ�任������
		int j = 0;
		for (j = 0; j < length - 1;j++) {	//�����ڲ��Ľ���
			if (a[j]>a[j+1]) {	//��������
				int x = 0;
				x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
		}
	}
}

//2.��������
//��������
void Inister(int a[], int length) {	//a:װ���ݵ�����	length:���ݵĳ���
	int i = 0;
	for (i = 1; i < length;i++) {	//�ڶ������ݿ�ʼ����Ϊ��һ�����ݲ���Ҫ��λ��
		int j = 0;
		int k = a[i];
		//������k��λ��
		for (j = i - 1; j >= 0;j--) {
			if (a[j] <= k) {	// 1 2 3������˳��,��С����
				break;
			}
			else {
				a[j + 1] = a[j];
			}
		}
		a[j + 1] = k;
	}
}

//3.ϣ������
void Hill(int a[], int length, int grep) {	
	//����������������ݵ����飬���ݳ��ȣ����
	//���ݳ��ȵ�ȷ������:
	//int length = sizeof(array) / sizeof(array[0]);
	int grep = length / 3 + 1;	//	ȷ�������
	while (grep) {
		int i = 0;
		for (i = grep; i < length;i++) {		//�������ݵ�ѭ��
			int j = 0;
			int k = a[i];
		//��������λ��
			for (j = i - grep; j >= 0; j = j - grep) {
				if (a[j] <= k) {	// 1 2 3������˳��,��С����
					break;
				}
				else {
					a[j + grep] = a[j];
				}
			}
		a[j + grep] = k;
		}
	grep--;	//�����1
	}
}

//4.ֱ��ѡ������
void choose(int a[], int length) {
	//����������������ݵ����飬���ݳ���
	int i = 0;
	for (i = 0; i < length; i++) {	//ȷ������ɫλ��
		int j = 0;
		int min = i;
		for (j = i + 1; j < length - i;j++) {	//�������ҵ���С��
			if (a[min]>a[j]) {	//��С���±���ܻ��ܶ�Σ����Ǽ�һ������min
				min = j;	//�ҵ���С���±�
			}
		}
		//�ҵ�֮����С���±꽻�������ڵ���������
		Swap(a+min, a+i);
	}
}
void Swap(int* a, int* b) {
	int arr = *a;
	*a = *b;
	*b = arr;
}


//5.������
void Heap(int a[], int length) {
	//����������������ݵ����飬���ݳ���
	//1.�����
	CreatHeap();	//����û��д  ������д
	//2.��ʼ����
	for (int i = 0; i < length - 1;i++) {
		Swap(&a[0], a + length - i);	//�������ڵ�����һ������
		AdjustDown(a,length-1-i,0);	//���µ�������֤������һֱ�Ǵ��
	}
}
void Swap(int* a, int* b) {
	int arr = *a;
	*a = *b;
	*b = arr;
}


void AdjustDown(int array[], int length,int root) {	//���ģ����µ���
	//����������������ݵ����飬���ݳ��ȣ�Ҫ����������
	while (1) {
		//��root�����ڵ����0
		//�ж�root�Ƿ���Ҷ�ӽڵ�		
		//��Ϊ������ȫ������ ��û������һ��û���к���		
		//����˳��洢���ҵ����ӵ��±꣬��������±�Խ�磬��û������		
		int left = 2 * root + 1;		//���Ҫ��ס�ģ�����ǹ̶���	/* �����0�����������������Ϊi * 2 + 1 */
		if (left >= length) {  //��Ҫ©������					
			//��Ҷ�ӽ��			
			return;		
		} 		
		//�ҵ����Һ�������С��һ��		
		//����һ�������ӣ��ж��Ƿ����Һ���		
		int right = 2 * root + 2;	//���Ҫ��ס�ģ�����ǹ̶���	/* �����0����������Һ�������Ϊi * 2 + 2 */
		int min = left;	
		if (right < length  //���Һ���			
			&&array[right] < array[left])  	{
			//�Һ���ֵС������			
			//&& array[right] > array[left])  //���					
			min = right;		
		} 		//�Ƚ�array[min]  array[root]		
		if (array[min] <= array[root])			
			//if (array[min] >= array[root])  //���		
		{			
			return;		
		} 		
		//����		
		int t = array[root];		
		array[min] = array[root];		
		array[min] = t; 		
		//�������µ�������min��Ϊ��� 		
		AdjustDown(array, length, min);
		}
} 


//��������ȡֵ�ֿ������ַ���
//Hover��
int Hover(int array[], int right, int left) {	//left��right�����ݵ��±�
	int  begin = left;
	int end = right;
	//��׼ֵ��array[right]	//ѡ����������ұߵ�������Ϊ��׼ֵ
	while (begin < end) {	//��ֹ����
		if (begin<end&&array[begin]<=array[right]) {	//���ֵС�ڵ����ұߵ�ֵ
			begin++;
		}
		//��ʱ��Ϳ�ס�ˣ������ұ�
		if (begin<end&&array[end]>=array[right]) {
			end++;
		}
		Swap(array + begin, array + end);
	}
	//���䱻�ֳ�С����׼����
	Swap(array + begin, array + right);
	//���ص�ǰ��׼ֵ
	return array[right];
}

//�ڿӷ�
//ʱ�临�Ӷ� O(1)
int Hole(int array[], int left, int right) {
	//left  right  ��������±�
	int begin = left;
	int end = right;
	int hole = array[right];  //��׼ֵ
	while (begin < end) {	//���������
		while (begin < end&&array[begin] <= hole) {
			begin++;
		}
		//��ס��,���
		array[end] = array[begin];
		//���ұ�
		while (begin < end&&array[end] >= hole) {
			end++;
		}
		//�ұ�Ҳ��ס��
		array[begin] = array[end];
	}
	//���䱻�ֳ�С���󣬻�׼
	Swap(array + begin, &hole);
	//���ص�ǰ��׼ֵ
	return hole;
}


//ǰ���±귨
int BeforeAfter(int array[], int left, int right) {
	//left  right  ��������±�
	int i = left;
	int d = left;
	while (i != right) {	//i����
		while (array[i] >= array[right]) {	//iֹͣ����
			i++;
		}
		//����array[i],array[d]
		Swap(array + d, array + i);
		i++;
		d++;
	}
	Swap(array + d, array + i);
	//���ص�ǰ��׼ֵ
	return array[right];

	/*
	//forѭ����
	for (int i = left; i < right; i++) {
		if (array[i] < array[right]) {
			Swap(array + d, array + i);
			d++;
		}
	}
	Swap(array + d, array + i);
	//���ص�ǰ��׼ֵ
	return array[right];
	*/
}

//����ȡ�з��������غ��ʵ��±�
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

//������������
//�ռ临�Ӷ�  log n --- n
//�ݹ���õ���� ���������ĸ߶ȣ�
void __QuickSort(int array[], int left, int right)  {
	//�������ұ�Ϊ��׼
	//��ֹ���� size==1 ||  size ==0
	//left==right  ʣ��һ����
	//left>right  ������û����
	if (left == right) {
		return;
	}

	if (left == right) {
		return;
	}
	//ѡ������ȡ��
	int pivot_index = PickMid(array, left, right);
	Swap(array + pivot_index, array + right);

	//  ��׼ֵ�����±� 
	int div; //  �Ȼ�׼ֵС�����ŵ���׼ֵ���     �Ȼ�׼ֵ������ŵ���׼ֵ�Ҳ�
	div = Hover(array, left, right);  //����array[left,right]����С�ķ��󣬴�ķ��ұ�
	//div = Hole(array, left, right);  //����array[left,right]����С�ķ��󣬴�ķ��ұ�
	//div = BeforeAfter(array, left, right);  //����array[left,right]����С�ķ��󣬴�ķ��ұ�

	//���ƶ�������ǰ�����
	__QuickSort(array, left, div - 1);  //�����㷨
	__QuickSort(array, div + 1, right);
}


//�鲢����
void __MergeSort(int array[], int left, int right, int* extra) {
	if (right == left + 1) {
		//ʣ��һ����������
		return;
	}
	if (left >= right) {
		//����û����
		return;
	}

	int mid = left + (right - left) / 2;
	//����ֳ���������С����
	//[left,mid)
	//[mid,right)
	//�Ȱ�����С����������򣬷����㷨���ݹ���
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	//����С�����Ѿ�����
	//�ϲ���������
	Merge(array, left, mid, right, extra);
}

//�ϲ���������
//array[left,mid)
//array[mid,right)
//ʱ�临�Ӷ� O(n)  
//�ռ临�Ӷ� O(n)
void Merge(int array[], int left, int mid, int right, int* extra) {
	//��Ҫһ������Ŀռ�ȥʵ��
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
	//�����Ԫ�����
	while (left_index < mid) {
		extra[extra_index++] = array[left_index];
	}
	//���ұ�Ԫ�����
	while (right_index < mid) {
		extra[extra_index++] = array[right_index];
	}

	for (int i = 0; i < size; i++) {
		array[left + i] = extra_index[i];
	}
	free(extra);
}



//����鲢
void _Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp){	
	int index = begin1;	
	int i = begin1, j = begin2;	//ע��:�����ֵ������㹻Сʱ,begin1==end1,begin2==end2	
	while (i <= end1&&j <= end2){		
		if (a[i]<=a[j])			
			tmp[index++] = a[i++];		
		else			
			tmp[index++] = a[j++];	
	}	
	//�����Ԫ����䵽tmp��	
	while (i <= end1)		
		tmp[index++] = a[i++];	
	//���ұ�Ԫ������tmp��	
	while (j <= end2)		
		tmp[index++] = a[j++];	
	//��tmp�е����ݿ�����ԭ�����Ӧ����������	//ע��:end2-begin1+1	
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}
