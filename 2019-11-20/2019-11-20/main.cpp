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
	void deleteNode(ListNode* node) {
		ListNode* cur = node;
		ListNode* temp = node->next;

		int a = temp->val;
		temp->val = node->val;
		node->val = a;
		node->next = temp->next;

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
	ListNode* deleteDuplicates(ListNode* head) {
		/*
		if(head==nullptr)
		{
			return nullptr;
		}
		if(head->next==nullptr)
		{
			return head;
		}
		//
		ListNode* cur=head;
		ListNode* temp=head->next;
		ListNode* list=new ListNode(0);
		ListNode* listtail=list;
		//主要思想是创建一个新的头节点指针，如果发现cur和temp指向的两个节点值不相等，就把cur尾插到新节点后面，
		while(temp)//
		{
			if(cur->val==temp->val)//如果两个节点值相等，就执行往后移动
			{
				while(cur->val==temp->val&&temp)//如果两个节点值相等，就把temp往后
					//移动，直到把temp放在和cur不相等的节点上，或者temp=nullptr
				{
					temp=temp->next;
				}
				while(cur!=temp)//从cur开始，一直删除到temp位置处
				{
					ListNode* next=cur;
					cur=cur->next;
					delete next;
				}

				if(temp)//因为temp因为元素相等而放到空位置上，此时就不能再让temp进行next操作
				temp=temp->next;
			}
			else//两个值不相等，就把cur的值尾插到头节点的后面
			{
				listtail->next = cur;
				listtail=cur;
				cur=temp;
				temp=temp->next;
			}
		}
		listtail->next=cur;//最后可能会出现末尾全部都是相同的元素，如果按照代码执行，listtail还指向原来的节点,所以的置为cur
		return list->next;
		*/
		ListNode* hhead = new ListNode(1);//创建一个头节点
		hhead->next = head;

		ListNode* cur1 = hhead;//cur1指向头节点
		ListNode* cur2 = head;//cur1指向第一个节点

		if (head == nullptr)
		{
			return nullptr;
		}

		int count = 0;//设一个标志量
		while (1)
		{
			if (cur2->next == nullptr)
			{
				if (count)
				{
					count = 0;
					cur2 = cur2->next;
					cur1->next = cur2;
				}
				break;
			}
			if (cur2->next->val == cur2->val)//如果发现cur2->next->val==cur2->val，就删除cur2-》next；并把标志量置为1
			{
				count++;
				cur2->next = cur2->next->next;
			}
			else
			{
				if (count == 0)//如果count等于0，说明没有删除过，就直接往后移
				{
					cur2 = cur2->next;
					cur1 = cur1->next;

				}
				else//如果发生删除操作，还得把cur2的那个位置给删掉，并且把count置为0
				{
					count = 0;
					cur2 = cur2->next;
					cur1->next = cur2;
				}
			}
		}
		return hhead->next;
	}
};

#endif

#if 0

/*
只需要完成逆置链表函数
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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
		{
			return pHead;
		}
		ListNode* cur = pHead;
		ListNode* temp = pHead;
		ListNode* prev = nullptr;
		while (temp)
		{
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			if (temp)
				cur = temp;

		}
		return cur;
	}
};

#endif

#include<list>

int main()
{
	
	system("pause");
	return 0;
}