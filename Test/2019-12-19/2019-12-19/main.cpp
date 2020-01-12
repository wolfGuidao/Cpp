/*
 *Copyright(c)2018,烟台大学计算机学院
 *All right reserved.
 *文件名称：bank.cpp
	 *作者：李小同
	 *完成日期；2018年7月6日
	 *版本号；v1.1
	 *
	 *问题描述：如下
	 *输入描述：功能需求
	 *程序输出：所需功能的实现
	*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define os 10
using namespace std;
void print();
#define M 3  //进程数量
#define N 10  //资源种类
int p[M];
using namespace std;
int Id[M];  //进程号，外部标识符
char State[M]; //状态 R就绪 W等待 E完成
int Request[M][N];  //当前请求量 
int Max[M][N] = { {7,5,3,1,0,1,0,1,0,1},{4,3,3,0,0,1,2,1,0,0},{3,0,6,1,2,0,0,1,1,1} };
// int Max[M][N]={(7,5,3),(3,2,2),(9,0,2),(2,2,2),(4,3,3)};  //需求总量
int Need[M][N];   //还需要资源数量
//int Allocation[M][N]={(0,1,0),(2,0,0),(3,0,2),(2,1,1),(0,0,2)};    //已分配量
int Allocation[M][N] = { {0,1,3},{4,1,1},{3,0,1} };
bool Finish[M];
int System[N];
int sum;
//int Available[N];
/*for(int p=0;p<M;p++)
{
	sum=Allocation[p][1]+Allocation[p][2]+Allocation[p][3];
	Available[p]=System[p]-sum;
}*/
int Available[N] = { 3,3,2,8,8,8,8,8,9,8 };
int Safe()
{
	int Work[N], temp[M];//temp[]用来记录进程安全执行的顺序
	int i, j, m, k = 0, count;
	for (i = 0; i < M; i++)
		Finish[i] = false;
	for (j = 0; j < N; j++)
		Work[j] = Available[j];//把可利用资源数赋给Work[]
	for (i = 0; i < M; i++)
	{
		count = 0; //记录符合条件的资源数量
		for (j = 0; j < N; j++)
		{
			if (Finish[i] == false && Need[i][j] <= Work[j])
				count++;
		}
		if (count == N)//当进程各类资源都满足Need<=Work时
		{
			for (m = 0; m < N; m++)
			{
				Work[m] = Work[m] + Allocation[i][m]; //将该进程的各类资源全部收回
			}
			Finish[i] = true;
			temp[k] = i;//记录下满足条件的进程
			k++;
			i = -1;  //将i置为-1 进行i++ 变为0  从头开始循环
		}
	}
	for (i = 0; i < M; i++)
		if (Finish[i] == false)
		{
			printf("系统不安全!!!本次资源申请不成功!!!\n");
			return 1;
		}
	printf("\n");
	printf("经安全性检查，系统安全\n");
	printf("\n");
	printf("本次安全序列：");
	for (i = 0; i < M; i++)//打印安全系统的进程调用顺序
	{
		printf("进程");
		printf("%d", temp[i]);
		if (i < M - 1)
			printf("->");   //当i=M时为最后一个 不需要输出->
	}
	printf("\n");
	return 0;
}
int Safe2()
{
	int Work[N], temp[M];//temp[]用来记录进程安全执行的顺序
	int i, j, m, k = 0, count;
	for (i = 0; i < M; i++)
		Finish[i] = false;
	for (j = 0; j < N; j++)
		Work[j] = Available[j];//把可利用资源数赋给Work[]
	for (i = 0; i < M; i++)
	{
		count = 0; //记录符合条件的资源数量
		for (j = 0; j < N; j++)
		{
			if (Finish[i] == false && Need[i][j] <= Work[j])
				count++;
		}
		if (count == N)//当进程各类资源都满足Need<=Work时
		{
			for (m = 0; m < N; m++)
			{
				Work[m] = Work[m] + Allocation[i][m]; //将该进程的各类资源全部收回
			}
			Finish[i] = true;
			temp[k] = i;//记录下满足条件的进程
			k++;
			i = -1;  //将i置为-1 进行i++ 变为0  从头开始循环
		}
	}
	for (i = 0; i < M; i++)
		if (Finish[i] == false)
		{
			return 1;
		}
	printf("\n");
	return 0;
}
void InitPCB()
{
	int i, j;
	for (i = 0; i < N; i++)
		System[N] = 10;
	//Max[M][N]={(7,5,3),(4,3,3),(3,0,6)};
	//Allocation[M][N]={(0,1,3),(4,1,1),(3,0,1)};
	/*for(int p=0;p<N;p++)
	{
		for(i=0;i<M;i++)
		{
		sum=Allocation[i][p]+Allocation[i][p]+Allocation[i][p];
		}
		Available[p]=System[p]-sum;
	}
	*/
	for (i = 0; i < M; i++)
	{
		Id[i] = i;
		State[i] = 'R';
		for (j = 0; j < N; j++)
			Need[i][j] = Max[i][j] - Allocation[i][j];
	}
}
int bank()
{
	int mi, i;
	Safe();
	while (1)
	{
		cout << "输入要申请的资源的进程号：（第一个进程号为0，第二个进程号为1，依此类推）\n";
		cin >> mi;
		if (mi >= M)
		{
			cout << "输入错误" << endl;
			return 0;
		}

		cout << "请输入进程请求资源的数量\n";
		for (i = 0; i < N; i++)
			cin >> Request[mi][i];
		for (i = 0; i < N; i++)
		{
			if (Request[mi][i] > Need[mi][i])
			{
				cout << "所请求资源数超过进程的需求量！\n";
				return 0;
			}
			else if (Request[mi][i] > Available[i])
			{
				cout << "所请求资源数超过系统所有的资源数！\n";
				return 0;
			}
		}
		for (i = 0; i < N; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}
		if (Safe() == 0)
			cout << "同意分配请求\n";
		else
		{
			cout << "分配失败\n";
			for (i = 0; i < N; i++)
			{
				Available[i] += Request[mi][i];
				Allocation[mi][i] -= Request[mi][i];
				Need[mi][i] += Request[mi][i];
			}
		}
		for (i = 0; i < M; i++)
			Finish[i] = 0;
		char Flag;       //标志位
		cout << "是否再次请求分配？是请按Y/y，否请按N/n";
		while (1)
		{
			cin >> Flag;
			if (Flag == 'Y' || Flag == 'y' || Flag == 'N' || Flag == 'n')
				break;
			else
			{
				cout << "请按要求重新输入:\n";
				continue;
			}
		}
		if (Flag == 'Y' || Flag == 'y')
		{
			print();
			continue;
		}
		else
			break;
	}
	return 0;
}
int random()
{
	int mi, i;
	while (1)
	{
		cout << "输入要申请的资源的进程号：（第一个进程号为0，第二个进程号为1，依此类推）\n";
		cin >> mi;
		cout << "输入进程所请求的各个资源的数量\n";
		for (i = 0; i < N; i++)
			cin >> Request[mi][i];
		for (i = 0; i < N; i++)
		{

			if (Request[mi][i] > Need[mi][i])
			{
				cout << "所请求资源数超过进程的需求量！\n";
				return 0;
			}
			if (Request[mi][i] > Available[i])
			{
				cout << "所请求资源数超过系统所有的资源数！\n";
				return 0;
			}
		}
		for (i = 0; i < N; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}
		if (Safe2() == 1)
		{
			cout << "发生死锁\n";
			return 0;
		}
		for (i = 0; i < M; i++)
			Finish[i] = 0;
		char Flag;       //标志位
		cout << "是否再次请求分配？是请按Y/y，否请按N/n";
		while (1)
		{
			cin >> Flag;
			if (Flag == 'Y' || Flag == 'y' || Flag == 'N' || Flag == 'n')
				break;
			else
			{
				cout << "请按要求重新输入:\n";
				continue;
			}
		}
		if (Flag == 'Y' || Flag == 'y')
			continue;
		else
			break;
	}
}
void print()       //输出   
{
	int i = 0, j = 0;
	printf("......................................................................\n");
	printf("\n当前状态:");
	cout << endl;
	cout << "当前可利用资源总量:" << endl;
	cout << "[";
	for (i = 0; i < N; i++)
		cout << Available[i] << " ";
	cout << "]" << endl << endl;
	cout << "进程号" << "         " << "还需资源数" << "               " << "需求总资源数" << endl;
	for (i = 0; i < M; i++)
	{
		cout << Id[i] << "        ";
		cout << "[";
		for (j = 0; j < N; j++)
			cout << Need[i][j] << " ";
		cout << "]      ";

		cout << "[";
		for (j = 0; j < N; j++)
			cout << Max[i][j] << " ";
		cout << "]";
		cout << endl;
	}
	printf("......................................................................\n");
}
int main()
{
	//  freopen("in.txt", "r", stdin);
	int n = 9999;
	printf("                         资源分配                   \n");
	while (n != 0)
	{
		printf("       --------------------------------------------------\n");
		printf("      |         &*****************************&          |\n");
		printf("      |         *      1、银行家算法          *          |\n");
		printf("      |         *      2、随机分配算法        *          |\n");
		printf("      |         *      0、退出程序            *          |\n");
		printf("      |         &*****************************&          |\n");
		printf("       --------------------------------------------------\n\n");

		printf("\n");

		InitPCB();
		print();
		printf("\n");
		printf("请选择:");

		cin>>n;
		printf("\n");


		if (n == 1)
		{
			bank();
			print();
		}
		else if (n == 2)
		{
			random();
			print();
		}
		else if (n == 0)
		{
			printf("感谢使用!\n");
			exit(0);
		}
		else printf("选择错误，请重新选择!\n");
	}
	return 0;
}