#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct student
{
    int skill;
    int team;
    int position;

    student(int position = 0, int skill = 0, int team = 0)
    {
        this->skill = skill;
        this->team = team;
        this->position = position;
    }
};

struct Node
{
    student data;
    Node* prev, * next;
    Node* prevFree, * nextFree;

    Node() {

        this->data = student(0, 0);
        this->prev = NULL;
        this->next = NULL;
        this->nextFree = NULL;
        this->prevFree = NULL;
    }
    Node(student data, Node* prev = NULL, Node* next = NULL)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
        this->nextFree = next;
        this->prevFree = next;
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

    void addAtStart(student data)
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
            head->prev = temp;
            head = temp;
        }
        this->size++;
    }

    void addAtEnd(student data)
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
            temp->prev = tail;
            tail->nextFree = temp;
            temp->prevFree = tail;
            tail = temp;
        }
        this->size++;
    }

    void addAtPosition(int pos, student data)
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
            Node* previous = NULL, * curr;
            curr = head;
            for (int i = 0; i < pos; i++)
            {
                previous = curr;
                curr = curr->next;
            }
            previous->next = temp;
            temp->prev = previous;
            temp->next = curr;
            curr->prev = temp;
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

    Node* getAtPosition(int position)
    {
        Node* curr = head;
        int c = 0;
        while (curr->next != NULL && c < position)
        {
            c++;
            curr = curr->next;
        }
        return curr;
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
            head->prev = NULL;
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
            Node* previous = NULL, * curr = head;
            for (int i = 0; i < pos; i++)
            {
                previous = curr;
                curr = curr->next;
            }
            previous->next = curr->next;
            curr->next->prev = previous;
            delete curr;
            this->size--;
        }
    }

    void changeTeam(int k, Node* curr, int t)
    {
        Node* temp = curr;

        temp->data.team = t;
        int counter = 0;
        temp = temp->nextFree;
        while (counter < k && temp != NULL)
        {
            temp->data.team = t;
            temp = temp->nextFree;
            counter++;
        }
        curr->nextFree = temp;

        counter = 0;

        Node* tempLeft = curr;

        tempLeft = curr;
        tempLeft = tempLeft->prevFree;
        while (counter < k && tempLeft != NULL)
        {
            tempLeft->data.team = t;
            tempLeft = tempLeft->prevFree;
            counter++;
        }
        curr->prevFree = tempLeft;

        if (tempLeft != NULL) {
            tempLeft->nextFree = curr->nextFree;
        }
        if (temp != NULL) {
            temp->prevFree = curr->prevFree;
        }
    }

    Node* getTail()
    {
        return tail;
    }

    void print()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data.team;
            temp = temp->next;
        }
    }

private:
    Node* head, * tail;
    int size;
};

int n,k;

void solve() {
    cin >> n >> k;
    
    List students;
    Node** sortedSkills = new Node * [n];
    for (int i = 0; i < n; i++)
    {
        int skill;
        cin >> skill;
        students.addAtEnd(student(i, skill));
        sortedSkills[skill - 1] = students.getTail();
    }

    int team = 0;
    int i = n - 1;
    while (i >= 0)
    {
        students.changeTeam(k, sortedSkills[i], team % 2 + 1);
        team++;

        while (i >= 0 && sortedSkills[i]->data.team != 0) {
            i--;
        }
    }
    students.print();
    delete[] sortedSkills;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}
