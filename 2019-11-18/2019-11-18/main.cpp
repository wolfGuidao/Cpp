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
		/*
		ListNode* head=new ListNode(1);//创建一个头节点
		head->next=pHead;

		ListNode* cur1=head;//cur1指向头节点
		ListNode* cur2=pHead;//cur1指向第一个节点

		if(pHead==nullptr)
		{
			return nullptr;
		}

		int count=0;//设一个标志量
		while(1)
		{
			if(cur2->next==nullptr)
			{
				if(count)
				{
					count=0;
					cur2=cur2->next;
					cur1->next=cur2;
				}
				break;
			}
			if(cur2->next->val==cur2->val)//如果发现cur2->next->val==cur2->val，就删除cur2-》next；并把标志量置为1
			{
				count++;
				cur2->next=cur2->next->next;
			}
			else
			{
				if(count==0)//如果count等于0，说明没有删除过，就直接往后移
				{
					cur2=cur2->next;
					cur1=cur1->next;

				}
				else//如果发生删除操作，还得把cur2的那个位置给删掉，并且把count置为0
				{
					count=0;
					cur2=cur2->next;
					cur1->next=cur2;
				}
			}
		}
		return head->next;
		*/
		if (pHead == nullptr)
		{
			return nullptr;
		}
		if (pHead->next == nullptr)
		{
			return pHead;
		}
		//
		ListNode* cur = pHead;
		ListNode* temp = pHead->next;
		ListNode* list = new ListNode(0);
		ListNode* listtail = list;
		//主要思想是创建一个新的头节点指针，如果发现cur和temp指向的两个节点值不相等，就把cur尾插到新节点后面，
		while (temp)//
		{
			if (cur->val == temp->val)//如果两个节点值相等，就执行往后移动
			{
				while (cur->val == temp->val&&temp)//如果两个节点值相等，就把temp往后
					//移动，直到把temp放在和cur不相等的节点上，或者temp=nullptr
				{
					temp = temp->next;
				}
				while (cur != temp)//从cur开始，一直删除到temp位置处
				{
					ListNode* next = cur;
					cur = cur->next;
					delete next;
				}

				if (temp)//因为temp因为元素相等而放到空位置上，此时就不能再让temp进行next操作
					temp = temp->next;
			}
			else//两个值不相等，就把cur的值尾插到头节点的后面
			{
				listtail->next = cur;
				listtail = cur;
				cur = temp;
				temp = temp->next;
			}
		}
		listtail->next = cur;//最后可能会出现末尾全部都是相同的元素，如果按照代码执行，listtail还指向原来的节点,所以的置为cur
		return list->next;
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
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		/*
		if(A==nullptr)
		{
			return false;
		}
		else if(A->next==nullptr)
		{
			return true;
		}

		vector<int> s;
		ListNode* cur=A;
		while(cur)
		{
			s.push_back(cur->val);
			cur=cur->next;
		}
		int start=0;
		int end=s.size()-1;
		while(start<end)
		{
			if(s[start]==s[end])
			{
				start++;
				end--;
			}
			else{
				return false;
			}
		}
		return true;
		*/
		ListNode* faster = A;//这种方法是把链表的后半部分进行反转，这样一个指针重前往后，一个指针重后往前进行比较
		ListNode* slower = A;
		ListNode* prev = A;
		ListNode* cur = A;
		int count = 0;
		while (cur)//用来求链表长度，后面要分奇偶
		{
			count++;
			cur = cur->next;
		}
		while (faster&&faster->next)//用快慢指针找到奇数链表的最中间一个节点，偶数链表中间两个节点的右边节点，就是faster
		{
			slower = slower->next;
			faster = faster->next->next;
		}
		ListNode* sss = slower;//临时变量
		prev = slower;//为后面反转做铺垫
		slower = slower->next;
		ListNode* next = slower;
		while (next)//完成反转
		{
			next = slower->next;
			slower->next = prev;
			prev = slower;
			if (next)
				slower = next;
		}
		if (count % 2 == 0)//分奇偶进行比较
		{
			cur = A;
			while (cur->next != sss)
			{
				if (cur->val == slower->val)
				{
					cur = cur->next;
					slower = slower->next;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			cur = A;
			while (cur != sss)
			{
				if (cur->val == slower->val)
				{
					cur = cur->next;
					slower = slower->next;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}
};

#endif