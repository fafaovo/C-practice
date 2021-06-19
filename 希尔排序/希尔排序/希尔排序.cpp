#include <iostream>
#include <sys\timeb.h>
#include <time.h>
using namespace std;

#define MAX 100000

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


//打印
void RrintArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ShellSort(int arrp[], int length)
{
	
	int increase = length; //增量
	do 
	{
		increase = increase / 3 + 1; //确定分组的增量
		for (int i = 0; i < increase; i++) //i 确定每一组的第一个元素
		{
			//插入排序
			for (int j = i + increase; j < length; j += increase) //j 为每一组下标 增量为increase
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
			//插入排序结束
		}
	} while (increase > 1); // 当inc等于1的时候也能执行一次
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
	ShellSort(Arr, size);
	long t_end = getSystemTime();
	printf("希尔排序%d个元素所需时间:%d毫秒\n", MAX, t_end - t_start);
	//RrintArray(Arr, size);


	system("pause");
	return 0;
}