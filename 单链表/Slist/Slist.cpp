#include "Slist.h"

//�½��ڵ�
pSList newSlistItem(SListDataType Date)
{
	pSList newlist = new SList();
	newlist->next = NULL;
	newlist->Date = Date;
	return newlist;
}

//��ӡ
void SListPrint(pSList pHead)
{
	if (pHead == NULL)
	{
		cout << "��Ԫ�ؿɴ�ӡ" << endl;
		return;
	}
	pSList cur = pHead;
	if (pHead->next == NULL)
	{
		cout << cur->Date << "->";
		return;
	}	
	while (cur)
	{
		cout << cur->Date << "->";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

void SListAppointPushBack(pSList* pHead, SListDataType x, int pos)
{
	pSList newList = newSlistItem(x);
	if (*pHead == NULL && pos < 0)
	{
		*pHead = newList;
	}
	else
	{
		int count = 0;
		if (count == pos)
		{
			newList->next = *pHead;
			*pHead = newList;
			return;
		}
		pSList cur = *pHead;
		pSList prev = NULL;
		while (cur != NULL)
		{
			if (count == pos)
				break;
			else
			{
				prev = cur;
				count++;
				cur = cur->next;
			}
		}
		if (count == pos)
		{
			newList->next = cur;
			prev->next = newList;
			return;
		}
		if (count < pos)
		{
			cout << "����λ�ù���" << endl;
		}
	}
}
void SListAppointPopBack(pSList* pHead, int pos)
{
	if (*pHead == NULL && pos < 0)
		return;
	if ((*pHead)->next == NULL)
	{
		delete *pHead;
		*pHead = NULL;
		return;
	}
	pSList cur = *pHead;
	pSList prev = NULL;
	int count = 0;
	if (count == pos)
	{
		*pHead = cur->next;
		delete cur;
		return;
	}
	while (cur)
	{
		if (count == pos)
		{
			break;
		}
		else
		{
			count++;
			prev = cur;
			cur = cur->next;
		}
	}
	if (count == pos && cur != NULL)
	{
		prev->next = cur->next;
		delete cur;
		return;
	}
	if (pos >= count)
	{
		cout << "ɾ��λ�ù���" << endl;
	}
}


//β��
void SListPushBack(pSList* pHead, SListDataType Date)
{
	pSList newList = newSlistItem(Date);
	if (*pHead == NULL)
	{	
		newList->next = *pHead;
		*pHead = newList;
	}
	else
	{
		pSList cur = *pHead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newList;
	}
}



void SlistPopBack(pSList* pHead)
{
	if (*pHead == NULL)
	{
		return;
	}
	if ((*pHead)->next == NULL)
	{
		delete *pHead;
		*pHead = NULL;
		return;
	}
	pSList cur = *pHead;
	pSList prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	delete cur;
}

void SListPushFront(pSList* pHead, SListDataType Date)
{
	pSList newlist =  newSlistItem(Date);
	newlist->next = *pHead;
	*pHead = newlist;
}
void SlistPopFront(pSList* pHead)
{
	if (*pHead == NULL)
		return;
	pSList next = (*pHead)->next;
	delete *pHead;
	*pHead = next;
}