#include<iostream>
#include<queue>
using namespace std;


class MyCircularQueue {
public:
	//主要思想是定义一个数组，空间设为k+1个，留一个空间进行区别判满和判空，采用取模运算进行循环，判满条件是（rear+1）%len==front，判空条件是rear==front
	MyCircularQueue(int k) {
		len = k + 1;
		//vector<int>q;
		q.resize(len);
		front = 0;
		rear = 0;

	}


	bool enQueue(int value) {
		if ((rear + 1) % len == front)
		{
			return false;
		}
		else
		{
			q[rear] = value;
			rear = (rear + 1) % len;
			return true;
		}
	}


	bool deQueue() {
		if (front == rear)
		{
			return false;
		}
		else
		{
			front = (front + 1) % len;
			return true;
		}
	}


	int Front() {
		if (rear == front)
			return -1;
		return q[front];
	}


	int Rear() {
		if (rear == front)
			return -1;
		return q[(rear - 1 + len) % len];
	}


	bool isEmpty() {
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool isFull() {
		if ((rear + 1) % len == front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	vector<int> q;
	int len;
	int front;
	int rear;

};


/*
class MyCircularQueue {
  public:

	MyCircularQueue(int k) {
		len = k+1;
		data.resize(len);
		front = 0,rear = 0; //front指向队头 rear 指向队尾的下一个位置
	}


	bool enQueue(int value) {
		if(isFull()) return false;//满时队列无法插入
		data[rear] = value,rear = (rear+1)%len;
		return true;
	}


	bool deQueue() {
		if(isEmpty()) return false;
		front = (front+1)%len;
		return true;
	}


	int Front() {
		if(isEmpty())
		 return -1;
		return data[front];
	}


	int Rear() {
		if(rear==front) return -1;
		return data[(rear-1+len)%len];
	}


	bool isEmpty() {
		return rear==front;
	}

	bool isFull() {
		return (rear+1)%len==front;
	}
	private:
	vector<int> data;
	int len;
	int front;
	int rear;
};
*/


int main()
{
	queue<int>q;
	q.rear->next = q.front;
	system("pause");
	return 0;
}