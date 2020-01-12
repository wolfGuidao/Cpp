class MyStack {
public:
	//主要思想是定义两个队列，入栈时，如果两个队列同时为空，就随便往一个队列中插入如果其中有一个队列不为空，每次插就往非空的队列中插入。出栈时，每次把非空队列的前size-1个元素移动到空队列中，原非空队列就只剩下最后一个元素，这个元素满足栈的要求，直接出队。总之，主要思想是把两个队列中的元素来回移动，每次剩下最后一个元素直接出队，就相当于是栈顶元素
		/** Initialize your data structure here. */
	MyStack() {
		queue<int>q1;
		queue<int>q2;
	}

	/** Push element x onto stack. */
	void push(int x) {
		//如果两个队列都为空，随便插入到一个队列中，反之插入到非空队列中
		if (!q1.empty())
		{
			q1.push(x);
		}
		else
		{
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		//每次把非空队列中的前size-1个元素移动到空队列中去，原非空队列剩下最后一个元素就相当于栈顶元素，出栈时，就直接出队
		int data;
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			data = q2.front();
			q2.pop();

		}
		else
		{
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			data = q1.front();
			q1.pop();
		}
		return data;
	}

	/** Get the top element. */
	int top() {
		//返回非空队列的队尾元素，就相当于栈顶元素，
		if (!q1.empty())
		{
			return q1.back();
		}
		else
		{
			return q2.back();
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		//两个队列同时为空是，此时才表明栈中没有任何元素
		return q1.empty() && q2.empty();
	}
private:

	queue<int>q1;
	queue<int>q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */