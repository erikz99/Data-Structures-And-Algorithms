#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;

    Node(int data = 0, Node * left = NULL, Node * right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* insert(Node* root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* minValueNode(Node* root)
{
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->left, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int search(Node* node, int key)
{
    if (node != NULL)
    {
        int counter = 0;
        if (node->data == key)
        {
            return counter;
        }
        else if (node->data < key)
        {
            counter += 1 + search(node->right, key);
        }
        else {
            counter += 1 + search(node->left, key);
        }
        return counter;
    }
    return -100000000;
}

int n,k;
int adr[100010];

void solve() {
    cin >> n >> k;
    Node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        root = insert(root, key);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> adr[i];
    }
    for (int i = 0; i < k; i++)
    {
        int a = search(root, adr[i]);
        if (a>=0)
        {
            cout << a << "\n";
        }
        else 
        {
            cout << -1 << "\n";
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}