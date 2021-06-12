#pragma once
#include <iostream>
using namespace std;

typedef int StackNodeType;
#define List_Max 10

typedef struct Stack
{
	StackNodeType* ListStack;
	int StackTop;
}Stack, *pStack;

//��������
StackNodeType* NewList();

//����ջ
pStack InitStack();

//��ջ
void push(pStack myStack, StackNodeType data);

//��ջ
void pop(pStack myStack);

//��ȡջ��Ԫ�ر���
StackNodeType top(pStack myStack);

//�ж��Ƿ�ջ��
int empty(pStack myStack);