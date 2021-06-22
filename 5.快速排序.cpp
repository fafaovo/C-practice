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
	//����ͷ��β
	int pStart = start;
	int pEnd = end;
	int temp = arr[pStart]; //�����׼��
	if (pEnd > pStart) //��βָ�����ͷָ��ʱ
	{
		while (pEnd > pStart)
		{
			//��������ȥ�ұȻ�׼��С��
			while (pEnd > pStart && arr[pEnd] >= temp)
			{
				pEnd--;
			}
			if (pEnd > pStart)
			{
				arr[pStart] = arr[pEnd];
				pStart++;
			}
			//���������ұȻ�׼�����
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
		//�ѻ�׼���ŵ�i == j��λ��
		arr[pStart] = temp;
		//����벿�ֽ��п�������
		QuickSort(arr, start, pEnd - 1);
		//���Ұ벿�ֽ��п�������
		QuickSort(arr, pStart + 1, end);
	}
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
	printf("��������%d��Ԫ������ʱ��:%d����\n", MAX, t_end - t_start);
	PrintArray(Arr, size);


	system("pause");
	return 0;
}