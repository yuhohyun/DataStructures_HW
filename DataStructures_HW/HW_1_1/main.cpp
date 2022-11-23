#include "CircularQueue.h"
#include <iostream>

/*************************************************************************************
 * 		기본 "CircularQueue.h"를 이용하여 원하는 데이터구조 완성하기
 *      - "CircularQueue.h"헤더 파일의 'CircularQueue'은 원형큐 구조를 나타내는 클래스이다.
 * 		- 처음 front와 rear의 index는 0으로 초기화되어 있다.
 * 		- 아래와 같이 처음 선언된 원형 큐에 대해서 연속으로 1~9까지의 수를 enqueue한다.
 * 		- basic_0_explain.png에 있는 데이터 구조를 만들고자 한다. block안을 채워 나머지 source 코드를 완성하여라.
 * 		- 1)은 아래의 block을 채우는 것이며, 2) "CircularQueue.h"에 있는 'MAX_QUEUE_SIZE'의 수를 정해주는 것이다.
*************************************************************************************/

int main()
{
	CircularQueue que;
	for (int i = 1; i < 10; i++)
		que.enqueue(i);

	que.display();

	// block 1은 CircularQueue.h에 있음!

	// 1) 원형큐가 basic_0_explain.png에서 보여지는 데이터들을 갖도록 하시오.	
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