#pragma once
#include <iostream>
using namespace std;

typedef int listNodeData;

typedef struct listNode
{
	struct listNode * prev;
	struct listNode * next;
	listNodeData data;
}listNode, *plistNode;

//初始化
plistNode listInit();
//打印
void listPrintf(plistNode pHead);

//指定位置插入 
void ListInset(plistNode pHead, int Num, listNodeData Data);
//指定位置删除u
void ListErase(plistNode pHead, int Num);

//查找
int ListSeek(plistNode pHead, listNodeData pos);

//尾插尾删 头插头删 
void ListPushBack(plistNode pHead, listNodeData Data);
void ListPopBack(plistNode pHead);
void ListPushFront(plistNode pHead, listNodeData Data);
void ListPopFront(plistNode pHead);
