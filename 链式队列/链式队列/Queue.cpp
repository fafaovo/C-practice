#include "Queue.h"


//�½��ڵ�
pQueueNode NewQueueNode(QueueNodeType Data)
{
	pQueueNode NewNode = new QueueNode();
	NewNode->Data = Data;
	NewNode->next = NULL;
	return NewNode;
}

//�½�����
pQueue InitQueue()
{
	pQueue myQueue = new Queue();
	myQueue->size = 0;
	myQueue->frontNode = myQueue->tailNode = NULL;
	return myQueue;
}

//���
void push(pQueue myQueue, QueueNodeType Data)
{
	pQueueNode newNode = NewQueueNode(Data);
	if (myQueue->size == 0)
	{
		myQueue->frontNode = myQueue->tailNode = newNode;

	}
	else
	{
		myQueue->tailNode->next = newNode;
		myQueue->tailNode = newNode;
	}
	myQueue->size++;
}
//����
void pop(pQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "��Ԫ�ؿɳ���" << endl;
		return;
	}
	pQueueNode next = myQueue->frontNode->next;
	delete myQueue->frontNode;
	myQueue->frontNode = next;
	myQueue->size--;
}

//��ȡ��ͷԪ��
QueueNodeType top(pQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "��Ԫ��" << endl;
		return -1;
	}
	return myQueue->frontNode->Data;
}

//����Ԫ��
int empty(pQueue myQueue)
{
	if (myQueue->size == 0)
		return 0;
	return 1;
}