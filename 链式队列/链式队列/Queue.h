#pragma once
#include <iostream>
using namespace std;

typedef int QueueNodeType;


//队列 先进先出 链表尾插和链表头删
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

//新建节点
pQueueNode NewQueueNode(QueueNodeType Data);

//新建队列
pQueue InitQueue();

//入队
void push(pQueue myQueue, QueueNodeType Data);

//出队
void pop(pQueue myQueue);

//获取队头元素
QueueNodeType top(pQueue myQueue);

//万用元素
int empty(pQueue myQueue);
