

//ֱ�Ӳ���   ��
//ʱ�临�Ӷ�---O(n^2)   �O(n^2)  ƽ��O(n^2)  ���O(n)
//�ռ�O(1)
//�ȶ���---�ȶ�


void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j;
		int k = array[i];
		//Ϊarray[i]��λ��
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= k)  // 1 2 3       //array[j]>=k   ������  3 2 1  
			{
				break;

			}
			else
			{
				array[j + 1] = array[j];
			}
		}
		array[j + 1] = k;

	}
}

//ֱ�Ӳ��Ų���
int main()
{
	int array[] = { 9, 4, 3, 8, 5, 7 };
	InsertSort(array, 6);
	for (int i = 0; i <= 5; i++)
	{
		printf("%2d", array[i]);
	}
	system("pause");
	return 0;
}




//ϣ��������С��������  ���� ��С ��1 ��ֹͣ
//ʱ�临�Ӷ�---O(n^1.3-n^2)  �ռ临�Ӷ�O(1)
//�ȶ��ԣ����ȶ�
//��õ�gap(���)  ��  gap / 3 + 1;

int gap = size;
gap = gap / 3 + 1;

void InsertSortWithGap(int array[], int size, int gap)
{
	for (int i = gap; i < size; i++)
	{
		int j;
		int k = array[i];

		//Ϊarray[i]��λ��
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (array[j] <= k)  // 1 2 3       //array[j]>=k   ������  3 2 1  
			{
				break;

			}
			else
			{
				array[j + gap] = array[j];
			}
		}
		array[j + gap] = k;

	}
}



//ֱ��ѡ������
//ÿ��ѡ��С����
//ʱ�临�Ӷ�O(n^2)
//�ȶ������ȶ�
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;  //��С�±�
		for (int j = i + 1; j < size - i; j++)
		{
			if (array[j] < array[min])
				min = j;
		}


		//������С���������ʵ�λ����ȥ
		Swap(array + min, array + i);
	}
}

void Swap(int* a, int* b)  //��������
{
	int t = *a;
	*a = *b;
	*b = t;
}

//������
//һ���ҵ������С��
//ʱ�临�Ӷ�O(n^2)
void SelectSortOP(int array[], int size)
{
	int minSpace = 0;  //�������ҵĵ���С�����±�
	int maxSpace = size - 1; //�������ҵ��������С��
	while (minSpace < maxSpace)
	{
		int min = minSpace;//������С������С��minSpace
		int max = maxSpace;//������������С��maxSpace
		for (int i = minSpace + 1; i <= maxSpace; i++)
		{
			if (array[i] < array[min])
				i = min;
			if (array[i]>array[max])
				max = i;
		}

		Swap(array + min, array + minSpace);
		if (minSpace == max)
		{
			max = min;
		}
		Swap(array + max, array + maxSpace);

		minSpace++;
		maxSpace--;
	}

}

//ð������ 
//ʱ�临�Ӷ�---���O(n),���ƽ��O(n^2) �ȶ�
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}
	}
}