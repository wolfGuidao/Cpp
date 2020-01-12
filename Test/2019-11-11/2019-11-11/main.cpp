#include<iostream>
using namespace std;

#if 0

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		auto it = nums.begin();
		sort(it, it + nums.size());//排序

		int count = 1;//记录相同数字的个数
		int i = 1;//防止vector越界问题，从1开始和前面一个进行比较
		while (i < nums.size())
		{
			if (nums[i - 1] == nums[i])//如果相等，就给count++
			{
				count++;

			}
			else//一旦不想等
			{
				count = 1;
			}

			if (count > 2)
			{
				nums.erase(it + i);
				count--;
			}
			else
			{
				i++;
			}
		}
		return nums.size();
	}
};

#endif

#if 0

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* cur1 = headA;
		ListNode* cur2 = headB;

		int count1 = 0;
		int count2 = 0;

		while (cur1)
		{
			count1++;
			cur1 = cur1->next;
		}
		while (cur2)
		{
			count2++;
			cur2 = cur2->next;
		}


		cur1 = headA;
		cur2 = headB;
		int count = 0;
		
			if (count1 > count2)
			{
				count = count1 - count2;
				while (count)
				{
					cur1 = cur1->next;
					count--;
				}
				while (cur1&&cur2)
				{
					if (cur1 == cur2)
					{
						return cur1;
					}
					else
					{
						cur1 = cur1->next;
						cur2 = cur2->next;
					}
				}
			}
			else if (count1 < count2)
			{
				count = count2 - count1;

				while (count)
				{
					cur2 = cur2->next;
					count--;
				}
				while (cur1&&cur2)
				{
					if (cur1 == cur2)
					{
						return cur2;
					}
					else
					{
						cur1 = cur1->next;
						cur2 = cur2->next;
					}
				}
			}
			else
			{
				while (cur1&&cur2)
				{
					if (cur1 == cur2)
					{
						return cur2;
					}
					else
					{
						cur1 = cur1->next;
						cur2 = cur2->next;
					}
				}
			}
		
		return nullptr;
	}
};
#endif

#if 0

int removeElement(int* nums, int numsSize, int val) {
	int src = 0;
	int des = 0;

	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[des] = nums[src];
			src++;
			des++;
		}
		else
		{
			src++;
		}
	}
	return des;
}

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
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return false;
		}
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (slow != fast)
		{
			if (fast == nullptr || fast->next == nullptr)
			{
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;


	}
};

#endif
int main()
{
	return 0;
}