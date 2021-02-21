#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
using namespace std;

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

	Node* remove(Node* node, int data)
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

	void leafSum(Node* node, int& sum)
	{
		if (node == NULL)
		{
			return;
		}

		if (!node->right && !node->left)
		{
			sum += node->data;
		}

		leafSum(node->left,sum);
		leafSum(node->right,sum);
	}

	void kthLargestUtil(Node* node, int k, int& c)
	{
		if (node == NULL || c >= k)
			return;

		kthLargestUtil(node->right, k, c);

		c++;

		if (c == k)
		{
			cout << "K'th largest element is "
				<< node->data << endl;
			return;
		}

		kthLargestUtil(node->left, k, c);
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

	int sumOddLevels(Node* node, bool is = true)
	{
		if (node == NULL)
		{
			return 0;
		}
		int sum = 0;
		if (is)
		{
			sum += node->data;
		}

		sum += sumOddLevels(node->left, !is);
		sum += sumOddLevels(node->right, !is);
		return sum;
	}

	int sumEvenLevels(Node* node, bool is = false)
	{
		if (node == NULL)
		{
			return 0;
		}

		int sum = 0;
		if (is)
		{
			sum += node->data;
		}

		sum += sumOddLevels(node->left, !is);
		sum += sumOddLevels(node->right, !is);
		return sum;
	}

	void printSpiral( Node* root)
	{
		if (root == NULL)
			return; 
		stack <Node*> s1;
		stack <Node*> s2;
		s1.push(root);
		
		while (!s1.empty() || !s2.empty())
		{
			while (!s1.empty())
			{
				Node* current = s1.top();
				cout << current->data << " ";
				s1.pop();
				if (current->right!=NULL)
				{
					s2.push(current->right);
				}
				if (current->left!=NULL)
				{
					s2.push(current->left);
				}
			}

			while (!s2.empty())
			{
				Node* current = s2.top();
				cout << current->data << " ";
				s2.pop();
				if (current->left != NULL)
				{
					s1.push(current->left);
				}
				if (current->right != NULL)
				{
					s1.push(current->right);
				}
			}
		}
	}


	void printInOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}

		printInOrder(node->left);
		cout << node->data << " ";
		printInOrder(node->right);
	}

	void printPostOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}

		printInOrder(node->left);
		printInOrder(node->right);
		cout << node->data << " ";
	}

	int sumOfNodes(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		return (node->data + sumOfNodes(node->right) + sumOfNodes(node->left));
	}

	void printPreOrder(Node* node)
	{
		if (node == NULL)
		{
			return;
		}

		cout << node->data << " ";
		printPreOrder(node->left);
		printPreOrder(node->right);
	}

	bool isBalanced(Node* node)
	{
		if (node == NULL)
		{
			return 1;
		}

		int right = height(node->right);
		int left = height(node->left);

		if (fabs(right - left) < 2 && isBalanced(node->right) && isBalanced(node->left))
		{
			return 1;
		}
		return 0;
	}

	Node* build(int* arr, int leftInd, int rightInd)
	{
		if (leftInd > rightInd)
		{
			return NULL;
		}

		int mid = (rightInd + leftInd) / 2;
		Node* node = new Node(arr[mid]);

		node->left = build(arr, leftInd, mid - 1);
		node->right = build(arr, mid + 1, rightInd);

		return node;
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

	void buildBST(int* arr, int leftInd, int rightInd)
	{
		root = build(arr, leftInd, rightInd);
	}

	void printPreOrder()
	{
		printPreOrder(root);
	}

	void printPostOrder()
	{
		printPostOrder(root);
	}

	void printInOrder()
	{
		printInOrder(root);
	}

	void printTraversals()
	{
		printTraversals(root);
	}

	void printSpiral()
	{
		printSpiral(root);
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

	void leafSum(int &sum)
	{
		leafSum(root, sum);
	}

	int height()
	{
		return height(root);
	}

	int sumOfNodes()
	{
		return sumOfNodes(root);
	}

	int sumOddLevels()
	{
		return sumOddLevels(root);
	}

	int sumEvenLevels()
	{
		return sumEvenLevels(root);
	}

	bool isBalanced()
	{
		return isBalanced(root);
	}

	
};

int main()
{
	BST tree;
	tree.insert(8);
	tree.insert(3);
	tree.insert(10);
	tree.insert(1);
	tree.insert(7);
	tree.insert(9);
	tree.insert(13);
	tree.insert(16);
	tree.remove(1);
	tree.printTraversals();
}