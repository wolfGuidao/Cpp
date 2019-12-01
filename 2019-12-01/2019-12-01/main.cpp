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
	ListNode* insertionSortList(ListNode* head) {

		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* cur1 = head;//用来比较的前一个节点
		ListNode* cur2 = head->next;//用来比较的后一个节点
		while (cur2)//循环比较
		{
			while (cur2&&cur2->val > cur1->val)//如果后一个节点的值比前一个节点的值大，就直接把两个指针往后移动，反之退出循环
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			//退出循环有两种情况
			if (cur2 == nullptr)//第一种是因为cur2为空退出循环，说明链表中所有节点都满足后一个节点比前一个节点大，就直接返回
			{
				return head;
			}
			//第二种是因为出现后一个节点的值比前一个节点的值小，这样就必须把后一个节点提出来，找一个合适的位置插入进去
			ListNode* temp = cur2;//临时用temp表示后一个比较小的节点，也就是待插入的节点
			cur2 = cur2->next;//cur2自己则记录下一个，用来控制循环前进
			//把temp插入的时候分两种情况
			if (temp->val <= head->val)//第一种情况是他比头节点小
			{
				temp->next = head;
				head = temp;
			}
			else//第二种是在链表除头节点外的任意位置
			{
				ListNode* tempp = head;//可能会用到遍历，头节点不动，动tempp
				while (temp->val > tempp->next->val)//为了方便插入，直接和tempp的next比较，因为处于else中，肯定比一个节点的值大，拿temp和tempp的下一个节点进行比较，如果比下一个节点大，就直接把tempp往后移动
				{
					tempp = tempp->next;
				}
				//反之就是temp比tempp的下一个小，但肯定是比tempp大或相等，就直接插到tenpp的后面
				temp->next = tempp->next;
				tempp->next = temp;

			}
			cur1->next = cur2;//把用来比较的前一个节点连上
			//进行循环比较
		}
		return head;

		/*
		if(head==nullptr||head->next==nullptr)
		{
			return head;
		}

		ListNode* newhead=new ListNode(0);//定义一个头节点方便插入
		newhead->next=head;

		ListNode* cur=head;//从链表的第一个节点处断开，即现在的头节点只链接一个节点
		ListNode* temp=cur->next;//用temp指向剩下的节点
		cur->next=nullptr;
		while(temp)//循环遍历
		{
			ListNode* cur1=temp->next;//记录temp的下一个节点，防止后面插temp后，找不到

			ListNode* tempp=newhead;//用来遍历循环

			while(tempp->next&&tempp->next->val<=temp->val)//给temp找合适的插入位置
			{
				tempp=tempp->next;
			}
			temp->next=tempp->next;
			tempp->next=temp;

			temp=cur1;//连接上继续循环判断
		}
		return newhead->next;
		*/
		/*
		if(head==nullptr||head->next==nullptr)
		{
			return head;
		}
		for(ListNode* i=head;i;i=i->next)
		{
			for(ListNode* j=i->next;j;j=j->next)
			{
				if(i->val>j->val)
				{
					int temp=j->val;
					j->val=i->val;
					i->val=temp;
				}
			}
		}
		return head;
		*/
	}
};