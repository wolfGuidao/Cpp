#include<iostream>
#include<Windows.h>
using namespace std;

//namespace wolf
//{
//
//}
//void Testpriority()
//{
//
//}
#if 0

void adjustDown(int* str,int len,int parent)//向下调整，保证根节点最小
{
	int child = 2 * parent + 1;
	while (child < len)//保证右孩子存在
	{
		if (child + 1 < len && str[child + 1] < str[child])//首先保证右孩子存在并且右孩子比左孩子小，才用child标记右孩子，使child始终标记较小孩子的下标
		{
			child += 1;
		}
		if (str[parent] > str[child])//如果双亲比孩子大，就进行交换
		{
			swap(str[parent], str[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else//否则就是根节点本来就比孩子节点小，说明该根节点以下都已经满足小堆情况，不用再向下调整；直接返回，调整上一个根节点
		{
			return;
		}
	}
}

void adjustUp(int* str, int child)//为了实现priority_queue中向堆尾插入一个元素且保证小堆的性质
{
	int parent = (child - 1) / 2;
	while (child)
	{
		if (str[child] < str[parent])
		{
			swap(str[child], str[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}

void Test()
{
	int arr[] = { 3,1,5,2,6,7,8,4,9,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int parent = (len - 1 - 1) / 2;//第一个减1是因为堆中是按照数组的方式计数的，从0开始，第二个减1是为了求最后一个根节点的位置
	for(;parent >= 0;parent--)//循环调整堆，使堆的结构为小堆
	{
		adjustDown(arr,len ,parent);
	}
	for (int i = 0;i < len - 1;i++)
	{
		swap(arr[0], arr[len - 1 - i]);//把对顶元素和堆中最后一个元素进行交换，这样堆中最后一个元素就是最小的
		adjustDown(arr, len - 1 - i - 1, 0);//进行调整，因为堆中最后一个元素已经是最小的，就不用惊醒调整，所以每交换一次，排序一个，所以长度len每次就减一个
	}
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}

#endif
#if 0

void adjustDown(int* str, int len, int parent)//向下调整，保证根节点最大
{
	int child = 2 * parent + 1;
	while (child < len)//保证右孩子存在
	{
		if (child + 1 < len && str[child + 1] > str[child])//首先保证右孩子存在并且右孩子比左孩子大，才用child标记右孩子，使child始终标记较大孩子的下标
		{
			child += 1;
		}
		if (str[parent] < str[child])//如果双亲比孩子小，就进行交换
		{
			swap(str[parent], str[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else//否则就是根节点本来就比孩子节点大，说明该根节点以下都已经满足大堆情况，不用再向下调整；直接返回，调整上一个根节点
		{
			return;
		}
	}
}

//void adjustUp(int* str, int child)//为了实现priority_queue中向堆尾插入一个元素且保证小堆的性质
//{
//	int parent = (child - 1) / 2;
//	while (child)
//	{
//		if (str[child] < str[parent])
//		{
//			swap(str[child], str[parent]);
//			child = parent;
//			parent = (child - 1) >> 1;
//		}
//		else
//		{
//			return;
//		}
//	}
//}

void Test()
{
	int arr[] = { 3,1,5,2,6,7,8,4,9,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int parent = (len - 1 - 1) / 2;//第一个减1是因为堆中是按照数组的方式计数的，从0开始，第二个减1是为了求最后一个根节点的位置
	for (;parent >= 0;parent--)//循环调整堆，使堆的结构为小堆
	{
		adjustDown(arr, len, parent);
	}
	for (int i = 0;i < len - 1;i++)
	{
		swap(arr[0], arr[len - 1 - i]);//因为大堆对顶元素是最大的，把对顶元素和堆中最后一个元素进行交换，这样堆中最后一个元素就是最大的
		adjustDown(arr, len - 1 - i - 1, 0);//进行调整，因为堆中最后一个元素已经是最大的，就不用进行调整，所以每交换一次，排序一个，所以长度len每次就减一个
	}
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}
#endif
#include<vector>
#include<queue>

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double>avg;
		if (!root)
		{
			return avg;
		}
		queue<TreeNode*>q;//存储节点
		q.push(root);//先把根结点入队
		double sum;//临时存储每一层的和
		while (!q.empty())
		{
			sum = 0.0;//每次都要置为0
			int count = q.size();//记录每一层元素个数
			for (int i = 0;i < count;i++)
			{
				TreeNode* cur = q.front();//cur每次都指向队头节点
				sum += cur->val;//求每一层val的和
				q.pop();//出对
				if (cur->left)//入队
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}

			}
			avg.push_back(sum / count);//求平均值并尾插到avg中
		}
		return avg;
	}
};

#endif

#if 0
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int>max;
		if (!root)
		{
			return max;
		}
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			int count = q.size();
			int max1 = q.front()->val;//存储队头节点的val
			for (int i = 0;i < count;i++)
			{
				TreeNode* cur = q.front();//始终指向队头节点
				if (cur->val > max1) //比大小，更新max1的值
				{
					max1 = cur->val;
				}
				q.pop();
				if (cur->left)
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}

			}
			max.push_back(max1);
		}
		return max;
	}
};
#endif

int main()
{
	//Test();
	//cout << max(1, 45, 99) << endl;
	system("pause");
	return 0;
}