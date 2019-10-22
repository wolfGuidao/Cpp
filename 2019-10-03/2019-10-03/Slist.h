#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
typedef struct SLNode
{
	SLDataType value;
	struct SLNode *next;
}SLNode;
typedef struct
{
	SLNode *first;
}SList;

//初始化
void SListInit(SList *list);

//创建节点
SLNode *SListBuyNode(SLDataType value);

//头插
void SListPushFront(SList *list, SLDataType value);

//尾插
void SListPushBack(SList *list, SLDataType value);

//打印
void SListPrint( SList *list);

//在pos后面插入value
void SListInsertAfter(SLNode *pos, SLDataType value);

//去找到链表中遇到的第一个 value，如果没找到，返回NULL
SLNode * SListFind(const SList *list, SLDataType value);

//在pos前面插入value
void SListInsertBefore(SLNode *list, SLNode *pos, SLDataType value);

//头删
void SListPopFront(SList *list);

//尾删
void SListPopBack(SList *list);

//销毁
void SlistDestory(SList *list);

//删除 pos 后面的 value
void SListEraseAfter(SLNode *pos);