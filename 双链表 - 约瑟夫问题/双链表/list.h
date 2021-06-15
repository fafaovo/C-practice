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

//��ʼ��
plistNode listInit();
//��ӡ
void listPrintf(plistNode pHead);

//ָ��λ�ò��� 
void ListInset(plistNode pHead, int Num, listNodeData Data);
//ָ��λ��ɾ��u
void ListErase(plistNode pHead, int Num);

//����
int ListSeek(plistNode pHead, listNodeData pos);

//β��βɾ ͷ��ͷɾ 
void ListPushBack(plistNode pHead, listNodeData Data);
void ListPopBack(plistNode pHead);
void ListPushFront(plistNode pHead, listNodeData Data);
void ListPopFront(plistNode pHead);

//�鿴˫�������ж��ٸ�Ԫ��
int sizeClist(plistNode pHead);

//Լɪ������
listNodeData Josephus(plistNode pHead,int a);

//Լɪ������ ��һ��Ȧ Ȧ����x���ڵ� �ӵ�һ����ʼ���� ������N��ʱ ɾ���ڵ� Ȼ��������ڵ����һ���ڵ��������N�� 
//ֱ����ʣ�����һ��Ԫ��