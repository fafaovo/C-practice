#pragma once
#include <iostream>
using namespace std;

typedef int SListDataType;

typedef struct SList
{
	struct SList* next;
	SListDataType Date;
}SList, *pSList;

//��ӡ 
void SListPrint(pSList pHead);
//β�� βɾ
void SListPushBack(pSList* pHead, SListDataType Date);
void SlistPopBack(pSList* pHead);
void SListPushFront(pSList* pHead, SListDataType Date);
void SlistPopFront(pSList* pHead);

//ָ��λ�ò��� ָ��λ��ɾ��
void SListAppointPushBack(pSList* pHead, SListDataType x, int pos);
void SListAppointPopBack(pSList* pHead, int pos);

