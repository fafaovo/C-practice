#include "Queue.h"


//新建节点
pQueueNode NewQueueNode(QueueNodeType Data)
{
	pQueueNode NewNode = new QueueNode();
	NewNode->Data = Data;
	NewNode->next = NULL;
	return NewNode;
}

//新建队列
pQueue InitQueue()
{
	pQueue myQueue = new Queue();
	myQueue->size = 0;
	myQueue->frontNode = myQueue->tailNode = NULL;
	return myQueue;
}

//入队
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
//出队
void pop(pQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "无元素可出队" << endl;
		return;
	}
	pQueueNode next = myQueue->frontNode->next;
	delete myQueue->frontNode;
	myQueue->frontNode = next;
	myQueue->size--;
}

//获取队头元素
QueueNodeType top(pQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "无元素" << endl;
		return -1;
	}
	return myQueue->frontNode->Data;
}

//万用元素
int empty(pQueue myQueue)
{
	if (myQueue->size == 0)
		return 0;
	return 1;
}