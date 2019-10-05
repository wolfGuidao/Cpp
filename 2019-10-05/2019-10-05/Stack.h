#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_SIZE 100
typedef int StackDataType;
typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int pop;
   
}Stack;

void StackInit(Stack* pStack);//初始化

void StackDestroy(Stack* pStack);//销毁

void StackPush(Stack* pStack, StackDataType data);//入栈

void StackPop(Stack* pStack);//出栈

StackDataType StackTop(Stack* pStack);//查看栈顶元素

int StackSize(const Stack *pStack);//栈长度

int StackFull(const Stack *pStack);//栈满

int StackEmpty(const Stack *pStack);//栈空
