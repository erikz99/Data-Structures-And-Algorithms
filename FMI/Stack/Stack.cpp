#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data = 0, Node * next = NULL)
	{
		this->data = data;
		this->next = NULL;
	}

};

class stack
{
	Node* top;

	stack()
	{
		this->top = NULL;
	}

	void push(int data)
	{
		Node* temp = new Node;
		temp->data = data;
		temp->next = top;
		top = temp;
	}

	int pop()
	{
		if (top != NULL)
		{	
			int data = top->data;
			Node* temp = top;
			top = temp->next;
			delete temp;
			return data;
		}
		else
		{
			return;
		}
	}

	int peek()
	{
		return top->data;
	}

	bool isEmpty()
	{
		return top == NULL;
	}

};