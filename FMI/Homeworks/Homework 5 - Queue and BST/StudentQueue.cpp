#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Student
{
    string name;
    int group;
    int position;
    int in;
    int out;

    Student(string name = "", int group = 0, int in = 0, int out = 0)
    {
        this->name = name;
        this->group = group;
        this->in = in;
        this->out = out;
    }
};

struct Node
{
    Student* stud;
    Node* next;

    Node(Student* stud, Node* next = NULL)
    {
        this->stud = stud;
        this->next = NULL;
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

    void addAtStart(Student* stud)
    {
        Node* temp = new Node(stud);
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

    void addAtEnd(Student* stud)
    {
        Node* temp = new Node(stud);
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

    void addAtPosition(int pos, Student* stud)
    {
        if (pos == 0)
        {
            addAtStart(stud);
        }
        else if (pos == size)
        {
            addAtEnd(stud);
        }
        else if (pos > 0 && pos <= size - 1)
        {
            Node* temp = new Node(stud);
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
            Node* curr = head, * prev = head;
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
            Node* prev = NULL, * curr = head;
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

    Student* getHead()
    {
        if (head != NULL)
        {
            return head->stud;
        }
        return NULL;
    }

    bool empty()
    {
        return this->size == 0;
    }

    void print()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->stud->name << endl;
            temp = temp->next;
        }
    }

private:
    Node* head, * tail;
    int size;
};

int n,m;
int gr[100010];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m + 1; i++)
    {
        gr[i] = 0;
    }
    int time = 0;
    List q;
    vector <Student*> s;
    vector < queue <Student*> > students(m + 1);

    int groupQueue;
    bool b = true;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int group;
        cin >> group;
        if (gr[group] != 0)
        {
            Student* s = new Student(name, group, time);
            students[group].push(s);
            gr[group]++;
        }
        else
        {
            Student* s = new Student(name, group, time);
            gr[group]++;
            q.addAtEnd(s);
        }
        if (time % 2 == 0 && time != 0)
        {
            Student* stud = q.getHead();
            if (b)
            {
                if (gr[stud->group] == 1)
                {
                    q.delAtStart();
                    gr[stud->group]--;
                    stud->out = time;
                    s.push_back(stud);
                }
                else
                {
                    groupQueue = stud->group;
                    q.delAtStart();
                    gr[stud->group]--;
                    stud->out = time;
                    s.push_back(stud);
                    b = false;
                }
            }
            else
            {
                Student* temp = students[groupQueue].front();
                temp->out = time;
                gr[groupQueue]--;
                students[groupQueue].pop();
                if (gr[groupQueue] == 0)
                {
                    b = true;
                }
                s.push_back(temp);
            }

        }
        time++;
    }

    while (s.size()!=n)
    {
        if (time % 2 == 0)
        {
            Student* stud = q.getHead();
            if (b)
            {
                if (gr[stud->group] == 1)
                {
                    q.delAtStart();
                    gr[stud->group]--;
                    stud->out = time;
                    s.push_back(stud);
                }
                else
                {
                    groupQueue = stud->group;
                    q.delAtStart();
                    gr[stud->group]--;
                    stud->out = time;
                    s.push_back(stud);
                    b = false;
                }
            }
            else
            {
                Student* temp = students[groupQueue].front();
                temp->out = time;
                gr[groupQueue]--;
                students[groupQueue].pop();
                if (gr[groupQueue] == 0)
                {
                    b = true;
                }
                s.push_back(temp);
            }

        }
        time++;
    }
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        cout << (*i)->name << " " << (*i)->in << " " << (*i)->out << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}

