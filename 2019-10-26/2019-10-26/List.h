#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int TypeDate;

typedef struct Node
{
	TypeDate date;
	struct Node* next;
}Node;

typedef struct List
{
	Node* first;
}List;

void SListInit(List* plist);

Node *SListBuyNode(TypeDate value);

void SListPushFront(List* plist, TypeDate value);

void SListPushBack(List* plist, TypeDate value);

void SListPrint(List* plist);

int FindNode(List* plist, TypeDate value);

void SListInsertBefore(List* plist, TypeDate value1, TypeDate value);

void SListInsertBack(List* plist, TypeDate value1, TypeDate value);

void SListEraseAfter(List* plist, TypeDate value);

void SListEraseAfter1(List* plist, Node* pos);

