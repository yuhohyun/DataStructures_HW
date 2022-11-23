#include "CooklistDeque.h"
#include <iostream>

/*************************************************************************************
 * 		"CooklistDeque.h"�� �̿��Ͽ� �Ĵ翡���� ���� �ֹ�ǥ �˰��� �����ϱ�.
 *
 *      - "CooklistDeque.h"���� class 'CooklistDeque'�� basic0���������� ���� ���� ť Ŭ���� 'CircularQueue'
 * 			�� ����ϰ� ������, �Ű������δ� ���� 'data'�� �ƴ�, ����ü 'TableFood'�� �Ű������� ���ϰ� �ִ�.
 * 			-> ����ü 'TableFood'�� "TableFood.h"�� ���ǵǾ� �ִ�.
 *
 * 		- ó�� front�� rear�� index�� 0���� �ʱ�ȭ�Ǿ� �ִ�.
 *
 * 		- basic_1_explain.png�� �ִ� �׸��� �˰����� �����ϰ��� �Ѵ�. block���� ä�� ������ source �ڵ带 �ϼ��Ͽ���.

 * 		- basic_1_explain.png�� ���� ����:
 * 			->  � 4���� table�� �ִ� �Ĵ翡�� Deque�� Ȱ���Ͽ�, basic_1_explain.png�� ���� total time ���� �ֹ�ǥ�� ������� �Ѵ�.
 *
 * 			[1]	totaltime_list : �� ������ ������ �Ϸ�Ǵ� �ð����� time update���ִ� �Լ�.
 *
 *			�� �������� ���ϴ� ������ �ǵ��� ��� block�� ä�� �־��.
*************************************************************************************/


/**
  * @brief:     �� ������ ������ �Ϸ�Ǵ� �ð����� time update���ִ� �Լ�.
  * @param:  	list: input �ʱ� cook list
  * @retval:    total time cook list
  */
CooklistDeque totaltime_list(CooklistDeque list)
{
	int sum = 0;

	// 2.1) front�� rear�� �ʱ�ȭ ��Ű�ÿ�.	( hint: CooklistDeque.h )
	int front = (list.front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	/* block 1 */
	int rear = (list.rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	/* 				block 2				*/

	// 2.2) ����Ʈ������ �����Ǿ�� �ϴ� �� ���ĵ��� ���� time���� �� ���ĵ��� ������ �Ϸ�Ǵ� total time���� ������Ʈ �Ͽ���. 
	for (int i = front; i <= rear; i++) {
		sum += list.data[i].totaltime;	/* 	block 3	*/
		list.data[i].totaltime = sum;
	}

	return list;
}


int main()
{
	//ó�� �ֹ����� �޾ƿ��� ����: cooklist
	//cooklist���� ������ totaltime���� cooklist�� �ð� ���������� ������Ʈ��Ų �ֹ�����Ʈ: totaltime_cooklist
	CooklistDeque cooklist, totaltime_cooklist;

	// 2.3) basic_1_explain.png �� ����, ����Ʈ������ �����Ǿ�� �ϴ� �� ���ĵ��� �ֹ����� cooklist�� addRear�϶�.
	// hint) 	cooklist.addRear(TableFood{ 1, "food_a", 8});
	cooklist.addRear(TableFood{ 1,"food_a", 8 });
	cooklist.addRear(TableFood{ 1,"food_b", 12 });
	cooklist.addRear(TableFood{ 3,"food_a", 8 });
	cooklist.addRear(TableFood{ 2,"food_c", 9 });
	cooklist.addRear(TableFood{ 3,"food_c", 9 });
	cooklist.addRear(TableFood{ 4,"food_a", 8 });
	cooklist.addRear(TableFood{ 4,"food_b", 12 });

	 // 2.4) �� ���ĵ��� �����Ǵ� �� �ɸ��� �ð� ��, totaltime���� ������Ʈ�� ���� ����Ʈ�� ����Ͽ���. 
	 // hint) �Լ�Ȱ��. 
	cooklist = CooklistDeque(cooklist);
	cooklist.display();

	totaltime_cooklist = totaltime_list(cooklist);
	totaltime_cooklist.display();
	
	return 0;
}