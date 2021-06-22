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


void QuickSort(int arr[], int start, int end)
{
	//定义头和尾
	int pStart = start;
	int pEnd = end;
	int temp = arr[pStart]; //定义基准树
	if (pEnd > pStart) //当尾指针大于头指针时
	{
		while (pEnd > pStart)
		{
			//从右向左去找比基准数小的
			while (pEnd > pStart && arr[pEnd] >= temp)
			{
				pEnd--;
			}
			if (pEnd > pStart)
			{
				arr[pStart] = arr[pEnd];
				pStart++;
			}
			//从左向右找比基准数大的
			while (pEnd > pStart && arr[pStart] < temp)
			{
				pStart++;
			}
			if (pEnd > pStart)
			{
				arr[pEnd] = arr[pStart];
				pEnd--;
			}
		}
		//把基准树放到i == j的位置
		arr[pStart] = temp;
		//对左半部分进行快速排序
		QuickSort(arr, start, pEnd - 1);
		//对右半部分进行快速排序
		QuickSort(arr, pStart + 1, end);
	}
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


int main()
{
	int Arr[MAX];
	int size = sizeof(Arr) / sizeof(Arr[0]);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		Arr[i] = rand() % size;
	}

	long t_start = getSystemTime();

	QuickSort(Arr, 0, size - 1);

	long t_end = getSystemTime();
	printf("快速排序%d个元素所需时间:%d毫秒\n", MAX, t_end - t_start);
	PrintArray(Arr, size);


	system("pause");
	return 0;
}