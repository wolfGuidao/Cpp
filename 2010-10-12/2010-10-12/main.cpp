#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cmath"
using namespace std;
#define Max 20      //�������̵����ֵ
int a[Max];
int show(int S)    //�����������
{
	int i, p, q;
	int b[Max][Max] = { 0 };     //���岢��ʼ��b[][]�������
	for (i = 1;i <= S;i++)    //������i˳�����a[i]��������
	{
		b[i][a[i]] = 1;
		printf("(%d,%d)\t", i, a[i]);
	}
	printf("\n");
	for (p = 1;p <= S;p++)     //�����̵ĺ���p˳������ʺ��λ��
	{
		for (q = 1;q <= S;q++)
		{
			if (b[p][q] == 1)     //�ڵ�p�е�q�з���һ���ʺ�����
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}
	return 0;
}

int check(int k)    //����check����
{
	int i;
	for (i = 1;i < k;i++)    //����k����ǰ��ĵ�1~~k-1�н����ж�
	{
		if ((a[i] == a[k]) || (a[i] - a[k] == k - i) || (a[i] - a[k] == i - k)) //����Ƿ��ж���ʺ���ͬһ��ֱ����
		{
			return 0;
		}
	}
	return 1;
}

void check_m(int num)   //���庯��
{
	int k = 1, count = 0;
	printf("�ʺ��λ������:\n");
	a[k] = 1;
	while (k > 0)
	{
		if (k <= num && a[k] <= num)//�ӵ�k�е�һ�е�λ�ÿ�ʼ��Ϊ��������ѡ�����λ��
		{
			if (check(k) == 0)    //��k�е�a[k]�в��ܷ��ûʺ�
			{
				a[k]++;        //����̽�⵱ǰ�е���һ�У�a[k]+1
			}
			else
			{
				k++;        //��K�е�λ���Ѿ�ȷ���ˣ�����Ѱ�ҵ�k+1�лʺ��λ��
				a[k] = 1;      //�ӵ�һ�п�ʼ����
			}
		}
		else
		{
			if (k > num)     //��������������Ҫ�������������
			{
				count++;
				printf("[%d]:  ", count);
				show(num);    //�����������show()
			}
			//���k>num��ִ���������д��룬��Ϊ��Ȼ�ҵ���N�ʺ������һ���⣬����Ҫ�ҵ������н⣬��Ҫ���ݣ��ӵ�ǰ���ûʺ����һ�м���̽��
			//���a[k]>numҲ��ִ���������д��룬����˵�ڵ�ǰ��û���ҵ����Է��ûʺ��λ�ã����ǻ��ݣ�����һ�лʺ�λ�õ���һ�м���̽��
			k--;      //����λ�ò�����Ҫ�����˻�ǰһ��
			a[k]++;   //������̽��һ��λ��
		}
	}
	printf("�������������»ʺ��λ�ù���: %d�� \n", count);
}

int main(void)
{
	int n;
	printf("������ʺ������");
	scanf("%d", &n);
	printf("\nʹ�÷ǵݹ���ݷ���� %d �ʺ�����ʱ���������\n", n);
	check_m(n);
	system("pause");
	return 0;
}
#if 0

#include<Windows.h>
#include<stdio.h>
#define MaxSize 10
//2n�ʺ�����
//��������
//����һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ�������з���n���ڻʺ��n���׻ʺ�ʹ����������ڻʺ�
//������ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ����ܹ��ж����ַŷ���
//nС�ڵ���8��
//�����ʽ
//����ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��
//������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�
//�����ʽ
//���һ����������ʾ�ܹ��ж����ַŷ���
//��������
//4
//1 1 1 1
//1 1 1 1
//1 1 1 1
//1 1 1 1
//�������
//2

int hei[MaxSize];//�ڻʺ�
int bai[MaxSize];//�׻ʺ�
int chessboard[MaxSize][MaxSize];//1:�ܷ�  0:���ܷ�
int count = 0;
int check(int queen[], int line)//�жϺ���
{
	for (int i = 1; i < line; i++)
	{
		int judge = queen[i] - queen[line];
		if (judge == 0 || judge == i - line || judge == line - i)
			//judge == 0 ��ʾ��ͬһ�У�judge == i - line || judge == line - i��ʾ��ͬһ�Խ���
		{
			return 0;
		}
	}
	return 1;
}

void White(int line, int n)//�ںڻʺ�ǰ���µݹ���ð׻ʺ�
{
	if (line == n + 1)//�ڷ���ڻʺ�ǰ���£����ð׻ʺ�ÿ�������лʺ�һ�Σ�count++;
	{
		count++;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (chessboard[line][i] == 1 && i != hei[line])
			{
				bai[line] = i;
				if (check(bai, line))
				{
					White(line + 1, n);//�ݹ���һ��
				}
			}
		}
	}
}

void Black(int line, int n)//�ݹ���úڻʺ�
{
	if (line == n + 1)//��ʾ�ڻʺ��ѷ������
	{
		White(1, n);
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			if (chessboard[line][i] == 1)
			{
				hei[line] = i;//��ʾ�ڻʺ�ÿһ�з��õ�λ��
				if (check(hei, line))//�жϷ��ûʺ�λ���Ƿ���������������͵ݹ飬������ͻ�һ��λ�÷��ûʺ󣬽���ѭ��
				{
					Black(line + 1, n);//�ݹ���һ��				
				}
			}
		}
	}
}

int main()
{
	int n;
	printf("���������̴�С��\n");
	scanf("%d", &n);
	printf("������%d�У�ÿ��%d��0��1��������\n",n,n);
	printf("���һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf(" %d ", chessboard[i][j]);
		}
		printf("\n");
	}
	Black(1, n);
	printf("�ܹ���%d�ַ��ûʺ�ķ���", count);
	system("pause");
	return 0;
}

#endif