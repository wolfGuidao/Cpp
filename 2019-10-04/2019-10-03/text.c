#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"SeqList.h"//顺序表
#include"Slist.h"//无头单向非循环链表
#include"Dlist.h"//带头双向循环链表

void HeBing()
{
	DList dlist1;
	DList dlist2;
	DListInit(&dlist1);
	DListInit(&dlist2);
	DListPushFront(&dlist1, 9);
	DListPushFront(&dlist1, 7);
	DListPushFront(&dlist1, 5);
	DListPushFront(&dlist1, 3);
	DListPushFront(&dlist1, 1);
	DListPushFront(&dlist2, 10);
	DListPushFront(&dlist2, 8);
	DListPushFront(&dlist2, 6);
	DListPushFront(&dlist2, 4);
	DListPushFront(&dlist2, 2);
	DListPrint(&dlist1);//1 3 5 7 9
	DListPrint(&dlist2);//2 4 6 8 10
	DListMerge(&dlist1, &dlist2);
	DListPrint(&dlist1);//1 2 3 4 5 6 7 8 9 10
}

void WFD()
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
}

void YXD()
{
	DList dlist;
	DListInit(&dlist);
	DListPushFront(&dlist, 1);
	DListPushFront(&dlist, 2);
	DListPushFront(&dlist, 3);
	DListPushFront(&dlist, 4);
	DListPushFront(&dlist, 5);
	DListPushFront(&dlist, 6);
	DListPrint(&dlist);
	DListPushBack(&dlist, 6);
	DListPushBack(&dlist, 7);
	DListPushBack(&dlist, 8);
	DListPushBack(&dlist, 9);
	DListPrint(&dlist);
	DListNode *ret = DListFind(&dlist, 1);
	DListInsertFront(ret, 99);
	DListPrint(&dlist);
	DListPopFront(&dlist);
	DListPrint(&dlist);
	DListPopBack(&dlist);
	DListPrint(&dlist);
	DListErase(ret);
	DListPrint(&dlist);
	DListDestroy(&dlist);
}
void YSF()
{
	int m = 0;
	int n = 0;
	printf("请输入m个人,n为数(n<m)");
	scanf("%d%d", &m, &n);
	YueSheFu(m, n);

}

void SXB()
{
		SeqList L;
		DataType data;
		//初始化顺序表
		InitList(&L);
		//在表中插入元素
		printf("依次在表中插入元素(1,2,3,4,5)：\n");
		InsList(&L, 1, 1);
		InsList(&L, 2, 2);
		InsList(&L, 3, 3);
		InsList(&L, 4, 4);
		InsList(&L, 5, 5);

		//打印表中元素
		printf("表中元素有：\n");
		PrintList(&L);
		//头插
		printf("在表头依次插入元素，6,7:\n");
		PushFront(&L, 6);
		PushFront(&L, 7);
		//尾插
		printf("在表尾依次插入元素，8,9:\n");
		PushBack(&L, 8);
		PushBack(&L, 9);
		printf("表中元素有：\n");
		PrintList(&L);
		//头删
		printf("头删一个元素:\n");
		PopFront(&L);
		//尾删
		printf("尾删一个元素:\n");
		PopBack(&L);
		//输出表中第4个元素值
		PrintList(&L);
		printf("表中第4个元素值为：\n%d\n", GetData(&L, 4));
		//查找表中第 i个元素的位置
		printf("元素2在表中的位置为：\n");
		printf("%d\n", Locate(&L, 2));
		//删除表中第2个元素对应的值
		printf("删除表中第2个元素：%d\n", DelList(&L, 2, &data));
		printf("顺序表的长度为：%d\n", LengthList(&L));
		printf("表中元素为：\n");
		PrintList(&L);
		//printf("删除的元素值为：%d\n", data);
		//清空顺序表
		ClearList(&L);
		PrintList(&L);
}

int main()
{
	//约瑟夫问题
	//YSF();

	//按顺序合并有序双链表
	//HeBing();

	//无头非循环单链表基本操作
	//WFD();

	//有头循环双链表基本操作
	//YSF();

	//顺序表
	SXB();

	system("pause");
	return 0;
}