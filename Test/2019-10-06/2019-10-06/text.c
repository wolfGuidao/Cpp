#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "Stack.h" //栈
#include "Tree.h"  //树

//栈基本操作
void stackvoid() {
	Stack pStack;
	StackInit(&pStack); //初始化
	//StackDestroy(pStack);//销毁
	StackPush(&pStack, 1); //入栈
	StackDataType a = StackTop(&pStack);
	printf("把1入栈，当前栈顶元素：%d\n ", a);

	StackPush(&pStack, 3);
	a = StackTop(&pStack);
	printf("把3入栈，当前栈顶元素：%d \n", a);

	StackPush(&pStack, 5);
	a = StackTop(&pStack);
	printf("把5入栈，当前栈顶元素%d\n", a);

	StackPop(&pStack); //出栈
	a = StackTop(&pStack);
	printf("出栈，当前栈顶元素%d\n ", a);

	int b = StackSize(&pStack);  //栈长度
	int c = StackFull(&pStack);  //栈满
	int d = StackEmpty(&pStack); //栈空
	printf("栈长度：%d\n", b);
	printf("栈满否（1为满，0为未满）：%d\n", c);
	printf("栈空否（1为空，0为未空）：%d\n", d);
}

void ErChaShu() 
{
	printf("测试代码\n");
	BiTree T;
	T = (BiTree)malloc(sizeof(BiTreeNode));

	printf("请给二叉树按照先序方式依次输入结点的值(空结点为#):\n");
	CreateBiTree(&T);


	printf("先序方式遍历结果：\n");
	PreOrderTravel(T);
	printf("\n");

	printf("中序方式遍历结果：\n");
	InOrderTravel(T);
	printf("\n");

	printf("后序方式遍历结果：\n");
	TailOrderTravel(T);
	printf("\n");
}

int main() {
	//stackvoid();
	ErChaShu();
	system("pause");
	return 0;
}