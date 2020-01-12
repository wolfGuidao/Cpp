#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"Stack.h"//栈
#include"DQueue.h"//队列

//栈基本操作
void stackvoid()
{
	Stack pStack;
	StackInit(&pStack);//初始化
	//StackDestroy(pStack);//销毁
	StackPush(&pStack, 1);//入栈
	StackDataType a = StackTop(&pStack);
	printf("%d ", a);

	StackPush(&pStack, 3);
	a = StackTop(&pStack);
	printf("%d ", a);

	StackPush(&pStack, 5);
	a=StackTop(&pStack);
	printf("%d\n", a);

	StackPop(&pStack);//出栈
	 a = StackTop(&pStack);
	printf("%d ", a);

	int b= StackSize(&pStack);//栈长度
	//int c= StackFull(&pStack);//栈满
	//int d= StackEmpty(&pStack);//栈空
	printf("%d", b);
	//printf("%d", c);
	//printf("%d", d);
}

//队列基本操作
void DuiLie()
{
	Queue pQueue;
	QueueInit(&pQueue);//初始化

	QueuePush(&pQueue, 1);//入队
	QDataType a= QueueFront(&pQueue);//查看队首元素
	printf("%d ", a);

	QueuePush(&pQueue, 2);//入队
	 a = QueueFront(&pQueue);//查看队首元素
	printf("%d ", a);

	QueuePush(&pQueue, 3);//入队
	a = QueueFront(&pQueue);//查看队首元素
	printf("%d\n", a);

	int b= QueueSize(&pQueue);//元素个数
	printf("%d ", b);

	QueuePop(&pQueue);//出队
	b = QueueSize(&pQueue);//元素个数
	printf("%d ", b);
}

int main()
{
	//stackvoid();
	DuiLie();
	system("pause");
	return 0;
}