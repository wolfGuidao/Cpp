#include"Seqlist.h"

// 基本增删查改接口
void SeqListInit(SeqList* psl)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(0);
	psl->capicity = 0;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	free(psl->array);
	psl->array = nullptr;
	psl->capicity = 0;
	psl->size = 0;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	int newcapacity = (psl->capicity == 0) ? 4 : psl->capicity * 2;
	if (psl->size == psl->capicity)
	{
		psl->capicity = newcapacity;

		psl->array = (SLDataType*)realloc(psl->array,newcapacity*sizeof(SLDataType));
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);


	CheckCapacity(psl);

	size_t cur = psl->size;
	while (cur > 0)
	{
		psl->array[cur] = psl->array[cur - 1];
		cur--;
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	size_t cur = 0;
	while (cur < psl->size - 1)
	{
		psl->array[cur] = psl->array[cur + 1];
		cur++;
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t cur = 0;
	while (cur < psl->size)
	{
		if (psl->array[cur] == x)
		{
			return cur;
		}
		cur++;
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl&&pos<=psl->size );

	size_t cur = psl->size;
	while (cur > pos)
	{
		psl->array[cur] = psl->array[cur - 1];
		cur--;
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl&&pos<psl->size );

	size_t cur = pos;
	while (cur<psl->size -1)
	{
		psl->array[cur] = psl->array[cur + 1];
		cur++;
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t str = 0;
	size_t des = 0;
	while (str < psl->size)
	{
		if (psl->array[str] != x)
		{
			psl->array[des] = psl->array[str];
			str++;
			des++;
		}
		else
		{
			str++;
		}
	}
	psl->size = des;
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl&&pos<psl->size );

	psl->array[pos] = x;
	
}
void SeqListPrint(SeqList* psl)
{
	assert(psl);

	size_t cur = 0;
	while (cur<psl->size )
	{
		cout << psl->array[cur]<<"->";
		cur++;
	}
	cout << "nullptr\n";
}

// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);

	size_t end = psl->size -1;
	for (;end>0;end--)
	{
		for (int start = 0;start < end;start++)
		{
			if (psl->array[start] > psl->array[start + 1])
			{
				swap(psl->array[start +1], psl->array[start]);
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int start = 0;
	int end = psl->size - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (psl->array[mid] == x)
		{
			return mid;
		}
		if (psl->array[mid] < x)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t str = 0;
	size_t des = 0;
	while (str < psl->size)
	{
		if (psl->array[str] != x)
		{
			psl->array[des] = psl->array[str];
			str++;
			des++;
		}
		else
		{
			str++;
		}
	}
	psl->size = des;
}