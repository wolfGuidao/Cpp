#include"List.h"

void SListInit(List* plist)
{
	assert(plist);
	plist->first = NULL;
}

Node* SListBuyNode(TypeDate value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = value;
	node->next = NULL;
	return node;
}

void SListPushFront(List* plist, TypeDate value)
{
	assert(plist);
	Node* node = SListBuyNode(value);
	node->next = plist->first;
	plist->first = node;
}

void SListPushBack(List* plist, TypeDate value)
{
	assert(plist);
	Node* node = SListBuyNode(value);
	if (plist->first == NULL)
	{
		SListPushFront(plist, value);
		return;
	}
	else
	{
		Node* cur = plist->first;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = node;
		node->next = NULL;
	}
}

void SListPrint(List* plist)
{
	assert(plist);
	Node* cur = plist->first;
	for(;cur;cur = cur->next)
	{
		printf("%d -> ", cur->date);
	}
	printf("NULL");
}

int FindNode(List* plist, TypeDate value)
{
	assert(plist);
	Node* cur = plist->first;
	for (;cur;cur = cur->next)
	{
		if (cur->date == value)
		{
			return 1;
		}
	}
	return 0;
}

void SListInsertBefore(List* plist, TypeDate value1, TypeDate value)
{
	assert(plist);
	Node* cur = plist->first;
	while (cur->next->date != value1)
	{
		cur = cur->next;
	}
	Node* node= SListBuyNode(value);
	
	node->next = cur->next;
	cur->next = node;
}

void SListInsertBack(List* plist, TypeDate value1, TypeDate value)
{
	assert(plist);
	Node* node= SListBuyNode(value);
	Node* cur = plist->first;
	for (;cur;cur = cur->next)
	{
		if (cur->date == value1)
		{
			node->next = cur->next;
			cur->next = node;
		}
	}
}

void SListEraseAfter(List* plist, TypeDate value)
{
	assert(plist);
	Node* cur1 = plist->first;
	Node* cur2 = plist->first;
	for (;cur1;cur1 = cur1->next)
	{
		if (cur1->date == value)
		{
			cur2 = cur1->next;
			cur1->next = cur2->next;
		}
	}
}

void SListEraseAfter1(List* plist, Node* pos)
{
	assert(plist);
	Node* cur = pos->next;
	pos->next = cur->next;

}

