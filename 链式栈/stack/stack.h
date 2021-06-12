#pragma once
#include <iostream>
using namespace std;

typedef int NodeDataType;
//��ʽջ ������Ľڵ� 
typedef struct ListNode
{
	struct ListNode * next;
	NodeDataType Data;
}ListNode, *pListNode;

//ջ
typedef struct Stack
{
	pListNode ListTop;  //ջ��
	int size;
}Stack, *pStack;

//�½��ڵ� 
pListNode NewStackNode(NodeDataType Data);

//��ʼ��ջ��
pStack InitStack();

//��ջ
void Push(pStack myStack, NodeDataType Data);
//��ջ
void Pop(pStack myStack);
//��ȡջ��Ԫ��
NodeDataType Top(pStack myStack);
//����ѭ���ĺ���
int empty(pStack myStack);