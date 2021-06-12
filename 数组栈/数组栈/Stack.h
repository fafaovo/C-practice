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

//创建数组
StackNodeType* NewList();

//创建栈
pStack InitStack();

//入栈
void push(pStack myStack, StackNodeType data);

//出栈
void pop(pStack myStack);

//获取栈顶元素变量
StackNodeType top(pStack myStack);

//判断是否到栈底
int empty(pStack myStack);