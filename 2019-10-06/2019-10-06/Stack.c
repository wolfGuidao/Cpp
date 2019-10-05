#include "Stack.h"

void StackInit(Stack* pStack) //初始化
{
	pStack->pop = 0;
}

void StackDestroy(Stack* pStack) //销毁
{
	pStack->pop = 0;
}

void StackPush(Stack* pStack, StackDataType data) //入栈
{
	assert(pStack != NULL);
	pStack->array[pStack->pop] = data;
	pStack->pop++;
}

void StackPop(Stack* pStack) //出栈
{
	assert(pStack != NULL);
	pStack->pop--;
}


StackDataType StackTop(Stack* pStack) //查看在栈顶元素
{
	assert(pStack != NULL);
	return pStack->array[pStack->pop - 1];
}

int StackSize(const Stack* pStack) //栈长度
{
	return pStack->pop;
}

int StackFull(const Stack* pStack) //栈满
{
	if (pStack->pop >= MAX_SIZE) {
		return 1;
	}
	else
	{
		return 0;
	}
}

int StackEmpty(const Stack* pStack) //栈空
{
	if (pStack->pop == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}