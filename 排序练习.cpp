

//直接插排   ￥
//时间复杂度---O(n^2)   最坏O(n^2)  平均O(n^2)  最好O(n)
//空间O(1)
//稳定性---稳定


void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j;
		int k = array[i];
		//为array[i]找位置
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= k)  // 1 2 3       //array[j]>=k   是逆序  3 2 1  
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

//直接插排测试
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




//希尔排序（缩小增量排序）  大间隔 》小 》1 》停止
//时间复杂度---O(n^1.3-n^2)  空间复杂度O(1)
//稳定性：不稳定
//最好的gap(间隔)  是  gap / 3 + 1;

int gap = size;
gap = gap / 3 + 1;

void InsertSortWithGap(int array[], int size, int gap)
{
	for (int i = gap; i < size; i++)
	{
		int j;
		int k = array[i];

		//为array[i]找位置
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (array[j] <= k)  // 1 2 3       //array[j]>=k   是逆序  3 2 1  
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



//直接选择排序
//每次选最小的数
//时间复杂度O(n^2)
//稳定：不稳定
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;  //最小下标
		for (int j = i + 1; j < size - i; j++)
		{
			if (array[j] < array[min])
				min = j;
		}


		//交换最小的数到合适的位置上去
		Swap(array + min, array + i);
	}
}

void Swap(int* a, int* b)  //交换函数
{
	int t = *a;
	*a = *b;
	*b = t;
}

//进化版
//一次找到最大最小的
//时间复杂度O(n^2)
void SelectSortOP(int array[], int size)
{
	int minSpace = 0;  //用来放找的的最小数的下标
	int maxSpace = size - 1; //用来方找到最大数的小标
	while (minSpace < maxSpace)
	{
		int min = minSpace;//假设最小的数在小标minSpace
		int max = maxSpace;//假设最大的数在小标maxSpace
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

//冒泡排序 
//时间复杂度---最好O(n),最坏，平均O(n^2) 稳定
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