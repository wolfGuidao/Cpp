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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}
		if (l1 == nullptr&&l2 == nullptr)
		{
			return nullptr;
		}

		ListNode* head = new ListNode(1);//为l1创建以个头节点
		head->next = l1;//把头节点和l1链接起来

		ListNode* cur1 = l1;//定义临时节点指针记录l1的比较元素
		ListNode* cur2 = l2;//定义临时节点指针记录l2的比较元素
		ListNode* temp1 = head;//temp1始终指向cur1的前一个节点，方便插入
		ListNode* temp2 = cur2->next;//temp2指向cur2的后一个节点，因为一旦发生插入，l2已经被破坏，所以要提前记录，否则cur2就无法前进
		while (cur1&&cur2)
		{
			if (cur2->val < cur1->val)//如果cur2的val小于cur1的val就把cur2的节点插到cur1的前面
			{
				//if(temp1==cur1)
				//{
				//    temp2 = cur2->next;
				//    cur2->next=cur1;
				//    l1=cur2;
				//    temp1=cur2;
				//    cur2 = temp2;
				//    continue;
				//}

				temp2 = cur2->next;//保存cur2的下一个位置

				temp1->next = cur2;//执行插入操作
				cur2->next = cur1;

				temp1 = cur2;//因为可能发生头插，为了和正常插入保持一致，让temp1指向cur2，

				cur2 = temp2;//cur2后移
			}
			else//cur2的val大于cur1的val，就把cur1后移，让cur2和下一个cur1比较
			{
				temp1 = cur1;
				cur1 = temp1->next;//cur1后移
			}
		}
		if (cur1 == nullptr)//如果最后cur1走到结尾，而cur2还没走到结尾，就把cur2直接接到cur1的后面，如果cur2走到结尾，以为返回的就是cur1，且cur1本来就是有序的，所以就不用管
		{
			temp1->next = cur2;
		}
		return head->next;//因为我们建头节点的时候给头节点带了一个值，所以返回head->next
	}
};

#endif

class Date
{
public:
	void Printf()
	{
		cout << _a << endl;
	}
	void show()
	{
		cout << "hello world" << endl;
	}
private:
	int _a=10;
};

#if 0

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* head = new ListNode(1);
		head->next = pHead;
		ListNode* top = head;

		ListNode* cur = pHead;
		ListNode* temp = cur->next;

		if (pHead == nullptr)
		{
			return nullptr;
		}

		int count = 0;
		while (temp || count)
		{
			int a = cur->val;
			int b = temp->val;
			if (a == b)
			{
				if (temp->next != nullptr)
				{
					temp = temp->next;
					a = cur->val;
					b = temp->val;
					count++;
					continue;
				}

			}
			if (count != 0)
			{
				top->next = temp;
				count = 0;
			}
			else
			{
				top = cur;
			}
			cur = temp;
			temp = temp->next;
		}
		return head->next;
	}
};

#endif

#if 0


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* smallhead = new ListNode(0);//创建一个小于x的头节点
		ListNode* largehead = new ListNode(0);//创建一个大于等于x的头节点

		ListNode* small = smallhead;//定义头指针指向头节点
		ListNode* large = largehead;

		while (pHead)//每次比较头节点
		{
			if (pHead->val < x)
			{
				small->next = pHead;
				small = small->next;
				pHead = pHead->next;
			}
			else
			{
				large->next = pHead;
				large = large->next;
				pHead = pHead->next;
			}
		}
		small->next = largehead->next;//衔接，注意头节点内是有值的，跳过头节点，指向头节点的下一个节点
		large->next = nullptr;//置空
		return smallhead->next;
	}
};

#endif

#include<algorithm>
#include<vector>

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		auto it = nums.begin();
		sort(it, it + nums.size());

		int i = 0;
		int count = 0;
		while (i < nums.size() )
		{
			if (nums[i] == val)
			{
				nums.erase(it + i);
				//count++;
			}
			else
			{
				i++;
			}
		}
		return nums.size();
	}
};

//void Test()
//{
//	Date* p = nullptr;
//	//p->Printf();
//	p->show();
//}


void Test()
{
	vector<int>nums{ 3,2,2,3 };
	Solution s;
	s.removeElement(nums, 3);


}
int main()
{
	Test();
	system("pause");
	return 0;
}