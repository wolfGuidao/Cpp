#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DEFAULT_CAPACITY 3

 typedef int DataType;
 typedef unsigned int size_t;

typedef struct SeqList
{
	DataType* array;
	size_t size;	  // 当前的有效数据个数 
	size_t capacity;//容量
}SeqList;

void InitSeqList(SeqList* pSeq);//初始化顺序表

void PrintSeqList(SeqList* pSeq);//打印顺序表

void CheckExpandCapacity(SeqList* pSeq);//检测内存空间是否足够，若不够则自动分配二倍空间存储数据

void DestorySeqList(SeqList* pSeq);//释放空间，销毁顺序表

void PushBack(SeqList* pSeq, DataType x);//尾插

void PopBack(SeqList* pSeq);//尾删

void PushFront(SeqList* pSeq, DataType x);//头插

void PopFront(SeqList* pSeq);//头删

void Insert(SeqList* pSeq, size_t index, DataType x);//在给定位置插入数据

void Remove(SeqList* pSeq, size_t index);//删除给定位置数据

int Find(SeqList* pSeq, DataType index);//查找给定数据

void Swap(DataType *left, DataType *right);//交换两数据

void BubbleSort(SeqList* pSeq);//冒泡排序