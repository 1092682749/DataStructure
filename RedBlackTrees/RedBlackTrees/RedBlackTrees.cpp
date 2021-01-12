
// 红黑树首先是一个排序二叉树

// RedBlackTrees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//

#include "pch.h"

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
		this->color = NodeColor::RED;

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
			// insertNode->parent = p->parent;
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
		
		if (insertNode->parent == nullptr) {
			insertNode->parent = p;
		}

	}

	void LL(Node *p)

	{
		Node *right = p->right;
		if (right == nullptr) return;
		Node *parent = p->parent;
		if (parent == nullptr) {
			
			p->parent = right;
			p->right = right->left;
			right->left = p;
			right->parent = nullptr;
			return;
		}
		if (parent->left == p) {
			p->right->parent = parent;
			parent->left = p->right;
			p->right = parent->left->left;
			p->parent = parent->left;
			parent->left->left = p;
			if (p->right != nullptr)
			p->right->parent = p;
		}
		else {
			p->right->parent = parent;
			parent->right = p->right;
			p->right = parent->right->left;
			p->parent = parent->right;
			parent->right->left = p;
			if (p->right != nullptr)
			p->right->parent = p;
		}
		


	}

	void RR(Node *p)

	{
		Node *left = p->left;
		if (left == nullptr) return;
		Node *parent = p->parent;
		if (parent == nullptr) {
			p->parent = left;
			p->right = left->right;
			left->right = p;
			left->parent = nullptr;
			return;
		}
		if (parent->left == p) {
			p->left->parent = parent;
			parent->left = p->left;
			p->left = parent->left->right;
			p->parent = parent->left;
			parent->left->right = p;
			if (p->left != nullptr)
			p->left->parent = p;
		}
		else {
			p->left->parent = parent;
			parent->right = p->left;
			p->left = parent->right->right;
			p->parent = parent->right;
			parent->right->right = p;
			if (p->left != nullptr)
			p->left->parent = p;
		}

	}

	void LR(Node *p)

	{
		LL(p);
		RR(p);

	}

	void RL(Node *p)

	{
		RR(p);
		LL(p);
	}



	int maxDepth(Node* root) {

		if (root == NULL) return 0;

		return 1 + max(maxDepth(root->left), maxDepth(root->right));

	}

};

int main()

{

	Tree t;
	Node root(100);
	t.insert(&root);
	t.insert(50);
	t.insert(150);
	t.insert(20);
	t.insert(75);
	t.insert(15);
	t.insert(25);
	t.insert(30);
	t.insert(65);
	t.insert(85);
	t.insert(22);
	Node n(1);
	Node *np = &n;
	Node *&pp = np;
	t.LL(root.left);
	t.RR(root.left->left);
	std::cout << "Hello World!\n";

}