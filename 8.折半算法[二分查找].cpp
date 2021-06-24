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

int binarySearch(int arr[], int length,int num)
{
	int start = 0;
	int end = length - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == num)
			return mid;
		else if (arr[mid] > num)
			end = mid - 1;
		else if (arr[mid] < num)
			start = mid + 1;
	}
	return -1;
}

void QuickSort(int arr[], int start, int end)
{
	int p_start = start;
	int p_end = end;
	int inter = arr[start];
	if (p_start < p_end)
	{
		while (p_start < p_end)
		{
			while (p_start < p_end && arr[p_end] > inter)
				p_end--;
			if (p_start < p_end)
				arr[p_start++] = arr[p_end];
			while (p_start < p_end && arr[p_start] < inter)
				p_start++;
			if (p_start < p_end)
				arr[p_end--] = arr[p_start];
		}
		arr[p_start] = inter;
		QuickSort(arr, start, p_end - 1);
		QuickSort(arr, p_start + 1, end);
	}
}

void PrintArray(int arr[], int length)
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
	PrintArray(Arr, size);
	QuickSort(Arr, 0,size-1);
	PrintArray(Arr, size);
	int num = binarySearch(Arr, size, 9);
	if (num != -1)
	{
		cout << Arr[num] << endl;
	}


	return 0;
}