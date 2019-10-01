#include"Slist.h"

//初始化
void SListInit(SList *list)
{
	assert(list!=NULL);
	list->first = NULL;
}

//创建节点
SLNode *SListBuyNode(SLDataType value)
{
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node!=NULL);
	node->value = value;
	node->next = NULL;
	return node;
}

//头插
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SLNode *node = SListBuyNode(value);
	assert(node != NULL);
	node->next = list->first;
	list->first = node;
}

//尾插
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	
	if (list->first == NULL)
	{
		SListPushFront(list, value);
		return;
	}
	SLNode *cur = list->first;
	while (cur->next)
	{
		cur = cur->next;
	}
	SLNode *node = SListBuyNode(value);
	cur->next = node;
	node->next = NULL;
}

//打印
void SListPrint(const SList *list)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	for (cur = list->first ;cur;cur = cur->next)
	{
		printf("%d->", cur->value);
	}
	printf("NULL\n");
}

//在pos后面插入value
void SListInsertAfter(SLNode *pos, SLDataType value)
{
	assert(pos != NULL);
	SLNode *node = SListBuyNode(value);
	node->next = pos->next;
	pos->next = node;
}

//去找到链表中遇到的第一个 value，如果没找到，返回NULL
SLNode * SListFind(const SList *list, SLDataType value)
{
	assert(list != NULL);
	SLNode *cur;
	for (cur = list->first;cur;cur = cur->next)
	{
		if (cur->value == value)
		{
			return cur;
		}
	}
	return NULL;
}

//在pos前面插入value
void SListInsertBefore(SList *list, SLNode *pos, SLDataType value)
{
	assert(pos != NULL);
	assert(list != NULL);
	SLNode *node = SListBuyNode(value);
	SLNode *cur = list->first;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	
	cur->next = node;
    node->next = pos;
}

//头删
void SListPopFront(SList *list)
{
	assert(list!=NULL);
	assert(list->first != NULL);
	SLNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//尾删
void SListPopBack(SList *list)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	while (cur->next->next  != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//销毁
void SlistDestory(SList *list)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	SLNode *right;
	while (cur != NULL) 
	{
		right = cur->next;
		free(cur);
		cur = right;
	}
	list->first = NULL;
}

//删除 pos 后面的 value
void SListEraseAfter(SLNode *pos)
{
	SLNode *next = pos->next;
	pos->next = next->next;
	free(next);
}