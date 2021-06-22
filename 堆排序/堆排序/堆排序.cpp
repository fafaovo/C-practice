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

//��ӡ
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
	@param myArr ������������
	@param index �������Ľ����±�
	@param length ���鳤��
*/
void HeapAdjust(int arr[],int index,int length)
{
	int max = index;
	//�������Һ��ӵ������±�
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
		//�����������
		MySwap(arr, max, index);
		HeapAdjust(arr, max,length);
	}
}
//������
void HeapSort(int myArr[],int length)
{
	//���ѭ�����ڳ�ʼ����
	//length/2 �Ƿ�Ҷ�ӽڵ����һ��Ԫ��
	//-1����Ϊ������ʼλ����0,������1
	for (int i = length / 2 - 1; i >= 0; i--)
	{ 
		HeapAdjust(myArr, i, length);
	}
	//�Ѷ��Ͷѵ��𽥽���
	for (int i = length - 1; i >= 0;i--)
	{
		MySwap(myArr, 0, i);
		HeapAdjust(myArr, 0, i);
	}
	
	
}

int main()
{
	int* arr = CreateArray();
	
	HeapSort(arr, MAX);
	PrintArray(arr, MAX);
	
	return 0;
}