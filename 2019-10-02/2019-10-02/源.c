#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
//几种链表的基本操作
//约瑟夫环问题（单链表实现）

//无头单向非循环链表的实现
#include"Slist.h"
int main()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);
	SListPushBack(&list, 8);
	SListPushBack(&list, 9);
	SListPrint(&list);//5 4 3 2 1 6 7 8 9
	SLNode *ret = SListFind(&list, 2);
	SListInsertAfter(ret, 19);
	SListPrint(&list);//5 4 3 2 19 1 6 7 8 9
	SListInsertBefore(&list, ret, 99);
	SListPrint(&list);//5 4 3 99 2 19 1 6 7 8 9
	SListPopFront(&list);
	SListPrint(&list);//4 3 99 2 19 1 6 7 8 9
	SListPopBack(&list);
	SListPrint(&list);//4 3 99 2 19 1 6 7 8
	SListEraseAfter(ret);
	SListPrint(&list);//4 3 99 2 1 6 7 8
	SlistDestory(&list);
	system("pause");
	return 0;
}