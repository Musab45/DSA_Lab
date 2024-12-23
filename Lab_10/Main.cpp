//Graphs
#include<iostream>
#include<queue>

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int key)
	{
		data = key;
		left = right = nullptr;
	}
};

//Breadth_First Search
void BFS(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();
		std::cout << node->data << " ";
		if (node->left != nullptr)
		{
			q.push(node->left);
		}
		if (node->right != nullptr)
		{
			q.push(node->right);
		}
	}
}

void main()
{
	/*
	*  	       1
	*        /   \
	*       /     \ 
	*      /       \
	*      2        3
	*    /   \     /  \
	*   /     \   /    \
	*  4       5  6     7
	* 
	*/
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	BFS(root);
}