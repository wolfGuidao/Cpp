#include"Dlist.h"

//申请节点
DListNode* DListBuyNode(DLDataType value)
{
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//初始化
void DListInit(DList *dlist)
{
	assert(dlist != NULL);
	dlist->head = DListBuyNode(0);
	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

//头插
void DListPushFront(DList *dlist, DLDataType value)
{
	assert(dlist != NULL);
	DListNode *node = DListBuyNode(value);
	node->next = dlist->head->next;
	dlist->head->next->prev = node;
	dlist->head->next = node;
	node->prev = dlist->head;
}

//打印
void DListPrint(DList *dlist)
{
	assert(dlist != NULL);
	printf(" %d->", dlist->head->value);
	DListNode *cur;
	for (cur = dlist->head->next ;cur != dlist->head;cur = cur->next)
	{
		printf("%d->", cur->value);
	}
	printf("%d", dlist->head->value);
	printf("\n");
}

//尾插
void DListPushBack(DList *dlist, DLDataType value)
{
	assert(dlist != NULL);
	DListNode *node = DListBuyNode(value);
	node->prev = dlist->head->prev ;
	node->next = dlist->head;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
}

//查 
DListNode* DListFind(const DList* dlist, DLDataType value)
{
	assert(dlist != NULL);
	DListNode *cur = dlist->head->next;
	while (cur!=dlist->head )
	{
		if (cur->value == value)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在 pos 前面进行插入 value
void DListInsertFront(DListNode* pos, DLDataType value)
{
	assert(pos != NULL);
	DListNode *node = DListBuyNode(value);
	node->prev = pos->prev;
	node->next = pos;
	node->prev->next = node;
	pos->prev = node;
}

//头删
void DListPopFront(DList *dlist)
{
	assert(dlist != NULL);
	DListNode *node = dlist->head->next ;
	node->next->prev = dlist->head;
	dlist->head->next = node->next;
	free(node);
}

//尾删
void DListPopBack(DList *dlist)
{
	assert(dlist != NULL);
	DListNode *node = dlist->head->prev;
	node->prev->next = dlist->head;
	dlist->head->prev = node->prev;
}

//删除 pos 位置的结点
void DListErase(DListNode* pos)
{
	assert(pos != NULL);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//彻底销毁链表
void DListDestroy(DList *dlist)
{
	assert(dlist != NULL);
	DListNode *cur;
	DListNode *pre;
	cur = dlist->head->next;
	while (cur != dlist->head)
	{
		pre = cur->next;
		free(cur);
		cur = pre;
	}
	dlist->head->next = dlist->head->prev = dlist->head;
	free(dlist->head);
	dlist->head = NULL;
}