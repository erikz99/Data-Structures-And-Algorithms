#include <iostream>
using namespace std;

struct Node
{
	int data; 
	Node* next;

	Node(int data=0, Node* next=NULL)
	{
		this->data = data;
		this->next = next;
	}
};

class List
{
public:
	
	List()
	{
		head = NULL;
		tail = NULL;
		this->size = 0;
	}

	void addAtStart(int data)
	{
		Node* temp = new Node(data);
		if (size == 0)
		{
			head = temp;
			tail = temp;
		}
		else 
		{
			temp->next = head;
			head = temp;
		}
		this->size++;
	}

	void addAtEnd(int data)
	{
		Node* temp = new Node(data);
		if (this->size==0)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		this->size++;
	}

	void addAtPosition(int pos, int data)
	{
		if (pos == 0)
		{
			addAtStart(data);
		}
		else if (pos == size)
		{
			addAtEnd(data);
		}
		else if (pos > 0 && pos <= size - 1)
		{
			Node* temp = new Node(data);
			Node* prev=NULL, * curr;
			curr = head;
			for (int i = 1; i < pos; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = temp;
			temp->next = curr;
			this->size++;
		}
		else
		{
			cout << "Position is not correct" << endl;
		}
	}

	void delAtEnd()
	{
		if (size == 0)
		{
			cout << "Empty list" << endl;
		}
		else if (size == 1)
		{
			delAtStart();
		}
		else
		{
			Node *curr = head, *prev=NULL;
			while (curr->next!= NULL)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = NULL;
			tail = prev;
			delete curr;
			this->size--;
		}
	}

	void delAtStart()
	{
		if (size == 0)
		{
			cout << "Empty list" << endl;
		}
		else if (size == 1)
		{
			Node* temp = head;
			delete temp;
			head = NULL;
			tail = NULL;
			this->size--;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			this->size--;
		}
	}

	void delAtPosition(int pos)
	{
		if (pos<0 || pos >size - 1)
		{
			cout << "Wrong position" << endl;
		}

		else if (pos == 0)
		{
			delAtStart();
		}

		else if (pos == size - 1)
		{
			delAtEnd();
		}
		
		else
		{
			Node* prev, * curr = head;
			for (int i = 1; i < pos ; i++)
			{
				prev = curr;
				curr = curr->next;
			}
			prev->next = curr->next;
			delete curr;
			this->size--;
		}
	}

	void print()
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << curr->data << "\n";
			curr = curr->next;
		}
	}

	bool search(int data)
	{
		Node* curr = head;
		while (curr != NULL)
		{
			if (curr->data == data)
			{
				return true;
			}
			curr = curr->next;
		}
		return false;
	}

private:
	Node* head, * tail;
	int size;
};

int main()
{
	List list1;

	for (int i = 0; i < 10; i++)
	{
		list1.addAtStart(i+1);
	}
	list1.print();
}