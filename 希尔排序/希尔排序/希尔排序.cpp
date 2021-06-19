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


//��������
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

void ShellSort(int arrp[], int length)
{
	
	int increase = length; //����
	do 
	{
		increase = increase / 3 + 1; //ȷ�����������
		for (int i = 0; i < increase; i++) //i ȷ��ÿһ��ĵ�һ��Ԫ��
		{
			//��������
			for (int j = i + increase; j < length; j += increase) //j Ϊÿһ���±� ����Ϊincrease
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
			//�����������
		}
	} while (increase > 1); // ��inc����1��ʱ��Ҳ��ִ��һ��
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
	printf("ϣ������%d��Ԫ������ʱ��:%d����\n", MAX, t_end - t_start);
	//RrintArray(Arr, size);


	system("pause");
	return 0;
}