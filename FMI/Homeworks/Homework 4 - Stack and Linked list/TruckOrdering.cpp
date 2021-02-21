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
public:
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
            return 0;
        }
    }

    int peek()
    {
        if (top == NULL)
        {
            return 0;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
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
        if (this->size == 0)
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
    void addAfter(Node* curr, int data) {
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
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
            Node* prev = NULL, * curr;
            curr = head;
            for (int i = 0; i < pos; i++)
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
            Node* curr = head, * prev = NULL;
            while (curr->next != NULL)
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
            Node* prev=NULL, * curr = head;
            for (int i = 0; i < pos; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
            this->size--;
        }
    }
    
    void delBefore(Node* prev, Node* curr)
    {
        Node* temp1 = prev, *temp2 = curr;
        temp1->next = temp2->next;
        delete temp2;
    }

    bool sort()
    {
        stack streets;
        int position = 0;
        Node* temp = head, *prev=head;
        while (temp->next!=NULL)
        {
            if (temp->data > (position+1))
            {
                if (!streets.isEmpty() && (streets.peek()==(position+1)))
                {
                    addAfter(temp, streets.pop());
                    position++;
                    prev = prev->next;
                }
                else
                {
                    if ((temp->data > streets.peek()) && !streets.isEmpty()) return false;
                    streets.push(temp->data);
                    Node* tempCopy = temp;
                    temp = temp->next;
                    delBefore(prev,tempCopy);
                    prev = temp;
                }
            }
            else
            {
                temp = temp->next;
                position++;
                prev = temp;
            }
        }
        return true;
    }

private:
    Node* head, *tail;
    int size;
};

int t;

void init() {
    cin >> t;
}

void solve() {
    for (int i = 0; i < t; i++)
    {
        List trucks;
        int n;
        cin >> n;
        if (n == 0 || n == 1 || n==2) cout << "yes" << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                int num;
                cin >> num;
                trucks.addAtEnd(num);
            }
            if (trucks.sort()) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
}
