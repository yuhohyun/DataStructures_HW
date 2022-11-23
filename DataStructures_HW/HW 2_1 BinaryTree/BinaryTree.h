#pragma once
#include "BinaryNode.h"

class BinaryTree
{
	BinaryNode* root;
public:

	BinaryTree() : root(NULL) { }
	~BinaryTree() { }

	void setRoot(BinaryNode* node) {
		root = node;
	}

	BinaryNode* getRoot() {
		return root;
	}

	bool isEmpty() {
		return root == NULL;
	}

	int	getCount() {
		return isEmpty() ? 0 : getCount(root);
	}

	int	getLeafCount() {
		return isEmpty() ? 0 : getLeafCount(root);
	}

	int	getHeight() {
		return isEmpty() ? 0 : getHeight(root);
	}

	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL) preorder(node->getLeft());
			if (node->getRight() != NULL) preorder(node->getRight());
		}
	}
	void preorder() {
		printf("preorder: ");
		preorder(root);
		printf("\n\n");
	}

	int getCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	int getLeafCount(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		if (node->isLeaf())
			return 1;
		else
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight(BinaryNode* node)
	{
		if (node == NULL)
			return 0;

		int	hLeft = getHeight(node->getLeft());
		int	hRight = getHeight(node->getRight());

		return
			(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}

public:
	//================================================================
	// 3.1) block�� ä��ÿ�.
	bool isEven(TNode* n) {	
		if ((n == NULL) ||  (n->left == NULL && n->right == NULL)) 
			return true;

		if (n->left == NULL || n->right == NULL)
			return false;

		return isEven(n->left) && isEven(n->right);
	}

	bool isFull() {
		bool ret = isEven(root);

		printf("��������Ʈ��%s\n\n", ret ? " �Դϴ�." : "�� �ƴմϴ�.");
		return ret;
	}

	//================================================================
	int checkLevel(TNode* p, TNode* n, int level)
	{
		// 3.2) block�� ä��ÿ�.
		int ll = 0, lr = 0;
		if (p == n) 		// ���� ��尡 ã���� �ϴ� Node�� ���ٸ�
			return level;
		
		// 3.2) block�� ä��ÿ�.
		if (p->left != NULL)
			ll = checkLevel(p->left, n, level + 1);
		
		if (p->right != NULL)
			lr = checkLevel(p->right, n, level + 1);

		if (ll > 0)
			return ll;

		else
			return lr;
	}


	int calcLevel(TNode* n) {
		int level = 0;
		if (root != NULL)
			level = checkLevel(root, n, 1);

		if (level > 0)
			printf("����� ������ %d.\n", level);
		else
			printf("Ʈ���� ���� ����Դϴ�.\n");

		return level;
	}


	//================================================================
	bool checkBalanced(TNode* p)
	{
		int lh, rh, dh;
		if (p == NULL)
			return true;

		lh = getHeight(p->left);
		rh = getHeight(p->right);
		dh = rh - lh;

		// 3.3) block�� ä��ÿ�.
		if (dh > 1 || dh < 0)
			return false;
		

		if (checkBalanced(p->left) == 0)
			return false;

		return checkBalanced(p->right);
	}

	bool isBalanced()
	{
		bool ret = checkBalanced(root);

		printf("%s ����Ʈ���Դϴ�.\n\n", ret ? "��������" : "�ұ�������");
		return ret;
	}

	//================================================================
	int calcPathLength(TNode* p, int level)
	{
		int llen = 0, rlen = 0;
		if (p == NULL)
			return 0;

		// 3.4) block�� ä��ÿ�.
		llen = calcPathLength(p->left, level + 1);
		rlen = calcPathLength(p->right, level + 1);

		return level + llen + rlen;

	}

	int pathLength()
	{
		int len = calcPathLength(root, 0);
		printf("��ü ����� ���̴� %d�Դϴ�.\n\n", len);
		return len;
	}
};


