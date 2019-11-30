#include<iostream>
using namespace std;

#if 0

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node* cur = head;
		//因为拷贝出来的节点地址和原来的节点没有任何关系，所以置random时应当注意
		while (cur)//第一步在原链表的每一个节点后面拷贝相同的节点插在每一个节点的后面
		{
			Node* temp = cur->next;
			Node* copy = new Node(cur->val);
			cur->next = copy;
			copy->next = temp;
			cur = temp;

		}
		cur = head;
		while (cur)//第二部，置拷贝出来的节点的random
		{
			Node* temp1 = cur->next;
			Node* temp2 = temp1->next;
			if (cur->random == nullptr)//判断节点的random是否为空
				temp1->random = nullptr;
			else
				temp1->random = cur->random->next;
			cur = temp2;

		}
		Node* newhead = nullptr;
		Node* newheadtail = nullptr;
		cur = head;
		while (cur)//第三步，把拷贝出来的节点解开组成一个新的链表，并恢复原链表
		{
			Node* temp1 = cur->next;
			Node* temp2 = temp1->next;

			if (newhead == nullptr)
			{
				newhead = newheadtail = temp1;
				newheadtail = temp1;

			}
			else
			{
				newheadtail->next = temp1;
				newheadtail = temp1;
			}
			cur->next = temp2;
			cur = temp2;
		}
		return newhead;
	}
};

#endif


int main()
{

	system("pause");
	return 0;
}