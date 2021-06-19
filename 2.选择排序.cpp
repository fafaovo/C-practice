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

//��������
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//ѡ������
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


//��ӡ
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
	cout << "ѡ������ǰ" << t_start << endl;
	SelectSort(Arr, size);
	long t_end = getSystemTime();
	cout << "ѡ�������" << t_end << endl;

	cout << "ѡ������" << MAX << "��Ԫ��,����ʱ��" << t_end - t_start << "����" << endl;

	RrintArray(Arr, size);
	system("pause");
	return 0;
}