#pragma once
#include<stdio.h>

#define MaxSize 100
#define ElemType int

typedef struct
{
	ElemType elem[MaxSize];
	int last;//记录线性表最后一个元素在数组中的下标值，注意是从零开始
}SeqList;

void InsList(SeqList * L, int i, ElemType e);//在顺序表i的前面插入一个元素

void PrintfList(SeqList *L);//打印

void InSeqList(SeqList *L);//初始化

void mergeList(SeqList* LA, SeqList* LB, SeqList* LC);