#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"SeqList.h"

int main()
{
	SeqList LA;
	SeqList LB;
	SeqList LC;
	InSeqList(&LA);
	InsList(&LA, 1, 1);
	InsList(&LA, 2, 3);
	InsList(&LA, 3, 5);
	InsList(&LA, 4, 7);
	InsList(&LA, 5, 9);

	InSeqList(&LB);
	InsList(&LB, 1, 2);
	InsList(&LB, 2, 4);
	InsList(&LB, 3, 6);
	InsList(&LB, 4, 8);
	InsList(&LB, 5, 10);

	PrintfList(&LA);
	PrintfList(&LB);

	InSeqList(&LC);
	mergeList(&LA, &LB, &LC);
	PrintfList(&LC);
	int i = 0;
	system("pause");
	return 0;
}