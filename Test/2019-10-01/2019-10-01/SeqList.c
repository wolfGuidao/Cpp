#include"SeqList.h"

unsigned int k = 0;

void InitSeqList(SeqList* pSeq)//初始化顺序表
{
	assert(pSeq);
	pSeq->array = (DataType *)malloc(sizeof(DataType)*DEFAULT_CAPACITY);
	pSeq->size = 0;
	pSeq->capacity = DEFAULT_CAPACITY;
}

void PrintSeqList(SeqList* pSeq)//打印顺序表
{
	assert(pSeq);
	for (k = 0;k < pSeq->size;k++)
	{
		printf("%d  ", pSeq->array[k]);
	}
	printf("\n");
}

void CheckExpandCapacity(SeqList* pSeq)//检测内存空间是否足够，若不够则自动分配二倍空间存储数据
{
	assert(pSeq);
	if (pSeq->size >= pSeq->capacity)
	{
		DataType* tmp = (DataType*)malloc(pSeq->capacity * 2 * sizeof(DataType));
		memcpy(tmp, pSeq->array, sizeof(DataType)*pSeq->size);

		free(pSeq->array);
		pSeq->array = tmp;
		pSeq->capacity = pSeq->capacity * 2;
	}
}

void DestorySeqList(SeqList* pSeq)//释放空间，销毁顺序表
{	
	if (pSeq)
	{
		free(pSeq->array);
		pSeq->capacity = 0;
		pSeq->size = 0;
	}
}

void PushBack(SeqList* pSeq, DataType x)//尾插
{
	assert(pSeq);
	CheckExpandCapacity(pSeq);
	pSeq->array[pSeq->size] = x;
	pSeq->size++;
}

void PopBack(SeqList* pSeq)//尾删
{
	assert(pSeq);
	--(pSeq->size);
}

void PushFront(SeqList* pSeq, DataType x)//头插
{
	assert(pSeq);
	for (k = pSeq->size;k >= 0;k--)
	{
		pSeq->array[k + 1] = pSeq->array[k];
	}
	pSeq->array[0] = x;
	pSeq->size++;
}

void PopFront(SeqList* pSeq)//头删
{
	assert(pSeq);
	for (k = 0;k < pSeq->size  ;k++)
	{
		pSeq->array[k] = pSeq->array[k + 1];
	}
	pSeq->size--;
}

void Insert(SeqList* pSeq, size_t index, DataType x)//在给定位置插入数据
{
	assert(pSeq);
	for (k = pSeq->size;k >= index;k--)
	{
		pSeq->array[k + 1] = pSeq->array[k];
	}
	pSeq->array[index-1] = x;
	pSeq->size++;
}

void Remove(SeqList* pSeq, size_t index)//删除给定位置数据
{
	assert(pSeq);
	for (k = index-1;k < pSeq->size;k++)
	{
		pSeq->array[k] = pSeq->array[k + 1];
	}
	pSeq->size--;
}

int Find(SeqList* pSeq, DataType index)//查找给定数据
{
	assert(pSeq);
	for (k = 0;k < pSeq->size;k++)
	{
		if (pSeq->array[k] == index)
		{
			return k + 1;
		}
	}
	return -1;
}

void Swap(DataType *left, DataType *right)//交换两数据
{
	DataType temp=0;
	temp = *right;
	*right = *left;
	*left = temp;
}

void BubbleSort(SeqList* pSeq)//冒泡排序
{
	assert(pSeq);
	unsigned int i = 0;
	for (i = 0;i < pSeq->size;i++)
	{
		for (k = 0;k < pSeq->size - 1 - i;k++)
		{
			if (pSeq->array[k] > pSeq->array[k + 1])
			{
				Swap(&(pSeq->array[k]), &(pSeq->array[k + 1]));
			}
		}
	}
}