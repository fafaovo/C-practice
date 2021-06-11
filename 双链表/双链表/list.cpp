#include "list.h"

plistNode newListNode(listNodeData Data)
{
	plistNode newNode = new listNode();
	if (newNode == NULL)
		exit(-1);
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = Data;
	return newNode;
}

//��ʼ��
plistNode listInit()
{
	plistNode pHead = newListNode(0);
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}



//��ӡ
void listPrintf(plistNode pHead)
{
	if (pHead == NULL)
		return;
	if (pHead->next == pHead)
	{
		cout << "��Ԫ�ؿɴ�ӡ" << endl;
		return;
	}
	plistNode cur = pHead->next;
	while (cur != pHead)
	{
		cout << cur->data << "->";
		cur = cur->next;
	}
	cout << endl;
}

//����
int ListSeek(plistNode pHead, listNodeData pos)
{
	if (pHead == NULL)
		return -1;
	if (pHead->next == pHead)
	{
		cout << "��Ԫ�ؿɴ�ӡ" << endl;
		return -1;
	}
	if (pHead->next->next == pHead)
	{
		if (pHead->data == pos)
		{
			return 1;
		}
		return -1;
	}
	int count = 0;
	plistNode cur = pHead->next;
	while (cur->next != pHead)
	{
		count++;
		if (cur->data == pos)
		{
			return count;
		}
		cur = cur->next;
	}
	return -1;
}

//ָ��λ�ò���
void ListInset(plistNode pHead, int Num, listNodeData Data)
{
	if (pHead == NULL)
		return;
	plistNode newNode = newListNode(Data);
	int count = 0;
	plistNode cur = pHead->next;
	while (true)
	{	
		if (count == Num)
		{
			plistNode curPrev = cur->prev;
			curPrev->next = newNode;
			newNode->prev = curPrev;
			cur->prev = newNode;
			newNode->next = cur;
			return;
		}
		else
		{
			if (cur == pHead)
			{
				cout << "����num����" << endl;
				return;
			}
			count++;
			cur = cur->next;
		}	
	}
}

//ָ��λ��ɾ��
void ListErase(plistNode pHead, int Num)
{
	if (pHead == NULL)
		return;
	plistNode cur = pHead->next;
	int count = 0;
	while (true)
	{	
		if (count == Num)
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;
			return;
		}
		else
		{
			if (cur == pHead)
			{
				cout << "ɾ����numֵ����" << endl;
				return;
			}
			count++;
			cur = cur->next;
		}
		
	}
}

void ListPushBack(plistNode pHead, listNodeData Data)
{
	ListInset(pHead, 0 ,Data);
}
void ListPopBack(plistNode pHead)
{
	ListErase(pHead, 0);
}
int ListSize(plistNode pHead)
{
	plistNode cur = pHead;
	int listSize = 0;
	while (cur->next != pHead)
	{
		listSize++;
		cur = cur->next;
	}
	return listSize;
}
void ListPushFront(plistNode pHead, listNodeData Data)
{
	
	ListInset(pHead, ListSize(pHead), Data);
}
void ListPopFront(plistNode pHead)
{
	ListErase(pHead, ListSize(pHead)-1);
}