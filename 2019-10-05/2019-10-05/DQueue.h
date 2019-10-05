#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QNode 
{
	QDataType data;
	struct QNode *next;
}	QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}	Queue;

void QueueInit(Queue *pQueue);//初始化

static QNode * CreateNode(QDataType data);//创建节点

void QueuePush(Queue *pQueue, QDataType data);//入队

void QueuePop(Queue *pQueue);//出队

QDataType QueueFront(Queue *pQueue);//查看队首元素

int QueueSize(const Queue *pQueue);//元素个数