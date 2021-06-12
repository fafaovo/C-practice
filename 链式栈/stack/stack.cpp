#include "stack.h"

//新建节点 
pListNode NewStackNode(NodeDataType Data)
{
	pListNode newnode = new ListNode();
	if (newnode == NULL)
	{
		cout << "栈元素创建失败" << endl;
		exit(-1);
	}
	newnode->next = NULL;
	newnode->Data = Data;
	return newnode;
}

//初始化栈的
pStack InitStack()
{
	pStack S = new Stack();
	if (S == NULL)
	{
		cout << "栈创建失败" << endl;
		exit(-1);
	}
	S->ListTop = NULL;
	S->size = 0;
	return S;
}


//入栈
void Push(pStack myStack, NodeDataType Data)
{
	if (myStack == NULL)
	{
		cout << "入栈失败" << endl;
		return;
	}
	pListNode newNode = NewStackNode(Data);
	newNode->next = myStack->ListTop;
	myStack->ListTop = newNode;
	myStack->size++;
}
//出栈
void Pop(pStack myStack)
{
	if (myStack == NULL)
		return;
	if (myStack->ListTop == NULL)
	{
		cout << "无元素可出栈" << endl;
		return;
	}
	pListNode cur = myStack->ListTop;
	myStack->ListTop = myStack->ListTop->next;
	delete cur;
	myStack->size--;
}

//获取栈顶元素
NodeDataType Top(pStack myStack)
{
	return myStack->ListTop->Data;
}

//万金油函数
int empty(pStack myStack)
{
	if (myStack->size == 0)
		return 0;
	return 1;
}
