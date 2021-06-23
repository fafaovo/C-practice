#include <iostream>
#include <sys\timeb.h>
#include <time.h>
using namespace std;


#define MAX 10


long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return (long)tb.time * 1000 + tb.millitm;
}

//打印
void PrintArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int* CreateArray()
{
	int *arr = new int[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}
void MySwap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

/*
	@param myArr 待调整的数组
	@param index 待调整的结点的下标
	@param length 数组长度
*/
void HeapAdjust(int arr[],int index,int length)
{
	int max = index;
	//保存左右孩子的数组下标
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	if (lchild < length && arr[lchild] > arr[max])
	{
		max = lchild;
	}
	if (rchild < length && arr[rchild] > arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		//交换两个结点
		MySwap(arr, max, index);
		HeapAdjust(arr, max,length);
	}
}
//堆排序
void HeapSort(int myArr[],int length)
{
	//这个循环用于初始化堆
	//length/2 是非叶子节点最后一个元素
	//-1是因为数组起始位置是0,而不是1
	for (int i = length / 2 - 1; i >= 0; i--)
	{ 
		HeapAdjust(myArr, i, length);
	}
	//堆顶和堆底逐渐交换
	for (int i = length - 1; i >= 0;i--)
	{
		MySwap(myArr, 0, i);
		HeapAdjust(myArr, 0, i);
	}
	
	
}

//快排
void QuickSort(int arr[], int start, int end)
{
	int p_start = start;
	int p_end = end;
	int scalar = arr[start];
	if (p_start < p_end)
	{
		while (p_start < p_end)
		{
			while (p_start < p_end && arr[p_end] > scalar)
				p_end--;
			if (p_start < p_end)
			{
				arr[p_start] = arr[p_end];
				p_start++;
			}
			while (p_start < p_end && arr[p_start] < scalar)
				p_start++;
			if (p_start < p_end)
			{
				arr[p_end] = arr[p_start];
				p_end--;
			}
		}
		arr[p_start] = scalar;
		QuickSort(arr, start, p_end-1);
		QuickSort(arr, p_start + 1, end);
	}
}

//希尔排序
void ShellSort(int arrp[], int length)
{
	int increase = length; //增量
	do 
	{
		increase = increase / 3 + 1;
		for (int i = 0; i < increase; i++)
		{
			for (int j = i + increase; j < length; j += increase)
			{
				if (arrp[j] < arrp[j - increase])
				{
					int temp = arrp[j];
					int k = j - increase;
					while (k >= 0 && temp < arrp[k])
					{
						arrp[k + increase] = arrp[k];
						k -= increase;
					}
					arrp[k + increase] = temp;
				}
			}
		}
	} while (increase > 1);
}



int main()
{
	int* arr = CreateArray();
	
	
	ShellSort(arr, MAX);
	PrintArray(arr, MAX);
	QuickSort(arr, 0, MAX - 1);
	HeapSort(arr, MAX);

	return 0;
}