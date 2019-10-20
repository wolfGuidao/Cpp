#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<string.h>
#include<assert.h>
using namespace std;

//int check()
//{
//	int i = 1;
//	char *p = (char*)&i;
//	return *p;
//}
//
//int main()
//{
//	int ret = check();
//	if (ret == 1)
//	{
//		cout << "小端" << endl;
//	}
//	else
//	{
//		cout << "大端" << endl;
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 14;
//	char *p = (char *)&i;
//	if (*p == 14)
//	{
//		cout << "小端" << endl;
//	}
//	else
//	{
//		cout << "大端" << endl;
//	}
//	cout << &i << endl;
//	system("pause");
//	return 0;
//}

int my_strlen1(const char*str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(const char*str)
{
	assert(str);
	if (*str=='\0')
	{
		return 0;
	}
	return 1 + my_strlen2(str+1);
}

int my_strlen3(char*str)
{
	assert(str);
	char *a = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - a;
}

char* my_strcpy(char*des ,const char* str)
{
	assert(des);
	assert(str);
	 char *a= des;
	do
	{
		*des = *str;
		str++;
		des++;
	} while (*str != '\0');
	return a;
}

char* my_strcat(char* des ,char* str)
{
	assert(des);
	assert(str);
	char *a = des;
	while (*des != '\0')
	{
		des++;
	}
	do
	{
		*des = *str;
		str++;
		des++;
	} while (*str != '\0');
	return a;
}

int my_strcmp(const char * des, const char *str)
{
	assert(des);
	assert(str);
	while (des&&str)
	{
		if (*des > *str)
		{
			return 1;
		}
		else if (*des < *str)
		{
			return -1;
		}
		else
		{
			str++;
			des++;
		}
	}
	if (*str == *des == '\0')
	{
		return 0;
	}
	else if (*des>*str)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char* my_strstr(const char* dest, const char* str)
{
	assert(dest);
	assert(str);
	while (dest)
	{
	    char* start =(char*) dest;
		char* str = (char*)str;
		while (*dest == *str&&*str != '\0')
		{
			dest++;
			str++;
		}
		if (*str == '\0')
		{
			return start;
		}
		else
		{
			dest = start + 1;
			str = str;
		}
	}
	return NULL;
}

void* my_memmove(void* dest,const void* str,size_t count)
{
	assert(dest);
	assert(str);
	void* ret = dest;
	if (str < dest || (char*)dest < ((char*)str + count))
	{
		
		dest = (char*)dest + count - 1;
		str = (char*)str + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)str;
			dest = (char*)dest - 1;
			str = (char*)str - 1;
		}
	}
	else
	{
		while (count--)
		{
			*(char*)dest = *(char*)str;
			dest = (char*)dest + 1;
			str = (char*)str + 1;
		}
		
	}
	return ret;
}
//void* my_memmove( void* dest,const void* str, size_t count)
//{
//	assert(dest);
//	assert(str);
//	void* ret = dest;
//	if (str < dest || (char*)dest < (char*)str + count)
//	{
//		str = (char*)str + count - 1;
//		dest = (char*)dest + count - 1;
//		while (count--)
//		{
//			*(char*)dest = *(char*)str;
//			dest = (char*)dest - 1;
//			str = (char*)str - 1;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)str;
//			dest = (char*)dest + 1;
//			str = (char*)str + 1;
//		}
//		
//	}
//	return ret;
//}

int main()
{
	char a[20] = "wolf guidao";
	//char b[20];
	//memmove(a + 10, a, 12);
	my_memmove(a + 10, a, 12);

	cout << a << endl;

	//char c[20];
	//memmove(b, a, 12);
	//my_memmove(c, a, 12);
	//cout << b << endl;
	//cout << c << endl;
	system("pause");
	return 0;
}