#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#if 0
//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include<stdio.h>
int main()
{
	int a, b, c, d, e;
	for (a = 1;a <= 5;a++)
	{
		for (b= 1;b<= 5;b++)
		{
			for (c = 1;c <= 5;c++)
			{
				for (d = 1;d <= 5;d++)
				{
					for (e = 1;e <= 5;e++)
					{
						if (((b == 2 && a != 3) || (b != 2 && a == 3)) == 1)
						{
							if (((b == 2 && e != 4) || (b != 2 && e == 4))==1)
							{
								if (((c == 1 && d != 2) || (c != 1 && d == 2))==1)
								{
									if (((c == 5 && d != 3) || (c != 5 && d == 3)) == 1)
									{
										if (((e == 4 && a != 1) || (e != 4 && a == 1)) == 1)
										{
											if ((a*b*c*d*e == 120)&&((a+b+c+d+e)==15))
											{
												printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

//2.
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个。
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

#include<stdio.h>
int main()
{
	int xongshou = 0;
	for (xongshou = 'A';xongshou <= 'D';xongshou++)
	{
		if (((xongshou != 'A') + (xongshou == 'C') + (xongshou == 'D') + (xongshou != 'D')) == 3)
		{
			printf("凶手是%c", xongshou);
		}
	}
	system("pause");
	return 0;
}


//3.在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1

#include<stdio.h>
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;//第一列的1
			}
			if (i == j)
			{
				arr[i][j] = 1;//对角线的1
			}
			if (i > 1)
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (i = 0; i < 10; i++)//打印空格
	{
		for (j = 0; j < 10 - i; j++)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)//打印数
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}



//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
    int sum = 0;
	for (i = 0;i < 32;i++)
	{
		if ((value >> i) & 1)
		{
			sum += (1<<(31-i));
		}
	}
	return sum;
}
int main()
{
	int n = 25;
	int a = 0;
	a = reverse_bit(n);
	printf("%u", a);
	system("pause");
	return 0;
}




//2.不使用（a + b） / 2这种方式，求两个数的平均值。
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	printf("%d", (a + b) >> 1);
	system("pause");
	return 0;
}


//3.编程实现：
//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）


#include<stdio.h>
int main()
{
	int a[9] ={ 1, 5, 5, 1, 7, 6, 7, 8, 8};
	int i = 0;
	int j = a[0];
	for (i = 1;i < 9;i++)
	{
		j ^= a[i];
	}
	printf("%d", j);
	system("pause");
	return 0;
}
#endif

//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
#include<stdio.h>
void JiaoHuan(char a[], int len)
{
	int left = 0;
	int right = len - 1;
	char b;
	while (left <= right)
	{
		b = a[left];
		a[left] = a[right];
		a[right] = b;
		left++;
		right--;
	}
}

int main()
{
	int temp=0;
	int i = 0;
	int left = 0;
	int right = 0;
	char a[] = "student a am i";
	int len = strlen(a);
	JiaoHuan(a, len);
	while(a[i]!='\0')
	{
		left = i;
		while (a[i] != ' '&&a[i]!='\0')
		{
			i++;
		}
		
		right = i-1;
		while (left < right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
		if (a[i] != '\0')
		{
			i++;
		}
		
	}

		printf("%s", a);
	system("pause");
	return 0;
}