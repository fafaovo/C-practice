#include "Stack.h"

//��������
StackNodeType* NewList()
{
	StackNodeType* newlist = new StackNodeType[List_Max];
	if (newlist == NULL)
	{
		exit(-1);
	}
	return newlist;
}

//����ջ
pStack InitStack()
{
	pStack myStack = new Stack();
	if (myStack == NULL)
	{
		exit(-1);
	}
	myStack->ListStack = NewList();
	myStack->StackTop = -1;
	return myStack;
}

//��ջ
void push(pStack myStack, StackNodeType data)
{
	myStack->ListStack[++myStack->StackTop] = data;
}

//��ջ
void pop(pStack myStack)
{
	if (myStack->StackTop == -1)
	{
		cout << "��Ԫ�ؿɳ�ջ" << endl;
	}
	else
	{
		myStack->StackTop--;
	}	
}

//��ȡջ��Ԫ��
StackNodeType top(pStack myStack)
{
	return myStack->ListStack[myStack->StackTop];
}

//����ͺ���
int empty(pStack myStack)
{
	if (myStack->StackTop == -1)
		return 0;
	return 1;
}