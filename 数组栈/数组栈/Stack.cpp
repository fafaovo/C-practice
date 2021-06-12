#include "Stack.h"

//创建数组
StackNodeType* NewList()
{
	StackNodeType* newlist = new StackNodeType[List_Max];
	if (newlist == NULL)
	{
		exit(-1);
	}
	return newlist;
}

//创建栈
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

//入栈
void push(pStack myStack, StackNodeType data)
{
	myStack->ListStack[++myStack->StackTop] = data;
}

//出栈
void pop(pStack myStack)
{
	if (myStack->StackTop == -1)
	{
		cout << "无元素可出栈" << endl;
	}
	else
	{
		myStack->StackTop--;
	}	
}

//获取栈顶元素
StackNodeType top(pStack myStack)
{
	return myStack->ListStack[myStack->StackTop];
}

//万金油函数
int empty(pStack myStack)
{
	if (myStack->StackTop == -1)
		return 0;
	return 1;
}