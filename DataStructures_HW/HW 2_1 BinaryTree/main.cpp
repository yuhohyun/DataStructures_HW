#include "BinaryTree.h"
typedef BinaryTree	BinTree;


/*************************************************************************************
 * 		Adavanced. �־��� Ʈ���� ���� �پ��� �Լ� ����.
 *      - �Ʒ����� ���̴� 'tree'�� �� �����鿡�� ���ϴ� ������ Ʈ�� ������ ������� �Ѵ�.
 * 			class BinaryTree�� 'BinaryTree.h'�ȿ� ����Ǿ� �ִ�.
 * 	        class TNode�� 'BinaryNode.h'�ȿ� ����Ǿ� �ִ�.
 *			�� �������� ���ϴ� ������ �ǵ��� ��� block�� ä�� �־��.
*************************************************************************************/

int main()
{
	BinTree tree;
	TNode* a, * b, * c, * d, * e, * f;

	//           A
	//       B       E
	//     C   D        F
	c = new TNode('C', NULL, NULL);
	d = new TNode('D', NULL, NULL);
	f = new TNode('F', NULL, NULL);
	b = new TNode('B', c, d);
	e = new TNode('E', NULL, f);
	a = new TNode('A', b, e);

	tree.setRoot(a);

	// tree.getCount(), tree.getLeafCount(), tree.getHeight()�� basc2�� �ִ� �Լ���� �����մϴ�.
	printf("��� ���� = %d\n", tree.getCount());
	printf("�ܸ� ���� = %d\n", tree.getLeafCount());
	printf("Ʈ�� ���� = %d\n", tree.getHeight());

	tree.preorder();
	//-> preorder:  [A]  [B]  [C]  [D]  [E]  [F] 

	/* [3.1] ����Ʈ���� ���� ����Ʈ�������� �˻��ϴ� ���� ������ �����϶�.
	 * ������ �־��� Ʈ���� ���� ����Ʈ���� �ƴϹǷ� 'false'�� ��ȯ�Ǿ�� �Ѵ�.
	*/
	printf("(1)\n");
	tree.isFull();


	/* [3.2] ������ node�� ������ ���ϴ� ������ �����϶�.
	 * ���� Node�� Ʈ�� �ȿ� ���� ������ 0�� ��ȯ�϶�. �� ����Ʈ���� ���� ������ �Ʒ� ����� �����϶�.
	*/
	printf("(2)\n");
	tree.calcLevel(a);
	tree.calcLevel(b);
	tree.calcLevel(c);
	tree.calcLevel(d);
	tree.calcLevel(e);
	tree.calcLevel(f);
	printf("\n");
	/* -> ���:
	����� ������ 1.
	����� ������ 2.
	����� ������ 3.
	����� ������ 3.
	����� ������ 2.
	����� ������ 3.
	*/


	/* [3.3] ����Ʈ���� ��� ��忡�� ���� ����Ʈ���� ������ ����Ʈ���� ������ ���̰� 2����
	 * ������ �� Ʈ���� "������ ���� �ִ�(balanced)"��� �Ѵ�. ���� ����Ʈ���� ���� ���� �ִ�����
	 * �˻��ϴ� ���� ������ �����϶�.
	 *
	 * ���� Ʈ���� ������ ���̰� 1 ���Ϸ� ���� ���� �ִ�.
	*/
	printf("(3)\n");
	tree.isBalanced();
	/* -> ���:
	�������� ����Ʈ���Դϴ�.
	*/



	/* [3.4] ����Ʈ���� ����� ����(path length)�� ��Ʈ�������� ��� �ڽ� �������� ����� ������
	 * ���̶�� ����. ����� ���̸� ���ϴ� ���� ������ �����϶�.
	 *
	 * ���� Ʈ������ ����� ���̴� 0+1+1+2+2+2=8�̴�.
	*/
	printf("(4)\n");
	tree.pathLength();
	/* -> ���:
	��ü ����� ���̴� 8�Դϴ�.
	*/


	return 0;
}