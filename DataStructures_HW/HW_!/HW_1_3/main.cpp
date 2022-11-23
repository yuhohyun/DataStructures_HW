#include "CooklistDeque.h"
#include <iostream>

/*************************************************************************************
 * 		"CooklistDeque.h"를 이용하여 식당에서의 음식 주문표 알고리즘
구현하기. ( basic 1과 이어지는 문제입니다. )
 *
 *      - "CooklistDeque.h"에서 class 'CooklistDeque'는 basic0문제에서와 같은
원형 큐 클래스 'CircularQueue'
 * 			를 상속하고 있으며, 매개변수로는 기존 'data'가 아닌,
구조체 'TableFood'를 매개변수로 취하고 있다.
 * 			-> 구조체 'TableFood'은 "TableFood.h"에 정의되어 있다.
 *
 * 		- 처음 front와 rear의 index는 0으로 초기화되어 있다.
 *
 * 		- advanced_explain.png에 있는 그림의 알고리즘을 구현하고자 한다.
block안을 채워 나머지 source 코드를 완성하여라.

 * 		- advanced_explain.png에 대한 설명:
 * 			->  어떤 4개의 table이 있는 식당에서 Deque를 활용하여,
basic1와 같이 total time 조리 주문표를 만들고자 한다.
 * 				또한, 추가적으로, 특정 시간 이후때의 가장 최근
조리 완료된 음식과 이제 조리완료가 되어야할 음식을 알 수 있도록 하고자 한다.
 *
 * 			[1]	프로젝트에서의 '들어오는 조리 주문',
'totaltime_list 함수' 및 헤더파일들은 basic1에서와 동일하다.
 * 			[2] predict_food 함수 : 특정시간이 되었을 때의,
업데이트된 음식 리스트를 구하는 함수.
 *
 *			각 문제에서 원하는 구현이 되도록 모든 block을 채워
넣어라.
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
    int front = (list.front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    /* block 1 */
    int rear = (list.rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	/* 				block 2				*/

     // 2.2) 리스트에서의 조리되어야 하는 각 음식들의 현재 time들을 각 음식들의
  // 조리가 완료되는 total time으로 업데이트 하여라.
    for (int i = front; i <= rear; i++) {
        sum += list.data[i].totaltime;	/* 	block 3	*/
        list.data[i].totaltime = sum;
    }

	return list;
}


/**
 * @brief:     특정시간이 되었을 때의, 업데이트된 음식 리스트를 구하는 함수.
 * @param:  	list: input total time cook list,
 * 			dst : time 후의 total time cook list,
 * 			time : 특정 시간
 * @retval:   	temp_cooked: 특정 시간 이후때의 가장 최근 조리 완료된 음식
 */
TableFood predict_food(CooklistDeque list, CooklistDeque& dst, int time) {
    // 3.1) front와 rear를 초기화 시키시오.
    int front = (list.front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;   /* 				block 5  */;
    int rear = (list.rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; /* 				block 6  */;

    TableFood temp_cooked = {list.data[rear].tablenumber, 
        list.data[rear].foodname, list.data[rear].totaltime}; // 반환을 위한 변수.

    while (time--) // 일분이 경과하였을 때~
    {
        // 3.2) 음식이 다 조리되었다면~
        if (list.data[rear].totaltime == 0) {
            printf("조리될 음식이 없음.");
            return TableFood{ 0, "nothing", 0 };
        }

        // 음식이 다 조리되지 않았다면~
        else {
            // 3.3) 남아있는 음식 주문 리스트에 totaltime들을 1씩 뺀다.
            for (int i = front; i <= rear; i++) {
                list.data[i].totaltime = list.data[i].totaltime - 1;

                if (list.data[i].totaltime == 0)   // 3.4) 지금 조리되고 있는 음식이
                                                             // 조리완료 되었다면,
                    temp_cooked = list.deleteFront();    /* 	 block 11	  */
               // 3.5) 방금 조리된 음식을 temp_cooked에 담는다.
            }
        }

        dst = list;
    }

    return temp_cooked;
}

int main() {
    // 처음 주문들을 받아오는 변수: cooklist
    // cooklist들을 가지고 totaltime으로 cooklist의 시간 변수값들을 업데이트시킨
    // 주문리스트: totaltime_cooklist 임시 주문 리스트: temp
    CooklistDeque cooklist, totaltime_cooklist, temp;
    TableFood predicted;

    // 2.3) 리스트에서의 조리되어야 하는 각 음식들의 주문들을 cooklist에
    // addRear하라. hint) 	cooklist.addRear(TableFood{ 1, "food_a", 8});
    cooklist.addRear(TableFood{ 1,"food_a", 8 });
    cooklist.addRear(TableFood{ 1,"food_b", 12 });
    cooklist.addRear(TableFood{ 3,"food_a", 8 });
    cooklist.addRear(TableFood{ 2,"food_c", 9 });
    cooklist.addRear(TableFood{ 3,"food_c", 9 });
    cooklist.addRear(TableFood{ 4,"food_a", 8 });
    cooklist.addRear(TableFood{ 4,"food_b", 12 });

     // 2.4) 각 음식들의 조리되는 데 걸리는 시간 즉, totaltime으로 업데이트된 조리
     // 리스트 출력하여라.
    cooklist = CooklistDeque(cooklist);
    cooklist.display();

    totaltime_cooklist = totaltime_list(cooklist);
    totaltime_cooklist.display();/* 	 block 13	*/;

    predicted = predict_food(totaltime_cooklist, temp, 28);

    // 3.6) 28분뒤 시점을 기준으로 가장 최근에 조리 완료된 음식의 정보를
    // 출력하여라.
    printf("pred: \n");
    printf("tablenumber: [%2d] / foodname: [%s] / totaltime: [%2d] \n",
          predicted.tablenumber  /* 	 block  14 */
        , predicted.foodname    /* 	 block 15	  */
        , predicted.totaltime   /* 	 block 16	  */
        );

    // 3.7) 28분뒤 시점을 기준으로 지금 조리되고 있는 음식의 정보를 출력하여라.
    printf("cooking now : \n");
    printf("tablenumber: [%2d] / foodname: [%s] / totaltime: [%2d] \n",
          temp.getFront().tablenumber     /* block 17 */
        , temp.getFront().foodname  /* 	 block 18	  */
        , temp.getFront().totaltime  /* 	 block 19 	  */
        );
    return 0;
}
