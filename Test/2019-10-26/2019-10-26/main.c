#include"List.h"


void YueSheFu(int m, int n)
{
	List* list1;
	SListInit(&list1);
	SListPushFront(&list1, m);
	Node* last = list1;
	for (int i = m-1;i >0;i--)
	{
		SListPushFront(&list1, i);
	}
	last->next  = list1;
	Node* cur = last;
	for (int j=0;j < m-1;j++)
	{
		for (int i = 1;i < n;i++)
		{
			cur = cur->next;
			printf("%dºÅ±¨£º%d\n", cur->date, i);
		}
		printf("%dºÅ³öÈ¦\n", cur->next->date );
		SListEraseAfter1(&list1, cur);
	}
	printf("%dºÅÊ¤Àû", cur->date);
	//SListPrint(&list1);
}

//void testList()
//{
//	List list;
//	SListInit(&list);
//	SListPushFront(&list, 1);
//
//	SListPushBack(&list, 2);
//
//	SListInsertBefore(&list, 2, 9);
//
//	SListInsertBack(&list, 9, 8);
//
//	SListInsertBack(&list, 8, 7);
//
//	SListInsertBack(&list, 7, 6);
//
//	SListInsertBack(&list, 6, 5);
//
//	SListInsertBack(&list, 5, 4);
//
//	SListEraseAfter(&list, 9);
//
//
//	//int ret=FindNode(&list, 22);
//	//printf("%d\n", ret);
//
//	SListPrint(&list);
//}
int main()
{
	//testList();
	YueSheFu(50,3);
	system("pause");
	return 0;
}
