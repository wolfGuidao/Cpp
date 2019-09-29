#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
int main()
{
	/*int a[] = { 1,2,3,4 };
	printf("%d ", sizeof(a));
	printf("%d ", sizeof(a+0));
	printf("%d ", sizeof(*a));
	printf("%d ", sizeof(a+1));
	printf("%d ", sizeof(a[1]));
	printf("%d ", sizeof(&a));
	printf("%d ", sizeof(*&a));
	printf("%d ", sizeof(&a+1));
	printf("%d ", sizeof(&a[0]));
	printf("%d ", sizeof(&a[0]+1));*/

	/*char arr[] = { 'a','b','c','d','e','f' };
	printf("%d ", sizeof(arr));
	printf("%d ", sizeof(arr + 0));
	printf("%d ", sizeof(*arr));
	printf("%d ", sizeof(arr[1]));
	printf("%d ", sizeof(&arr));
	printf("%d ", sizeof(&arr + 1));
	printf("%d ", sizeof(&arr[0] + 1));
	printf("%d ", strlen(arr));
	printf("%d ", strlen(arr+0));
	printf("%d ", strlen(*arr));
	printf("%d ", strlen(arr[1]));
	printf("%d ", strlen(&arr));
	printf("%d ", strlen(&arr+1));
	printf("%d ", strlen(&arr[0]+1));*/

	/*char arr[] = "abcdef";
	printf("%d ", sizeof(arr));
	printf("%d ", sizeof(arr + 0));
	printf("%d ", sizeof(*arr));
	printf("%d ", sizeof(arr[1]));
	printf("%d ", sizeof(&arr));
	printf("%d ", sizeof(&arr + 1));
	printf("%d ", sizeof(&arr[0] + 1));
	printf("%d ", strlen(arr));
	printf("%d ", strlen(arr + 0));
	printf("%d ", strlen(*arr));
	printf("%d ", strlen(arr[1]));
	printf("%d ", strlen(&arr));
	printf("%d ", strlen(&arr + 1));
	printf("%d ", strlen(&arr[0] + 1));*/

	/*char *p = "abcdef";
	printf("%d ", sizeof(p));
	printf("%d ", sizeof(p+1));
	printf("%d ", sizeof(*p));
	printf("%d ", sizeof(p[0]));
	printf("%d ", sizeof(&p));
	printf("%d ", sizeof(&p + 1));
	printf("%d ", sizeof(&p[0] + 1));
	printf("%d ", strlen(p));
	printf("%d ", strlen(p + 1));
	printf("%d ", strlen(*p));
	printf("%d ", strlen(p[0]));
	printf("%d ", strlen(&p));
	printf("%d ", strlen(&p + 1));
	printf("%d ", strlen(&p[0] + 1));*/

	int a[3][4] = { 0 };
	printf("%d ", sizeof(a));
	printf("%d ", sizeof(a[0][0]));
	printf("%d ", sizeof(a[0]));
	printf("%d ", sizeof(a[0]+1));
	printf("%d ", sizeof(*(a[0]+1)));
	printf("%d ", sizeof(a+1));
	printf("%d ", sizeof(*(a+1)));
	printf("%d ", sizeof(&a[0]+1));
	printf("%d ", sizeof(*(&a[0]+1)));
	printf("%d ", sizeof(*a));
	printf("%d ", sizeof(a[3]));
	system("pause");
	return 0;
}