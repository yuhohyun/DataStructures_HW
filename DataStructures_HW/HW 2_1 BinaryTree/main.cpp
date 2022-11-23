#include "BinaryTree.h"
typedef BinaryTree	BinTree;


/*************************************************************************************
 * 		Adavanced. 주어진 트리에 대한 다양한 함수 구현.
 *      - 아래에서 보이는 'tree'를 각 문제들에서 원하는 데이터 트리 구조로 만들고자 한다.
 * 			class BinaryTree는 'BinaryTree.h'안에 선언되어 있다.
 * 	        class TNode는 'BinaryNode.h'안에 선언되어 있다.
 *			각 문제에서 원하는 구현이 되도록 모든 block을 채워 넣어라.
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

	// tree.getCount(), tree.getLeafCount(), tree.getHeight()는 basc2에 있는 함수들과 동일합니다.
	printf("노드 개수 = %d\n", tree.getCount());
	printf("단말 개수 = %d\n", tree.getLeafCount());
	printf("트리 높이 = %d\n", tree.getHeight());

	tree.preorder();
	//-> preorder:  [A]  [B]  [C]  [D]  [E]  [F] 

	/* [3.1] 이진트리가 완전 이진트리인지를 검사하는 다음 연산을 구현하라.
	 * 위에서 주어진 트리는 완전 이진트리가 아니므로 'false'가 반환되어야 한다.
	*/
	printf("(1)\n");
	tree.isFull();


	/* [3.2] 임의의 node의 레벨에 구하는 연산을 구현하라.
	 * 만약 Node가 트리 안에 있지 않으면 0을 반환하라. 위 이진트리에 대한 레벨은 아래 출력을 참고하라.
	*/
	printf("(2)\n");
	tree.calcLevel(a);
	tree.calcLevel(b);
	tree.calcLevel(c);
	tree.calcLevel(d);
	tree.calcLevel(e);
	tree.calcLevel(f);
	printf("\n");
	/* -> 출력:
	노드의 레벨은 1.
	노드의 레벨은 2.
	노드의 레벨은 3.
	노드의 레벨은 3.
	노드의 레벨은 2.
	노드의 레벨은 3.
	*/


	/* [3.3] 이진트리의 모든 노드에서 왼쪽 서브트리와 오른쪽 서브트리의 높이의 차이가 2보다
	 * 작으면 이 트리를 "균형이 잡혀 있다(balanced)"라고 한다. 현재 이진트리가 균형 잡혀 있는지를
	 * 검사하는 다음 연산을 구현하라.
	 *
	 * 위의 트리는 높이의 차이가 1 이하로 균형 잡혀 있다.
	*/
	printf("(3)\n");
	tree.isBalanced();
	/* -> 출력:
	균형잡힌 이진트리입니다.
	*/



	/* [3.4] 이진트리의 경로의 길이(path length)를 루트에서부터 모든 자식 노드까지의 경로의 길이의
	 * 합이라고 하자. 경로의 길이를 구하는 다음 연산을 구현하라.
	 *
	 * 위의 트리에서 경로의 길이는 0+1+1+2+2+2=8이다.
	*/
	printf("(4)\n");
	tree.pathLength();
	/* -> 출력:
	전체 경로의 길이는 8입니다.
	*/


	return 0;
}