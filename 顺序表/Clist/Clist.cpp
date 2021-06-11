#include "Clist.h"

PCList InitCList1()
{
	PCList MyCList = new CList;
	MyCList->MyList = new CListtype[List_MAX * sizeof(CListtype)];
	MyCList->size = 0;
	return MyCList;
}


bool SeqListInsert(PCList List, int pos, CListtype item)
{
	if (List == NULL)
	{
		cout << "˳���Ϊ��" << endl;
		return false;
	}		
	if (pos > List->size || pos < 0)
	{
		cout << "����λ�ò���ȷ" << endl;
		return false;
	}
	if (pos == 0 && List->size == 0)
	{
		List->MyList[0] = item;
		List->size++;
		return true;
	}
	int end = List->size - 1;
	while (end >= pos)
	{
		List->MyList[end + 1] = List->MyList[end];
		end--;
	}
	List->MyList[pos] = item;
	List->size++;
	return true;
}

bool seqListPrint(PCList List)
{
	if (List->size == 0)
	{
		cout << "��Ԫ�ش�ӡ" << endl;
		return false;
	}
	for (int i = 0; i < List->size; i++)
	{
		printf("%d ", List->MyList[i]);
	}
	cout << endl;
	return true;
}

bool SeqListErase(PCList List, int pos)
{
	if (List->size == 0 || List == NULL)
	{
		cout << "�޷�ɾ��.˳���Ϊ��" << endl;
		return false;
	}
	if (pos > List->size || pos < 0)
	{
		cout << "ɾ��λ�ò���ȷ" << endl;
		return false;
	}
	int start = pos;
	while (start < List->size-1)
	{
		List->MyList[start] = List->MyList[start + 1];
		start++;
	}
	List->size--;
	return true;

}

bool DeleteSeqList(PCList List)
{
	delete[] List->MyList;
	List->MyList = NULL;
	List->size = NULL;
	delete List;
	List = NULL;
	return true;
}

int SeqListFind(PCList List, CListtype item)
{
	if (List == NULL || List->size == 0)
		return false;
	for (int i = 0; i < List->size; i++)
	{
		if (List->MyList[i] == item)
		{
			return i;
		}
	}
	return -1;
}

int SeqListModify(PCList List, CListtype pos, CListtype item)
{
	if (List == NULL || List->size == 0)
		return false;
	int cur = SeqListFind(List, pos);
	List->MyList[cur] = item;
	return true;
}


