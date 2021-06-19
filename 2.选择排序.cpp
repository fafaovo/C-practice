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

//选择排序
void SelectSort(int *arrp,int length)
{
	
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arrp[j] < arrp[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&arrp[min], &arrp[i]);
		}
	}
}


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
	
	long t_start = getSystemTime();
	cout << "选择排序前" << t_start << endl;
	SelectSort(Arr, size);
	long t_end = getSystemTime();
	cout << "选择排序后" << t_end << endl;

	cout << "选择排序" << MAX << "个元素,所需时间" << t_end - t_start << "毫秒" << endl;

	RrintArray(Arr, size);
	system("pause");
	return 0;
}