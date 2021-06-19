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

//插入排序
void InserSort(int* arr, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			int j = i - 1;
			while (j >= 0 && temp < arr[j])
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}
	}
}



//交换函数
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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
	InserSort(Arr, size);
	RrintArray(Arr, size);


	system("pause");
	return 0;
}