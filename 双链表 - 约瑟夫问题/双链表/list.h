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

//查看双链表中有多少个元素
int sizeClist(plistNode pHead);

//约瑟夫问题
listNodeData Josephus(plistNode pHead,int a);

//约瑟夫问题 有一个圈 圈内用x个节点 从第一个开始数数 数到第N个时 删除节点 然后让这个节点的下一个节点继续数第N个 
//直到就剩下最后一个元素