#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
using namespace std;

int num = 0;

struct Node
{
    int data;
    Node* right, * left;

    Node(int data = 0)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node* root;

    Node* find(Node* node, int value)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (node->data > value)
        {
            return find(node->left, value);
        }

        else if (node->data < value)
        {
            return find(node->right, value);
        }

        return node;
    }

    Node* insert(Node* node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }

        if (node->data > value)
        {
            node->left = insert(node->left, value);
        }

        else if (node->data < value)
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    Node* remove (Node* node, int data)
    {
        if (node == NULL) return NULL;

        if (node->data > data)
        {
            node->left = remove(node->left, data);
        }
        else if (node->data < data)
        {
            node->right = remove(node->right, data);
        }
        else
        {
            if (node->right == NULL && node->left == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else
            {
                Node* temp = node->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    Node* findMax(Node* node)
    {
        if (node->right)
        {
            return findMax(node->right);
        }
        return node;
    }

    Node* findMin(Node* node)
    {
        if (node->left)
        {
            return findMin(node->left);
        }
        return node;
    }

    void printTraversals(Node* node)
    {
        queue <Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* temp = q.front();
            cout << temp->data << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            q.pop();
        }
    }

    int height(Node* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);
        
        return (max(left, right) + 1);
    }
    
    int subtree(Node* node) {
        if (node==nullptr) {
            return 0;
        }
        return 1+subtree(node->left) + subtree(node->right);
    }
    
    void removeKth(Node* node, int k) {
        int biggest = !node->right ? 0 : subtree(node->right);
        if (biggest>k-1) {
            removeKth(node->right,k);
        } 
        else if (biggest<k-1) {
            removeKth(node->left,k-biggest-1);
        }
        else {
            remove(root,node->data);
        }
    }

    public:

    BST()
    {
        this->root = NULL;
    }

    void insert(int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
        }
        else
        {
            root = insert(root, value);
        }
    }

    void remove(int value)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            root = remove(root, value);
        }
    }

    void printTraversals()
    {
        printTraversals(root);
    }

    int findMin()
    {
        return findMin(root)->data;
    }

    int findMax()
    {
        return findMax(root)->data;
    }

    bool find(int value)
    {
        return find(root, value);
    }

    int height()
    {
        return height(root);
    }
    
    void removeKth(int k){
        removeKth(root,k);
    } 
};

void solve() {
    int n,k;
    cin >> n >> k;
    BST tree;
    int el;
    for (int i=0; i<n; i++) {
        cin >> el;
        tree.insert(el);
    }
    tree.removeKth(k);
    tree.printTraversals();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
}