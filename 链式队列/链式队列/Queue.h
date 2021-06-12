#pragma once
#include <iostream>
using namespace std;

typedef int QueueNodeType;


//���� �Ƚ��ȳ� ����β�������ͷɾ
typedef struct QueueNode
{
	struct QueueNode * next;
	QueueNodeType Data;
}QueueNode,*pQueueNode;

typedef struct Queue
{
	pQueueNode frontNode;
	pQueueNode tailNode;
	int size;
}Queue, *pQueue;

//�½��ڵ�
pQueueNode NewQueueNode(QueueNodeType Data);

//�½�����
pQueue InitQueue();

//���
void push(pQueue myQueue, QueueNodeType Data);

//����
void pop(pQueue myQueue);

//��ȡ��ͷԪ��
QueueNodeType top(pQueue myQueue);

//����Ԫ��
int empty(pQueue myQueue);
