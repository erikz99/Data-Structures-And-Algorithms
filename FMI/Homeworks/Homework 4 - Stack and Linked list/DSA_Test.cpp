#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int data = 0, Node* next = NULL, Node* prev = NULL)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

class List
{
public:

    List()
    {
        head = NULL;
        tail = NULL;
        mid = NULL;
        this->size = 0;
    }

    void addAtEnd(int data)
    {
        Node* temp = new Node(data);
        if (this->size == 0)
        {
            head = temp;
            tail = temp;
            mid = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            if ((size > 1) && (size % 2 != 0)) {
                mid = mid->next;
            }
        }
        this->size++;
    }

    void delAtEnd()
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
            mid = NULL;
            this->size--;
        }
        else
        {
            if ((size % 2 == 0) && (size > 2)) {
                mid = mid->prev;
            }
            Node* curr = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete curr;
            this->size--;
        }
    }

    void print()
    {
        Node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void shuffle() {
        if (size == 1) {
            return;
        }
        tail->next = head;
        head->prev = tail;
        head = mid->next;
        if (size % 2 == 0) {
            mid = tail;
        }
        else {
            mid = tail->prev;
        }
        tail = head->prev;
        tail->next = nullptr;
    }

    Node* head, * tail, * mid;
    int size;
};

int n;

void init() {
    cin >> n;
}

void solve() {
    List l;
    char cmd[10];
    int number;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (strcmp(cmd, "add") == 0) {
            cin >> number;
            l.addAtEnd(number);
        }
        else if (strcmp(cmd, "gun") == 0) {
            l.delAtEnd();
        }
        else if (strcmp(cmd, "milen") == 0) {
            l.shuffle();
        }
    }
    cout << l.size << "\n";
    if (l.size > 0) {
        l.print();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
    
    return 0;
}