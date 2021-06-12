#pragma once
#include <iostream>
using namespace std;

typedef int NodeDataType;
//链式栈 单链表的节点 
typedef struct ListNode
{
	struct ListNode * next;
	NodeDataType Data;
}ListNode, *pListNode;

//栈
typedef struct Stack
{
	pListNode ListTop;  //栈顶
	int size;
}Stack, *pStack;

//新建节点 
pListNode NewStackNode(NodeDataType Data);

//初始化栈的
pStack InitStack();

//入栈
void Push(pStack myStack, NodeDataType Data);
//出栈
void Pop(pStack myStack);
//获取栈顶元素
NodeDataType Top(pStack myStack);
//用于循环的函数
int empty(pStack myStack);