#include "stack.h"

//�½��ڵ� 
pListNode NewStackNode(NodeDataType Data)
{
	pListNode newnode = new ListNode();
	if (newnode == NULL)
	{
		cout << "ջԪ�ش���ʧ��" << endl;
		exit(-1);
	}
	newnode->next = NULL;
	newnode->Data = Data;
	return newnode;
}

//��ʼ��ջ��
pStack InitStack()
{
	pStack S = new Stack();
	if (S == NULL)
	{
		cout << "ջ����ʧ��" << endl;
		exit(-1);
	}
	S->ListTop = NULL;
	S->size = 0;
	return S;
}


//��ջ
void Push(pStack myStack, NodeDataType Data)
{
	if (myStack == NULL)
	{
		cout << "��ջʧ��" << endl;
		return;
	}
	pListNode newNode = NewStackNode(Data);
	newNode->next = myStack->ListTop;
	myStack->ListTop = newNode;
	myStack->size++;
}
//��ջ
void Pop(pStack myStack)
{
	if (myStack == NULL)
		return;
	if (myStack->ListTop == NULL)
	{
		cout << "��Ԫ�ؿɳ�ջ" << endl;
		return;
	}
	pListNode cur = myStack->ListTop;
	myStack->ListTop = myStack->ListTop->next;
	delete cur;
	myStack->size--;
}

//��ȡջ��Ԫ��
NodeDataType Top(pStack myStack)
{
	return myStack->ListTop->Data;
}

//����ͺ���
int empty(pStack myStack)
{
	if (myStack->size == 0)
		return 0;
	return 1;
}
