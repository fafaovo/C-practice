#include <iostream>
#include <time.h>
#include <sys/timeb.h>
using namespace std;

#define MAX 10

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return (long)tb.time * 1000 + tb.millitm;
}

//交换函数
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//冒泡排序
void BubbleSort(int *arrp, int length)
{
	int flag = 0;
	for (int i = 0; i < length- 1 && flag == 0; i++)
	{
		flag = 1;
		for (int k = 0; k < length - i - 1; k++)
		{
			if (arrp[k] > arrp[k + 1])
			{
				flag = 0;
				Swap(&arrp[k], &arrp[k+1]);
			}
		}
	}
}

//冒泡排序改进版
//如果有一次循环并没有执行交换，那么说明他有序了

//打印
void RrintArray(int* arr, int length)
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
	//冒泡排序
	long t_start = getSystemTime();
	cout << "排序前" << t_start  << endl;
	BubbleSort(Arr, size);

	long t_end = getSystemTime();
	cout << "排序后" << t_end << endl;
	cout << "冒泡排序" << MAX << "个元素,所需时间" << t_end - t_start << "毫秒" << endl;
	RrintArray(Arr,size);
	system("pause");
	return 0;
}