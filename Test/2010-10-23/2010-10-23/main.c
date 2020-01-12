#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

#if 0

void Left(char* str, int len, int k)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0;i < k;i++)
	{
		temp = str[0];
		for (j = 0;j < len;j++)
		{
			str[j] = str[j + 1];
		}
		str[len - 1] = temp;
	}
}

int main()
{
	char str[20] = "ABCDEF";
	int len = strlen(str);
	int k = 2;
	Left(str, len, k);
	for (int i = 0;i < len;i++)
	{
		printf("%c", str[i]);
	}
	system("pause");
	return 0;
}

#endif

#if 0
//
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
int CheckLeft(char* str1, char*str2, int len)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int tag = 0;
	for (i = 0;i < len;i++)
	{
		temp = str1[0];
		for (j = 0;j < len;j++)
		{
			str1[j] = str1[j + 1];
		}
		str1[len - 1] = temp;
		
		if (!strcmp(str1, str2))
		{
			tag+=1;
		}
		
	}
	return tag;
}

int main()
{
	char str1[] = "AABCD";
	char str2[] = "AABCD";
	int len = strlen(str1);
	if (CheckLeft(str1, str2, len))
	{
		printf("%d", 1);
	}
	else
	{
		printf("%d", 0);
	}
	system("pause");
	return 0;
}

#endif
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。

//3.模拟实现strcpy
//4.模拟实现strcat

#if 0

int main()
{
	int str[]={ 1,1,2,3,3,2,4,5,5,6,6,7 };
	int len = sizeof(str) / sizeof(str[0]);
	int temp[2];
	int i = 0;
	int j = 0;
	int tag = 0;
	int k = 0;
	for (i = 0;i < len;i++)
	{
		tag = 0;
		for (j = 0;j < len;j++)
		{
			if (str[i] == str[j])
			{
				tag++;
			}
		}
		if (tag == 1)
		{
			temp[k++] = str[i];
		}
	}
	printf("%d  %d", temp[0], temp[1]);
	system("pause");
	return 0;
}
#endif

#if 0

//
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
//
int main()
{
	int money = 20;
	int woter = money;//汽水瓶数
	int pinpin = woter;//开始空瓶数
	int num = 0;//记录剩余空瓶树
	int lastpinpin = pinpin;//总空瓶数
	while (pinpin)
	{
		pinpin = lastpinpin / 2;//2个空瓶换一瓶汽水，换到多少汽水，就得到多少空瓶
		num = lastpinpin % 2;//记录上次换完汽水有没有剩余
		 lastpinpin=pinpin+ num;//总空瓶树==得到的汽水数+剩余空瓶数
		 woter += pinpin;//每次给汽水加上
	}
	printf("%d", woter);
	system("pause");
	return 0;
}
#endif
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
		dest1 += (count - 1);
		str1 += (count - 1);
		while (count--)
		{
			*dest1 = *str1;
			dest1 = dest1 - 1;
			str1 = str1 - 1;
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
