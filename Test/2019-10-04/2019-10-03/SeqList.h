#pragma once
#include<stdio.h>

#define ListSize 100      //线性表的最大长度
typedef int DataType;

typedef struct
{
	DataType data[ListSize];   //用数组存储线性表中的元素
	DataType length;           //顺序表的长度
}SeqList, *PSeqList;

void InitList(PSeqList L);  //顺序表的初始化操作
int LengthList(PSeqList L); //求顺序表的长度
int GetData(PSeqList L, int i); //返回数据表中第i个元素的值
int InsList(PSeqList L, int i, DataType e);   //在顺序表的第i个位置插入元素
int DelList(PSeqList L, DataType i, DataType* e); //删除顺序表L的第i个数据元素
int Locate(PSeqList L, DataType e); //查找数据元素e在表中的位置
void PushFront(PSeqList L, DataType e); //头插，在表头插入元素e
void PopFront(PSeqList L);    //头删,删除表中的第一个元素
void PushBack(PSeqList L, DataType e);  //尾插，在表尾插入元素e
void PopBack(PSeqList L); //尾删，删除表尾元素
void ClearList(PSeqList L);  //清空顺序表
int EmptyList(PSeqList L);   //判断顺序表是否为空
void PrintList(PSeqList L);  //打印表中元素

