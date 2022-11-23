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
	// 3.1) block을 채우시오.
	bool isEven(TNode* n) {	
		if ((n == NULL) ||  (n->left == NULL && n->right == NULL)) 
			return true;

		if (n->left == NULL || n->right == NULL)
			return false;

		return isEven(n->left) && isEven(n->right);
	}

	bool isFull() {
		bool ret = isEven(root);

		printf("완전이진트리%s\n\n", ret ? " 입니다." : "가 아닙니다.");
		return ret;
	}

	//================================================================
	int checkLevel(TNode* p, TNode* n, int level)
	{
		// 3.2) block을 채우시오.
		int ll = 0, lr = 0;
		if (p == n) 		// 현재 노드가 찾고자 하는 Node와 같다면
			return level;
		
		// 3.2) block을 채우시오.
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
			printf("노드의 레벨은 %d.\n", level);
		else
			printf("트리에 없는 노드입니다.\n");

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

		// 3.3) block을 채우시오.
		if (dh > 1 || dh < 0)
			return false;
		

		if (checkBalanced(p->left) == 0)
			return false;

		return checkBalanced(p->right);
	}

	bool isBalanced()
	{
		bool ret = checkBalanced(root);

		printf("%s 이진트리입니다.\n\n", ret ? "균형잡힌" : "불균형적인");
		return ret;
	}

	//================================================================
	int calcPathLength(TNode* p, int level)
	{
		int llen = 0, rlen = 0;
		if (p == NULL)
			return 0;

		// 3.4) block을 채우시오.
		llen = calcPathLength(p->left, level + 1);
		rlen = calcPathLength(p->right, level + 1);

		return level + llen + rlen;

	}

	int pathLength()
	{
		int len = calcPathLength(root, 0);
		printf("전체 경로의 길이는 %d입니다.\n\n", len);
		return len;
	}
};


