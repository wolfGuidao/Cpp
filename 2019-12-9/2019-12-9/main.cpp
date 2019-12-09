class MyQueue {
public:
	//主要思想是定义两个栈，一个用来存放入队元素的栈s1，另一个栈用来进行出队操作的s2，往队列中插元速时，直接往s1中插入，出队时，如果s2不为空，直接在s2中进行出栈操作，如果s2为空，就把s1中元素全部放到s2中
		/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		//直接往s1中插入
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		//进行出队操作时，如果s2为空，就直接把s1中元素先移动到s2中，在进行出队操作，如果s2不为空，直接在s2中直接出队，注意不能在s2有元素时把s1中的元素移动到s2中，这样顺序回乱
		int data;
		if (s2.empty())
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
			data = s2.top();
			s2.pop();
		}
		else
		{
			data = s2.top();
			s2.pop();
		}
		return data;

	}

	/** Get the front element. */
	int peek() {
		int data;
		if (s2.empty())
		{
			while (s1.size())
			{
				s2.push(s1.top());
				s1.pop();
			}
			data = s2.top();
			//s2.pop();
		}
		else
		{
			data = s2.top();
			//s2.pop();
		}
		return data;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty() && s2.empty();
	}
private:
	stack<int>s1;
	stack<int>s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */