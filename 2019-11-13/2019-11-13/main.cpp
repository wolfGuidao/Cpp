#include"Seqlist.h"
#include<Windows.h>

using namespace std;

void Test()
{
	int n;
	int i = 2;
	int sum;
	while (cin >> n)
	{
		sum = 1;
		for (i = 2;i <= n;i++)
		{
			sum *= i;
			while (sum % 10 == 0)
			{
				sum /= 10;
			}
			sum %= 10000;
		}
		cout << sum % 10 << endl;
	}
}

void Test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	
	SeqListPushFront(&s, 9);
	SeqListPushFront(&s, 8);
	SeqListPushFront(&s, 7);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//SeqListDestory(&s);
}

void Test2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	/*cout << SeqListFind(&s, 2) << endl;
	cout << SeqListFind(&s, 1) << endl;
	cout << SeqListFind(&s, 7) << endl;*/

	SeqListInsert(&s, 0, 99);
	SeqListInsert(&s, 3, 98);
	SeqListInsert(&s, 5, 97);
	//SeqListInsert(&s, 10, 97);
	SeqListPrint(&s);
	SeqListErase(&s, 0);
	SeqListErase(&s, 2);
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	
}
void Test3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPrint(&s);

	SeqListModify(&s, 0, 999);
	//SeqListRemove(&s, 2);
	SeqListPrint(&s);
	SeqListBubbleSort(&s);
	SeqListPrint(&s);

	/*cout<<SeqListBinaryFind(&s, 1)<< endl;
	cout<<SeqListBinaryFind(&s, 2) << endl;
	cout << SeqListBinaryFind(&s, 3) << endl;
	cout << SeqListBinaryFind(&s, 999) << endl;
	cout << SeqListBinaryFind(&s, 0) << endl;*/

	SeqListRemoveAll(&s, 2);
	SeqListPrint(&s);

}
#include<vector>
void Test4()
{
	/*vector<vector<int>>s;
	s.resize(20);*/

}
int main()
{
	//Test();
	//Test1();
	//Test2();
	Test3();
	//Test4();
	system("pause");
	return 0;
}