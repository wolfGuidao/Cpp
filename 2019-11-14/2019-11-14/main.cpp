#include<iostream>
using namespace std;

#if 0

class Solution {
public:
	int cutRope(int number) {
		/*if(number<2)
		{
			return 0;
		}
		if(number==2)
		{
			return 1;
		}
		if(number==3)
			return 2;
		int x=number/3;
		int y=number%3;

		if(y==0)
		{
			return pow(3,x);
		}
		if(y==1)
		{
			return  4*pow(3,x-1);
		}
		else
		{
			return 2*pow(3,x);
		}
		*/
		static int n = 0;
		int x = 0, i;
		if (number == 2)
			return n == 0 ? 1 : 2;
		if (number == 3)
			return n == 0 ? 2 : 3;
		n++;
		for (i = 1; i <= number / 2; i++)
		{
			if (cutRope(i)*cutRope(number - i) > x)
			{
				x = cutRope(i)*cutRope(number - i);
			}
		}
		return x;
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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {

		ListNode* cur = root;//用来循环判断的
		ListNode* cur2 = nullptr;//指向cur的下一个，因为放入vector中的不一定是单个节点，可能会把链表截断，防止cur找不到下一个节点
		ListNode* cur1 = cur;//记录开始要放入vector中的第一个节点
		vector<ListNode*>s;

		int count = 0;//用来计算链表节点个数
		int count1 = 0;//用来记录vector每次要放的个数
		while (cur)
		{
			count++;
			cur = cur->next;
		}

		int m = count % k;
		int n = count / k;

		cur = root;
		if (count <= k)
		{
			ListNode* temp;

			while (cur)
			{
				s.push_back(cur);
				temp = cur->next;
				cur->next = nullptr;
				cur = temp;
				count--;
			}
			if (s.size() < k)
			{
				s.resize(k, NULL);
			}

		}
		else
		{
			while (cur)
			{

				count1 = n + (m == 0 ? 0 : 1) - 1;//因为要保持前面的部分的长度比后面的部分长度长，且长度差不能超过1；
				while (count1)//用循环控制每次vector中因该放多少个
				{
					cur = cur->next;
					count1--;
				}
				if (m > 0)//因为m一直减可能会为负数，最好加一个判断
					m--;
				s.push_back(cur1);//因为cur1一直指向要往vector中放的第一个节点，所以直接push，后面再把链表截断


				cur2 = cur->next;//记录cur的下一个位置，防止cur找不到路
				cur->next = nullptr;//置为空，截断链表

				cur = cur2;//往后移动
				cur1 = cur2;

			}
		}
		return s;
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
	ListNode* oddEvenList(ListNode* head) {
		/*
		 ListNode* A=new ListNode(1);
		 ListNode* B=new ListNode(1);

		 ListNode* headA=A;
		 ListNode* headB=B;

		 ListNode* cur=head;
		 int count=0;
		 while(cur)
		 {
			 count++;
			 cur=cur->next;
		 }

		 cur=head;

			 for(int i=1;i<=count;i++)
			 {
				 if(i%2!=0)
				 {
					 headA->next=cur;
					 headA=cur;
					 cur=cur->next;
				 }
				 else
				 {
					 headB->next=cur;
					 headB=cur;
					 cur=cur->next;
				 }
		 }
		 headA->next=B->next;
		 return B->next;
		 */
		if (head == nullptr)
			return nullptr;

		ListNode* oddhead = head;//定义一个奇数头指针指向链表的头
		ListNode* evenhead = head->next;//定义一个偶数头指针指向链表的第二个节点
		ListNode* odd = oddhead;//定义一个奇数节点指针，每次都指向链表中奇数节点，把奇数节点接在奇数头指针后面
		ListNode* even = evenhead;//定义一个偶数节点指针，每次都指向链表中偶数节点，把偶数节点接在偶数头节点后面

		while (even&&even->next)//
		{
			odd->next = even->next;//画个图就很容易，
			odd = even->next;
			even->next = odd->next;
			even = odd->next;
		}
		odd->next = evenhead;//把偶数的头节点接在奇数的后面
		return oddhead;

	}
};

#endif
int main()
{


	system("payse");
	return 0;
}