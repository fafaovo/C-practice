#include <iostream>
using namespace std;
#include <stdlib.h>

#define List_MAX 40
//˳�����Ҫ ˳���ṹ�� ��ɾ��� ��ʼ������

typedef int CListtype;

typedef struct CList
{
	CListtype* MyList;
	int size;
} CList, *PCList;

//��ʼ��
PCList InitCList1();

//����λ�ò��� �б�λ�ò���
bool SeqListInsert(PCList List, int pos, CListtype item);

//��ӡ˳���
bool seqListPrint(PCList List);

//����λ��ɾ�� 
bool SeqListErase(PCList List, int pos);

//�ͷ�
bool DeleteSeqList(PCList List);

//����
int SeqListFind(PCList List, CListtype item);

//�޸�
int SeqListModify(PCList List, CListtype pos, CListtype item);