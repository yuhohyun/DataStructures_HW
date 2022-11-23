#include "CircularQueue.h"
#include <iostream>

/*************************************************************************************
 * 		�⺻ "CircularQueue.h"�� �̿��Ͽ� ���ϴ� �����ͱ��� �ϼ��ϱ�
 *      - "CircularQueue.h"��� ������ 'CircularQueue'�� ����ť ������ ��Ÿ���� Ŭ�����̴�.
 * 		- ó�� front�� rear�� index�� 0���� �ʱ�ȭ�Ǿ� �ִ�.
 * 		- �Ʒ��� ���� ó�� ����� ���� ť�� ���ؼ� �������� 1~9������ ���� enqueue�Ѵ�.
 * 		- basic_0_explain.png�� �ִ� ������ ������ ������� �Ѵ�. block���� ä�� ������ source �ڵ带 �ϼ��Ͽ���.
 * 		- 1)�� �Ʒ��� block�� ä��� ���̸�, 2) "CircularQueue.h"�� �ִ� 'MAX_QUEUE_SIZE'�� ���� �����ִ� ���̴�.
*************************************************************************************/

int main()
{
	CircularQueue que;
	for (int i = 1; i < 10; i++)
		que.enqueue(i);

	que.display();

	// block 1�� CircularQueue.h�� ����!

	// 1) ����ť�� basic_0_explain.png���� �������� �����͵��� ������ �Ͻÿ�.	
	/**************************************
	 *
	 *
	 *               block 2
	 *
	 *
	 *
	 ***************************************/

	for (int i = 10; i < 13; i++) {
		que.enqueue(i);
	}

	que.dequeue();
	que.dequeue();

	for (int i = 13; i < 15; i++) {
		que.enqueue(i);
	}

	que.display();

	return 0;
}