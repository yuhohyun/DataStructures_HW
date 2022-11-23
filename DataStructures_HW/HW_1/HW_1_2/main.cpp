#include "CooklistDeque.h"
#include <iostream>

/*************************************************************************************
 * 		"CooklistDeque.h"를 이용하여 식당에서의 음식 주문표 알고리즘 구현하기.
 *
 *      - "CooklistDeque.h"에서 class 'CooklistDeque'는 basic0문제에서와 같은 원형 큐 클래스 'CircularQueue'
 * 			를 상속하고 있으며, 매개변수로는 기존 'data'가 아닌, 구조체 'TableFood'를 매개변수로 취하고 있다.
 * 			-> 구조체 'TableFood'은 "TableFood.h"에 정의되어 있다.
 *
 * 		- 처음 front와 rear의 index는 0으로 초기화되어 있다.
 *
 * 		- basic_1_explain.png에 있는 그림의 알고리즘을 구현하고자 한다. block안을 채워 나머지 source 코드를 완성하여라.

 * 		- basic_1_explain.png에 대한 설명:
 * 			->  어떤 4개의 table이 있는 식당에서 Deque를 활용하여, basic_1_explain.png와 같이 total time 조리 주문표를 만들고자 한다.
 *
 * 			[1]	totaltime_list : 각 음식이 조리가 완료되는 시간으로 time update해주는 함수.
 *
 *			각 문제에서 원하는 구현이 되도록 모든 block을 채워 넣어라.
*************************************************************************************/


/**
  * @brief:     각 음식이 조리가 완료되는 시간으로 time update해주는 함수.
  * @param:  	list: input 초기 cook list
  * @retval:    total time cook list
  */
CooklistDeque totaltime_list(CooklistDeque list)
{
	int sum = 0;

	// 2.1) front와 rear를 초기화 시키시오.	( hint: CooklistDeque.h )
	int front = (list.front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	/* block 1 */
	int rear = (list.rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	/* 				block 2				*/

	// 2.2) 리스트에서의 조리되어야 하는 각 음식들의 현재 time들을 각 음식들의 조리가 완료되는 total time으로 업데이트 하여라. 
	for (int i = front; i <= rear; i++) {
		sum += list.data[i].totaltime;	/* 	block 3	*/
		list.data[i].totaltime = sum;
	}

	return list;
}


int main()
{
	//처음 주문들을 받아오는 변수: cooklist
	//cooklist들을 가지고 totaltime으로 cooklist의 시간 변수값들을 업데이트시킨 주문리스트: totaltime_cooklist
	CooklistDeque cooklist, totaltime_cooklist;

	// 2.3) basic_1_explain.png 를 보고, 리스트에서의 조리되어야 하는 각 음식들의 주문들을 cooklist에 addRear하라.
	// hint) 	cooklist.addRear(TableFood{ 1, "food_a", 8});
	cooklist.addRear(TableFood{ 1,"food_a", 8 });
	cooklist.addRear(TableFood{ 1,"food_b", 12 });
	cooklist.addRear(TableFood{ 3,"food_a", 8 });
	cooklist.addRear(TableFood{ 2,"food_c", 9 });
	cooklist.addRear(TableFood{ 3,"food_c", 9 });
	cooklist.addRear(TableFood{ 4,"food_a", 8 });
	cooklist.addRear(TableFood{ 4,"food_b", 12 });

	 // 2.4) 각 음식들의 조리되는 데 걸리는 시간 즉, totaltime으로 업데이트된 조리 리스트를 출력하여라. 
	 // hint) 함수활용. 
	cooklist = CooklistDeque(cooklist);
	cooklist.display();

	totaltime_cooklist = totaltime_list(cooklist);
	totaltime_cooklist.display();
	
	return 0;
}