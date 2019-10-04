#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DLDataType;
typedef struct DListNode
{
	DLDataType value;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;
typedef struct DList
{
	DListNode *head;
}DList;

//初始化
void DListInit(DList *dlist);

//申请节点
static DListNode* DListBuyNode(DLDataType value);

//头插
void DListPushFront(DList *dlist, DLDataType value);

//打印
void DListPrint(DList *dlist);

//尾插
void DListPushBack(DList *dlist, DLDataType value);

//查 
DListNode* DListFind(const DList* dlist, DLDataType value);

//在 pos 前面进行插入 value
void DListInsertFront(DListNode* pos, DLDataType value);

//头删
void DListPopFront(DList *dlist);

//尾删
void DListPopBack(DList *dlist);

//删除 pos 位置的结点
void DListErase(DListNode* pos);

//彻底销毁链表
void DListDestroy(DList *dlist);

//按顺序合并有序双链表
void DListMerge(DList *list1, DList *list2);