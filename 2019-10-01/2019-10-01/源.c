#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"SeqList.h"
//数据结构

void Test1()
{
	SeqList s;
	InitSeqList(&s);
	CheckExpandCapacity(&s);
	PushBack(&s, 5);
	PushBack(&s, 7);
	PushBack(&s, 11);
	PushBack(&s, 3);
	PushBack(&s, 2);
	PushBack(&s, 5);
	PushBack(&s, 7);
	PushBack(&s, 23);
	PushBack(&s, 18);
	PrintSeqList(&s);
	PopBack(&s);
	PrintSeqList(&s);
	BubbleSort(&s);
	PrintSeqList(&s);
	Remove(&s, 3);
	PrintSeqList(&s);
	Insert(&s, 4, 99);
	PrintSeqList(&s);
}

int main()
{
	Test1();
	printf("\n");
	system("pause");
	return 0;
}

