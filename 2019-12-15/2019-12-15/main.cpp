//
//#if 0
//class Solution {
//public:
//	int QuickShortchild(vector<int>&str, int left, int right)
//	{
//		int temp = str[left];//默认选数组第一个元素作为基准，即temp = str[left]
//		while (left < right)//选好基准，传参时right存储数组最后一个元素下标，left存储数组首元素下标
//		{
//			while (left < right&&str[right] >= temp)//每次循环都是从后往前进行，即如果right代表元素小于基准，就把该值赋给left代表元素
//			{
//				right--;//否者right位置前移
//			}
//			str[left] = str[right];
//			while (left < right&&str[left] <= temp)//然后从前往后进行，如果left代表元素大于基准，这把该值赋给right代表元素
//			{
//				left++;//否者left后移
//			}
//			str[right] = str[left];
//		}
//		str[left] = temp;
//		return left;//此为一趟快速排序，返回基准位置，方便递归时把数组分割开
//	}
//	void QuickSort(vector<int>&str, int left, int right)
//	{
//		if (left < right)
//		{
//			int mid = QuickShortchild(str, left, right);//得到基准位置，即数组中该位置前的元素都比它小，后面的元素都比他大
//			QuickSort(str, left, mid - 1);//对基准左部进行递归排序
//			QuickSort(str, mid + 1, right);	//对基准右部进行递归排序
//		}
//	}
//	vector<int> sortArray(vector<int>& nums) {
//		/*
//		sort(nums.begin(),nums.end());
//		return nums;
//		*/
//		QuickSort(nums, 0, nums.size() - 1);
//		return nums;
//	}
//};
//
//#endif
#include<iostream>
using namespace std;
///*
//int main()
//{
//	int arr[10];
//	int m = 5;
//	int i = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		arr[i] = 1;
//
//	}
//	arr[9] = 999;
//	for (i = 0; i < m; i++)
//	{
//		if (arr[i] == 1)
//		{
//			m++;
//		}
//	}
//	cout << i << endl;
//	system("pause");
//	return 0;
//}
//*/
//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		/*
//		//注意这道题坑的地方是编号是从0开始编的，和报数是从0开始报的，注意
//		if(n<1||m<0)
//		{
//			return -1;
//		}
//		list<int>l;
//		//循环往list中放编号
//		for(int i=0;i<n;i++)
//		{
//			l.push_back(i);
//		}
//		//cur每次用来遍历和用来记录要删除的节点
//		auto cur=l.begin();
//		//如果list中元素的个数大于1就继续循环，直到只剩下一个
//		while(l.size()>1)
//		{
//			//循环报数
//			for(int i=1;i<m;i++)
//			{
//				cur++;
//				//注意++后可能会越界，所以必须让list循环起来
//				if(cur==l.end())
//				{
//					cur=l.begin();
//				}
//			}
//			//记录带待删除的下一个节点
//			auto next=++cur;
//			//同理要让list循环起来
//			if(next==l.end())
//			{
//				next=l.begin();
//			}
//			//之前为了记录next执行了++，就得--回来
//			cur--;
//			//删除cur的节点
//			l.erase(cur);
//			//后移
//			cur=next;
//		}
//		return *cur;
//		*/
//		if (n < 0 || m < 0)
//		{
//			return -1;
//		}
//		int* arr = new int[n];
//		int index = -1;
//		int length = n;
//		//int sss = m;
//		for (int i = 0; i < n; i++)
//		{
//			arr[i] = i;
//		}
//		while (n > 0)
//		{
//			while (m)
//			{
//				index = (index + 1) % length;
//				if (arr[index] == -1)
//				{
//					m++;
//				}
//				m--;
//			}
//			
//
//			//int index1 = (index + 1) % length;
//			/*
//			while (arr[index1] == -1)
//			{
//				index1 = (index1 + 1) % length;
//
//			}
//			*/
//			//index = (index + 1)%length;
//			//m = arr[index];
//			arr[index] = -1;
//
//			//m = sss;
//			n--;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (arr[i] != -1)
//			{
//				return i;
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout<<s.LastRemaining_Solution(5, 3);
//	system("pause");
//	return 0;
//}

//#include<stdio.h> 
int main()
{
	int n, m, i, k;
	int a[99] = { 0 };
	cin >> n >> m;
	for (i = 0; i < n; i++)
		//scanf("%d", &a[i]);
		a[i] = i;
	i = -1; k = n;
	while (n>1)
	{
		while (m)
		{
			i = (i + 1) % k;
			if (a[i] == -1)
				m++;
			m--;
		}
		printf("%d", i + 1);
		m = a[i];
		a[i] = -1;
		n--;
	}
	return 0;
}
