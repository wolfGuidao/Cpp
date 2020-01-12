#include<iostream>
#include<CoreWindow.h>
using namespace std;

#if 0

class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<string> ret;//存储结果
		int B_info[26] = { 0 };//用来记录B中最终每个字母出现的最大次数
		for (int i = 0; i < B.size(); i++)//遍历B
		{
			int temp_info[26] = { 0 };//临时存储
			for (auto j : B[i])//遍历B中每个具体的string
			{
				temp_info[j - 'a']++;//临时记录B中每个string中每个字母出现的次数
				B_info[j - 'a'] = max(B_info[j - 'a'], temp_info[j - 'a']);//因为可能有同一个字母出现多次，这种情况下不能只记录一次，B_info中应存放每个字母出现的最大次数
			}
		}
		for (auto i : A)//遍历A
		{
			int temp1_info[26] = { 0 };//临时存储A中每个字母出现的次数
			for (auto j : i)//遍历A中每个string
			{
				temp1_info[j - 'a']++;//存储A中每个字母出现的次数
			}
			int k = 0;//临时变量，用来循环
			while (k < 26)
			{
				if (temp1_info[k] >= B_info[k])//如果满足A中每个字母的出现的次数大于等于B_info中记录的结果，就继续循环
				{
					k++;
				}
				else//一旦出现小于的情况，直接break，就不用在进行判断
				{
					break;
				}
			}
			if (k == 26)//如果走到这里，说明A中每个字母都满足条件，直接把这个字符串尾插到ret中
			{
				ret.push_back(i);
			}
		}
		return ret;
	}
};
#endif


#if 0

#include<string>
class Solution {
public:
	void replaceSpace(char *str, int length) {
		/*
		string ret=str;
		auto it=ret.begin();
		int i= 0;
		while(it!=ret.end())
		{
			i = ret.find(" ");
			if(i<0)
			{
				break;
			}
			else
			{

				if(it!=ret.end())
				it=it+1;
			}

		}
		char* newstr=ret.c_str();
		str=(char*)newstr;
		*/
		char* newstr = new char[length * 2];
		int k = 0;
		if (str == nullptr || length < 0)
		{
			str = nullptr;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (str[i] == ' ')
				{
					newstr[k++] = '%';
					newstr[k++] = '2';
					newstr[k++] = '0';
				}
				else
				{
					newstr[k++] = str[i];
				}
			}
			newstr[k] = '\0';
			str = newstr;
			cout << str;
		}
	}
};

class Solution
{
	//注意，一旦要把stack1中的元素往stack2中放，一定要放全部
	//只有stack2为空时，才能往stack2中放元素
public:
	void push(int node) {
		stack1.push(node);

	}

	int pop() {
		if (stack2.empty())//如果发现stack2为空，就把stack1中的所有元素都插到stack1中，
			//记住是所有，不是一部分
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			int ret = stack2.top();
			stack2.pop();
			return ret;
		}
		else//如果发现stack2中还有元素，此时万万不能把stack1中的元素往stack2中插入，
			//因为队是先进先出的，stack2中的元素是先进来的，就因该先出去，
			//等stack2中的元素完全出栈才能进行入栈操作，
		{
			int ret = stack2.top();
			stack2.pop();
			return ret;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

class Solution {
public:
	int rectCover(int number) {
		//变种斐波那契
		if (number == 0 || number == 1 || number == 2)
		{
			return number;
		}
		return rectCover(number - 1) + rectCover(number - 2);

		/*
		if(number==0||number==1||number==2)
		{
			return number;
		}
		int n1=1;
		int n2=2;
		int n3=0;
		while(number>=3)
		{
			n3=n1+n2;
			n1=n2;
			n2=n3;
			number--;
		}
		return n3;
		*/
	}
};

void test()
{
	Solution s;
	char str[] = "hello world";
	int len = strlen(str);
	s.replaceSpace(str,len);
}

#endif

#if 0
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr&&pHead2 == nullptr)
		{
			return nullptr;
		}
		if (pHead1 == nullptr&&pHead2 != nullptr)
		{
			return pHead2;
		}
		if (pHead1 != nullptr&&pHead2 == nullptr)
		{
			return pHead1;
		}
		ListNode* head = new ListNode(0);
		ListNode* cur = head;
		while (pHead1&&pHead2)
		{
			if (pHead1->val <= pHead2->val)
			{
				if (cur == nullptr)
				{
					head = pHead1;
					pHead1 = pHead1->next;
				}
				else
				{
					cur->next = pHead1;
					cur = pHead1;
					pHead1 = pHead1->next;
				}
			}
			else
			{
				if (cur == nullptr)
				{
					head = pHead2;
					pHead2 = pHead2->next;
				}
				else
				{
					cur->next = pHead2;
					cur = pHead2;
					pHead2 = pHead2->next;
				}
			}
		}
		if (pHead1 == nullptr)
		{
			cur->next = pHead2;
		}
		if (pHead2 == nullptr)
		{
			cur->next = pHead1;
		}
		return head->next;

	}
};

#include<vector>
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int start = 0;
		int end = array.size() - 1;
		int temp = array[0];
		while (start < end)
		{
			while (array[end] % 2 == 0 && start < end)
			{
				end--;
			}
			array[start] = array[end];
			while (array[start] % 2 != 0 && start < end)
			{
				start++;
			}
			array[end] = array[start];
		}
		array[start] = temp;


	}
};
void test()
{
	Solution s;
	vector<int>l = { 1,2,3,4,5,6,7 };
	s.reOrderArray(l);
	for (auto e : l)
	{
		cout << e << ' ' << endl;
	}
}

#endif

#include<vector>

int main()
{
	vector<vector<int>>arr;
	int m;
	int n;
	cin >> m >> n;
	arr.resize(m);
	for (int i = 0; i < m; i++)
	{
		arr[i].resize(n, 0);
	}
	//int arr[4][4] = { 0 };
	arr[0][0] = 1;
	int num = n * m;
	int x = 0;//记住x和y都是从0开始的，记住记住
	int y = 0;
	int k = 1;//注意边界问题
	while (num-1)//因为k从1开始，就少循环一次
	{
		//注意前置++和后置++在此处的区别
		while (y + 1 < n && arr[x][y+1] == 0  )//向右，不能取到n是因为下标都是从0开始的，+1是因为y是从0开使的，
			//arr[x][y+1] == 0是为了判断哪些位置可以放，哪些位置不能放
		{
			arr[x][++y] = ++k;
			num--;
		}
		//y--;
		while (x+1 < m && arr[x+1][y] == 0  )//向下
		{
			arr[++x][y] = ++k;
			num--;
		}
		//x--;
		while (y-1 >= 0 && arr[x][y-1] == 0  )//向左
		{
			arr[x][--y] = ++k;
			num--;
		}
		//y++;
		while (x-1 >=0  && arr[x-1][y] == 0  )//向上
		{
			arr[--x][y] = ++k;
			num--;
		}
		//x++;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//cout << arr[i][j] << "  ";
			printf("%3d", arr[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}