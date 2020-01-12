#include"DQueue.h"

void QueueInit(Queue *pQueue)//初始化
{
	pQueue->front = pQueue->rear = NULL;
}

static QNode * CreateNode(QDataType data)//创建节点
{
	QNode *node= (QNode *)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}

void QueuePush(Queue *pQueue, QDataType data)//入队
{
    QNode * node=CreateNode(data);
	if (pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = node;
	}
	pQueue->rear->next  = node;
	pQueue->rear = node;
}

void QueuePop(Queue *pQueue)//出队
{
	if (pQueue->front == NULL)
	{
		pQueue->rear = NULL;
	}
	QNode * cur = pQueue->front;
	pQueue->front = cur->next;
	free(cur);
}

QDataType QueueFront(Queue *pQueue)//查看队首元素
{
	return pQueue->front->data;
}

int QueueSize(const Queue *pQueue)//元素个数
{
	QNode *cur=pQueue->front ;
	int count = 0;
	while (cur )
	{
		count++;
		cur = cur->next;
	}
	return count;
}