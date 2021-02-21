#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
    double data;
    Node *left;
    Node *right;
    int height;

    Node(double value)
    {
        this->data = value;
        this->height = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class AVLTree
{
private:
    Node *root;
    
    int getHeight(Node* root)
    {
        if (root == NULL) return 0;
        return root->height;
    }

    int getBalance(Node* root)
    {
        if (root==NULL) return 0;
        return getHeight(root->left) - getHeight(root->right);
    }
    
    Node* getMin(Node* root)
    {
        if (root->left)
        {
            return getMin(root->left);
        }
        return root;
    }
    
    Node* rightRotate(Node* root)
    {
        Node* leftNode = root->left;
        Node* leftRightNode = leftNode->right;

        root->left = leftRightNode;
        leftNode->right = root;

        root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
        leftNode->height = max(getHeight(leftNode->right), getHeight(leftNode->left)) + 1;

        return leftNode;
    }
    
    Node* leftRotate(Node* root)
    {
        Node* rightNode = root->right;
        Node* rightLeftNode = rightNode->left;

        root->right = rightLeftNode;
        rightNode->left = root;

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        rightNode->height = max(getHeight(rightNode->right), getHeight(rightNode->left)) + 1;

        return rightNode;
    }
    
    Node* add(Node* root, double value)
    {
        if (root == NULL) return new Node(value);
        
        if (root->data > value)
        {
            root->left = add(root->left, value);
        }
        else if (root->data < value)
        {
            root->right = add(root->right, value);
        }
        else
        {
            cout << value << " already added" << endl;
            return root;
        }

        root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

        int balance = getBalance(root);

        if (balance > 1)
        {
            if (value < root->left->data)
            {
                return rightRotate(root);
            }
            else if (value > root->left->data)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (balance < -1)
        {
            if (value > root->right->data)
            {
                return leftRotate(root);
            }
            else if (value < root->right->data)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        
        return root;
    }
    
    Node* remove(Node* root, double value)
    {
        if (root == NULL)
        {
            cout << value << " not found to remove" << endl;
            return NULL;
        }

        if (root->data < value)
        {
            root->right = remove(root->right, value);
        }
        else if (root->data > value)
        {
            root->left = remove(root->left, value);
        }
        else
        {
            if (!root->left)
            {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if (!root->right)
            {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                root->right = remove(root->right, root->data);
            }
        }

        if (root == NULL)
        {
            return root;
        }

        root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
        int balance = getBalance(root);

        if (balance > 1)
        {
            if (getBalance(root->left) >= 0)
            {
                return rightRotate(root);
            }
            else if (getBalance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (balance < -1)
        {
            if (getBalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            else if (getBalance(root->left) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        
        return root;
    }
    
    bool containsRecursive(Node *current, double value)
    {
        if (current == NULL)
        {
            return false;
        }

        if (current->data == value)
        {
            return true;
        }

        if (value < current->data)
        {
            return containsRecursive(current->left, value);
        }
        else
        {
            return containsRecursive(current->right, value);
        }
    }

    void printRecursive(Node *current)
    {
        if (current == NULL)
        {
            return;
        }

        printRecursive(current->left);
        cout << current->data << " ";
        printRecursive(current->right);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void add(double value)
    {
        root = add(root, value);
    }

    void remove(double value)
    {
        if (root == NULL)
        {
            cout << value << " not found to remove" << endl;
            return;
        }
        root = remove(root, value);
    }
    
    bool contains(double value)
    {
        if (root == NULL)
        {
            return false;
        }

        return containsRecursive(root, value);
    }

    void print()
    {
        if (root == NULL)
        {
            return;
        }

        printRecursive(root);
        cout << "\n";
    }
};

void solve() {
    AVLTree tree;
    string operation;
    double number;
    int N;

    cin >> N;
    cout << fixed;

    for (size_t i = 0; i < N; i++)
    {
        cin >> operation;
        if (operation != "print")
        {
            cin >> number;
        }

        if (operation == "add")
        {
            tree.add(number);
        }
        else if (operation == "remove")
        {
            tree.remove(number);
        }
        else if (operation == "contains")
        {
            if (tree.contains(number))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (operation == "print")
        {
            tree.print();
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}