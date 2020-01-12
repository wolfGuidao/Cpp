#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

int my_strlen1(const char* str)//模拟实现strken():计数
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(const char*str)//递归
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	return 1 + my_strlen2(str + 1);
}

int my_strlen3(const char* str)//连续的内存上两指针相减，返回之间元素个数
{
	assert(str);
	const char*str1 = str;
	while (*str)
	{
		str++;
	}
	return str - str1;
}

char* my_strcpy(char* dest, const char* str)//模拟strcpy（）
{
	assert(dest&&str);
	char* dest1 = dest;
	while (*str)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';//注意结尾；'\0'
	return dest1;
}

char* my_strcat(char* dest, const char* str)//模拟strcat()
{
	assert(dest&&str);
	char* dest1 = dest;
	while (*dest)
	{
		dest++;
	}
	do
	{
		*dest = *str;
		dest++;
		str++;
	} while (*str);
	*dest = '\0';
	return dest1;
}

int my_strcmp(const char* dest, const char* str)//模拟strcmp()
{
	assert(dest&&str);
	while (*dest != '\0'&&*str != '\0')
	{
		if (*dest == *str)
		{
			str++;
			dest++;
		}
	}
	if (*str == *dest&&*str == '\0')
	{
		return 0;
	}
	else if (*dest > *str)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char* my_strstr(const char*dest, const char* str)//
{
	assert(dest&&str);
	char* start;
	const char* str1 = str;//保存待匹配串首地址
	while (*dest)
	{
	    start = (char*)dest;//记录每次匹配位置
		while (*dest == *str&&*str != '\0')
		{
			dest++;
			str++;
		}
		if (*str == '\0')//如果str=='\0'说明已完成匹配
		{
			return start;
		}//这里不能直接break；因为后面可能会出现
		else//如果完成匹配，记录并返回第一个字符的位置；该次没有完成匹配，记录该位置，下一次重该位置后一个进行比较
		{
			dest = start + 1;
			str = str1;
		}
	}
	return NULL;
}

void* my_memmove(void* dest, const void* str, size_t count)//注意参数和返回值的类型
{
	assert(dest&&str);
	char* dest1 = (char*)dest;
	char* str1 = (char*)str;
	if (str1 < dest1 || dest1 < str1 + count)//内存覆盖在后面；从后往前赋值
	{
		dest1 += (count-1);
		str1 += (count - 1);
		while (count--)
		{
			*dest1 = *str1;
			dest1=dest1-1;
			str1=str1-1;
		}
	}
	else//没有内存或内存覆盖在前面；从前往后赋值
	{
		while (count--)
		{
			*dest1 = *str1;
			dest1 = dest1 - 1;
			str1 = str1 - 1;
		}
	}
	return dest1;
}

int main()
{
	//测试用例中不要全部放开，可能会发生冲突
	char str[] = "wolf guidao";
	/*cout << strlen(str) << endl;
	cout << my_strlen1(str) << endl;
	cout << my_strlen2(str) << endl;
	cout << my_strlen3(str) << endl;*/

	char str1[40];
	//cout << strcpy(str1, str) << endl;
	//cout << my_strcpy(str1, str) << endl;

	//cout << my_strcat(my_strcpy(str1, str), str) << endl;

	//cout << strcmp(str, my_strcpy(str1, str)) << endl;
	//cout << my_strcmp(str, my_strcpy(str1, str)) << endl;
	//cout << my_strcmp(str, strcpy(str1, "wolf guidaoo")) << endl;
	//cout << my_strcmp(str, my_strcpy(str1, "wolf guidaoo")) << endl;

	//cout << my_strstr(str, my_strcpy(str1, str)) << endl;
	//cout << strstr(str, my_strcpy(str1, str)) << endl;
	//cout << my_strstr(str, my_strcpy(str1, "guidao")) << endl;
	//cout << strstr(str, my_strcpy(str1, "guidao")) << endl;

	//my_memmove(str1, str, 12);
	//memmove(str1, str, 12);
	//cout << str1 << endl;
	//my_memmove(str+11, " aini", 6);
	//memmove(str + 11, " aini", 6);
	//cout << str << endl;
	//memmove(str + 10, str, 12);
	my_memmove(str + 10, str, 12);
	cout << str << endl;

	system("pause");
	return 0;
}