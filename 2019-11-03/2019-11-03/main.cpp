#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>

using namespace std;



 
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> ret;//记录结果返回最后结果
//		if (!root)
//		{
//			return ret;
//		}
//
//		queue<TreeNode*>s;//创建一个存储节点的队列
//		s.push(root);
//		while (!s.empty())//如果队列为空就退出循环
//		{
//			vector<int> ret1;//存储每一层
//			int levsize = s.size();//记录每层节点个数
//			for (int i = 0;i < levsize;i++)//循环
//			{
//				TreeNode* cur = s.front();//保存队头元素
//				ret1.push_back(cur->val);//把队头节点尾插到ret1中
//				s.pop();//出队
//
//				if (cur->left)//如果左右孩子不为空，就入队
//				{
//					s.push(cur->left);
//				}
//				if (cur->right)
//				{
//					s.push(cur->right);
//				}
//			}
//			ret.push_back(ret1);//每次把每层结果尾插到ret中
//		}
//		return ret;
//	}
//};

//int main()
//{
//	//list<int>L{ 1,2,3,4,5 };
//	//auto it = L.begin();
//	//while (it != L.end())//迭代器失效
//	//{
//	//	it= L.erase(it);
//	//	//++it;
//	//}
//	//for (auto e : L)
//	//{
//	//	cout << e << " ";
//	//}
//	/*stack<int> s;
//	s.push(2);
//	s.push(5);
//	s.push(7);
//	cout << s.top() << endl;
//	s.pop();
//	s.pop();
//	cout << s.top() << endl;*/
//	/*string s("a");
//	cout << s << endl;
//	cout << s.c_str() << endl;
//	cout<<atoi(s.c_str())<<endl;
//	printf("%c", s);*/
//	//printf("%d\n", atoi(s.c_str()));
//	//printf("%c\n", s.c_str());
//	cout << atoi("123") << endl;
//	cout << "123";
//	system("pause");
//	return 0;
//}
//#include<iostream>
#include<stdlib.h>
//#include<stdio.h>
#include <stdio.h>

//using namespace std;
int main()
{
	//vector<int>L{ 1,2,45,7,8,45,423,1,2,4 };
	////sort(L.begin(),L.end(),greater<int>);
	//reverse(L.begin(),L.end());
	//for (auto e : L)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//list<int>a{ 2,4,5,7,8,9,65,3,2,2,1,4,5,6,7 };
	//reverse(a.begin(), a.end());
	////a.sort();
	//for (auto e : a)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	/*char str[110];
	char c;*/
	//char *str1;
	//c=getchar();
	// gets(str);
	/*while ((c = getchar()) != EOF)
	{}
	cout << c << endl;*/
	/*string s;
	
	getline(cin, s);
	*/
	char str[100] = "fsjkmskjjs";
	char str1[100] = { 's','a','ad','afd' };
	cout << sizeof(str) << " " << strlen(str)<< endl;
	cout << sizeof(str1) << " " << strlen(str1) << endl;

	system("pause");
	return 0;
}
