#include<iostream>
#include<Windows.h>
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
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr)
		{
			return head;
		}
		ListNode* cur = head;//判断当前节点
		ListNode* temp = cur;//指向当前节点的前一个节点
		while (cur)
		{
			if (cur->val == val)
			{
				if (cur == head)//要删除位置在头
				{
					head = cur->next;
					cur = head;
					if (head == nullptr)//如果删完后链表变为空，就直接返回
					{
						return head;
					}
					else
					{
						continue;//continue防止跳过一个节点
					}
				}
				else if (cur->next == nullptr)//如果要删除的位置在结尾
				{
					temp->next = nullptr;
					return head;
				}
				else//要删除的节点在中间
				{
					temp->next = cur->next;
					cur = temp->next;
					continue;//如果没有continue，就会跳过一个节点
				}
			}
			temp = cur;
			cur = cur->next;
		}
		return head;
	}
};

#endif

#if  0

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
	ListNode* reverseList(ListNode* head) {
		ListNode* prv = nullptr;//记录前驱
		ListNode* cur = head;//当前节点
		ListNode* temp;//记录cur的下一个节点
		while (cur)
		{
			temp = cur->next;
			cur->next = prv;//反转
			prv = cur;//后移
			cur = temp;//判断节点后移
		}
		head = prv;//把头节点接上
		return head;
	}
};

#endif

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
	ListNode* middleNode(ListNode* head) {
		ListNode* cur = head;
		ListNode* temp;
		int count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		cur = head;
		int i = count / 2 + 1;
		while (i > 0)
		{
			temp = cur;
			cur = cur->next;
			i--;
		}
		return temp;
	}
};

#endif

#if 0

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int x = 0;
		int num1 = 0;
		int num2 = 0;
		for (auto i : nums)
			x ^= i;//异或的结果一定为数组nums中只出现一次的两个数字异或结果，且x一定有一位为1，x不可能为0

		int pos = 0;//用来记录x中哪一位为1
		for (;pos < 32;pos++)
		{
			if (x & (1 << pos))//如果1左移pos位和x与，说明第pos位为1
			{
				break;//如果找到就直接返回
			}
		}

		vector<int> ans;//存储结果
		for (auto i : nums) {//遍历原数组，因为两个只出现一次的元素在第pos位一定是不一样的，
			if (i & (1 << pos))//分为2组num1和num2：那两个只出现一次的元素一定不在同一组，所以这样就把只出现一次的两个元素分开了，
			{
				num1 ^= i;//如果数组中元素的第pos位为1，
			}
			else
			{
				num2 ^= i;
			}
		}
		ans.push_back(num1);
		ans.push_back(num2);
		return ans;
	}
};

#endif

int main()
{
	system("pause");
	return 0;
}
