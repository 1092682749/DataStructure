
// 红黑树首先是一个排序二叉树

// RedBlackTrees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//



#include <iostream>

int max(int a, int b)

{

	return a > b ? a : b;

}

enum NodeColor {

	RED = 0, BLACK = 1

};

class Node {

private:

	static const int RED = 0;

	static const int BLACK = 1;

public:

	Node(int data)

	{

		this->data = data;

	}

	Node *parent;

	Node *left;

	Node *right;

	NodeColor color;

	int data;

};



class Tree

{

private:

	Node *root = nullptr;

public:

	void insert(int data)

	{

		insert(new Node(data));

	}

	void insert(Node *node)

	{

		if (root == nullptr)

		{

			this->root = node;

			this->root->color = BLACK;

		}

		else {

			visit(root, node);

		}

	}

	void visit(Node *&p, Node *&insertNode)

	{

		if (p == nullptr)

		{

			p = insertNode;

			return;

		}

		if (p->data > insertNode->data)

		{

			visit(p->left, insertNode);

			// p->left = insertNode;

		}

		else

		{

			visit(p->right, insertNode);

			// p->right = insertNode;

		}

	}

	void LL()

	{



	}

	void RR()

	{



	}

	void LR()

	{



	}

	void RL()

	{



	}



	int maxDepth(Node* root) {

		if (root == NULL) return 0;

		return 1 + max(maxDepth(root->left), maxDepth(root->right));

	}

};

int main()

{

	Tree t;

	t.insert(1);

	t.insert(0);

	t.insert(2);



	std::cout << "Hello World!\n";

}