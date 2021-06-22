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

int* CreateArray()
{
	srand((unsigned int)time(NULL));
	int* arr = new int[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}

void PrintArr(int arr[], int length)
{
	for (int i = 0; i < length;i ++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//�ϲ��㷨
void Merge(int arr[], int start, int end, int mid, int temp[])
{
	//��һ����������
	int i_start = start;
	int i_end = mid;
	//�ڶ�����������
	int j_start = mid + 1;
	int j_end = end;

	int length = 0; // ��ʾ�����ռ��ж��ٸ�Ԫ��
	//�ϲ�������������
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	//�����������������һ��ֵ
	while (i_start <= i_end)
	{
		temp[length] = arr[i_start];
		length++;
		i_start++;
	}
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}
	//�Ѹ����ռ�����ݸ��ǵ�ԭ�ռ�
	for (int i = 0; i < length;i++)
	{		
		arr[start + i] = temp[i]; //�������ʼλ�ÿ�ʼ����
	}

}

//temp ��ʱ�ռ�
void MergeSort(int arr[], int start, int end,int temp[])
{
	if (start >= end)
	{
		return;
	}
	
	int mid = (start + end) / 2;
	//���� ���ߺ��Ұ��
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);
	//�ϲ�
	Merge(arr, start, end, mid, temp);

}



int main()
{
	//int * arr = CreateArray();
	int arr[MAX];
	int temp[MAX];
	int size = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size;
	}
	//int* temp = new int[MAX];
	
	PrintArr(arr, MAX);
	MergeSort(arr, 0, MAX - 1, temp);
	PrintArr(arr, MAX);

	return 0;
}
