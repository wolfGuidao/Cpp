#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>

//µÝ¹éººÅµËþ
#include<stdio.h>
void HanNuoTa(int n,int A,int B ,int C)
{
	if (n == 1)
	{
		printf("%c->%c\n",A,C);
	}
	else
	{
		HanNuoTa(n - 1, A, C, B);
		printf("%c->%c\n", A, C);
		HanNuoTa(n - 1, B, A, C);
	}
	
}
int main()
{
	int n = 3;
	HanNuoTa(n,'A','B','C');
	system("pause");
	return 0;
}

//µÝ¹éÄæÖÃ×Ö·û´®Êý×é
#include<stdio.h>
void NiZi(char *p)
{
	char temp = 0;
	char *q;
	int len = strlen(p);
	temp = *p;
	q = p + len - 1;
	*p = *q;
	*q = '\0';
	if (strlen(p) >= 3)
	{
		NiZi(p + 1);
	}
	*q = temp;
}
int main()
{
	char a[] = "hello bit";
	NiZi(a);
	printf("%s", a);
	system("pause");
	return 0;
}