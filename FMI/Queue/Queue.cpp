#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data = 0, Node * next = NULL)
	{
		this->data = data;
		this->next = next;
	}
};

class Queue
{
private:
	Node* front;
	Node* back;
	int size;

public:
	
	Queue()
	{
		this->front = NULL;
		this->back = NULL;
		this->size = 0;
	}

	void enqueue(int data)
	{
		Node* temp = new Node(data);
		if (front == NULL && back == NULL)
		{
			front = temp;
			back = temp;
		}
		else
		{
			back->next = temp;
			back = temp;
		}
		size++;
	}

	void dequeue()
	{
		if (front != NULL)
		{
			if (front == back)
			{
				Node* temp = front;
				front = NULL;
				back = NULL;
				delete temp;
			}
			else
			{
				Node* temp = front;
				front = front->next;
				delete temp;
				size--;
			}
		}


	}

	int peek()
	{
		if (front == NULL)
		{
			return -1;
		}
		else
		{
			return front->data;
		}
	}

	bool isEmpty()
	{
		return size == 0;
	}

};

int main()
{
	Queue q;
	q.enqueue(5);
	cout << q.peek() << "\n";
	q.enqueue(100);
	cout << q.peek() << "\n";
	q.enqueue(241241);
	cout << q.peek() << "\n";
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.enqueue(1000);
	cout << q.peek() << "\n";
	cout << q.isEmpty();	
}