#pragma once
#include <iostream>
using namespace std;

typedef int SListDataType;

typedef struct SList
{
	struct SList* next;
	SListDataType Date;
}SList, *pSList;

//打印 
void SListPrint(pSList pHead);
//尾插 尾删
void SListPushBack(pSList* pHead, SListDataType Date);
void SlistPopBack(pSList* pHead);
void SListPushFront(pSList* pHead, SListDataType Date);
void SlistPopFront(pSList* pHead);

//指定位置插入 指定位置删除
void SListAppointPushBack(pSList* pHead, SListDataType x, int pos);
void SListAppointPopBack(pSList* pHead, int pos);

