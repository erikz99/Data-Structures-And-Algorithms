#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
    int rank;

    Node(int value)
    {
        this->data = value;
        this->height = 0;
        this->rank = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class AVLTree
{
private:
    Node* root;

    int getRank(Node* root)
    {
        if (root == NULL) return 0;
        return root->rank;
    }

    int getHeight(Node* root)
    {
        if (root == NULL) return 0;
        return root->height;
    }

    int getBalance(Node* root)
    {
        if (root == NULL) return 0;
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

    void computeRank(Node* root, int& i)
    {
        if (root == NULL)
        {
            return;
        }

        computeRank(root->left, i);
        root->rank = i;
        i++;
        computeRank(root->right, i);

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

    Node* add(Node* root, int value)
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

    Node* remove(Node* root, int value)
    {
        if (root == NULL)
        {
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
                Node* temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
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

    void printRecursive(Node* current)
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

    void add(int value)
    {
        root = add(root, value);
    }

    void remove(int value)
    {
        if (root == NULL)
        {
            cout << value << " not found to remove" << endl;
            return;
        }
        root = remove(root, value);
    }

    void computeRank()
    {
        if (root == NULL)
        {
            return;
        }
        int i = 0;
        computeRank(root, i);
    }

    int getRank()
    {
        return getRank(root);
    }

    void print()
    {
        if (root == NULL)
        {
            return;
        }

        printRecursive(root);
        cout << endl;
    }
};

int main()
{
    AVLTree avlTree;
}