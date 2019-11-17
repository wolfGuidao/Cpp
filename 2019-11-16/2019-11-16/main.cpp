#include<iostream>
using namespace std;

#if 0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
		{
			return true;
		}
		if (head->next == nullptr)
		{
			return true;
		}
		ListNode* slower = head;
		ListNode* faster = head->next;
		stack<int>s;
		int count = 0;
		while (faster&&faster->next)
		{
			slower = slower->next;
			faster = faster->next->next;
		}
		ListNode* cur = head;
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		cur = head;

		if (count % 2 == 0)
		{
			slower = slower->next;

			while (slower != cur)
			{
				s.push(cur->val);
				cur = cur->next;
			}
		}
		else
		{
			while (slower != cur)
			{
				s.push(cur->val);
				cur = cur->next;
			}
			slower = slower->next;
		}

		while (!s.empty())
		{
			if (s.top() == slower->val)
			{
				s.pop();
				slower = slower->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

#endif

void reverse(char* str)//递归反转字符串
{
	int len = strlen(str);//每次递归结束都要求一下len
	char* str_end =str + len - 1;//str_len会随着len的减少而不断往前移动
	char temp = 0;//临时变量，

	if (len < 2)//递归出口，如果len小于2，说明已经把后半部分递归完毕，就不用再递归下去了
	{
		return;
	}
	else
	{
		temp = *str;//首先把第一个元素保存起来
		*str = *str_end;//把最后一个元素放在第一个元素的位置，完成最后一个字符串的反转
		*str_end = '\0';//把最后一位置为\0，让str的长度不断缩短，使得str_end不断往前移动
		reverse(++str);//递归把后面的元素都放到前面，把前面的元素用临时变量保存起来，直到srt的长度小于2中止递归
		*str_end = temp;//完成后半部分的逆置后，在分别把temp中的元素放在str_end的位置
	}
}

int main()
{
	char str[20];
	cin >> str ;
	reverse(str);
	cout << str << endl;
	system("pause");
	return 0;
}