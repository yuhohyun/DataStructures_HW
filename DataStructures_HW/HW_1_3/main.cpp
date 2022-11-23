#include "CooklistDeque.h"
#include <iostream>

/*************************************************************************************
 * 		"CooklistDeque.h"�� �̿��Ͽ� �Ĵ翡���� ���� �ֹ�ǥ �˰���
�����ϱ�. ( basic 1�� �̾����� �����Դϴ�. )
 *
 *      - "CooklistDeque.h"���� class 'CooklistDeque'�� basic0���������� ����
���� ť Ŭ���� 'CircularQueue'
 * 			�� ����ϰ� ������, �Ű������δ� ���� 'data'�� �ƴ�,
����ü 'TableFood'�� �Ű������� ���ϰ� �ִ�.
 * 			-> ����ü 'TableFood'�� "TableFood.h"�� ���ǵǾ� �ִ�.
 *
 * 		- ó�� front�� rear�� index�� 0���� �ʱ�ȭ�Ǿ� �ִ�.
 *
 * 		- advanced_explain.png�� �ִ� �׸��� �˰����� �����ϰ��� �Ѵ�.
block���� ä�� ������ source �ڵ带 �ϼ��Ͽ���.

 * 		- advanced_explain.png�� ���� ����:
 * 			->  � 4���� table�� �ִ� �Ĵ翡�� Deque�� Ȱ���Ͽ�,
basic1�� ���� total time ���� �ֹ�ǥ�� ������� �Ѵ�.
 * 				����, �߰�������, Ư�� �ð� ���Ķ��� ���� �ֱ�
���� �Ϸ�� ���İ� ���� �����Ϸᰡ �Ǿ���� ������ �� �� �ֵ��� �ϰ��� �Ѵ�.
 *
 * 			[1]	������Ʈ������ '������ ���� �ֹ�',
'totaltime_list �Լ�' �� ������ϵ��� basic1������ �����ϴ�.
 * 			[2] predict_food �Լ� : Ư���ð��� �Ǿ��� ����,
������Ʈ�� ���� ����Ʈ�� ���ϴ� �Լ�.
 *
 *			�� �������� ���ϴ� ������ �ǵ��� ��� block�� ä��
�־��.
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
    int front = (list.front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;    /* block 1 */
    int rear = (list.rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;	/* 				block 2				*/

     // 2.2) ����Ʈ������ �����Ǿ�� �ϴ� �� ���ĵ��� ���� time���� �� ���ĵ���
  // ������ �Ϸ�Ǵ� total time���� ������Ʈ �Ͽ���.
    for (int i = front; i <= rear; i++) {
        sum += list.data[i].totaltime;	/* 	block 3	*/
        list.data[i].totaltime = sum;
    }

	return list;
}


/**
 * @brief:     Ư���ð��� �Ǿ��� ����, ������Ʈ�� ���� ����Ʈ�� ���ϴ� �Լ�.
 * @param:  	list: input total time cook list,
 * 			dst : time ���� total time cook list,
 * 			time : Ư�� �ð�
 * @retval:   	temp_cooked: Ư�� �ð� ���Ķ��� ���� �ֱ� ���� �Ϸ�� ����
 */
TableFood predict_food(CooklistDeque list, CooklistDeque& dst, int time) {
    // 3.1) front�� rear�� �ʱ�ȭ ��Ű�ÿ�.
    int front = (list.front + 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;   /* 				block 5  */;
    int rear = (list.rear + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; /* 				block 6  */;

    TableFood temp_cooked = {list.data[rear].tablenumber, 
        list.data[rear].foodname, list.data[rear].totaltime}; // ��ȯ�� ���� ����.

    while (time--) // �Ϻ��� ����Ͽ��� ��~
    {
        // 3.2) ������ �� �����Ǿ��ٸ�~
        if (list.data[rear].totaltime == 0) {
            printf("������ ������ ����.");
            return TableFood{ 0, "nothing", 0 };
        }

        // ������ �� �������� �ʾҴٸ�~
        else {
            // 3.3) �����ִ� ���� �ֹ� ����Ʈ�� totaltime���� 1�� ����.
            for (int i = front; i <= rear; i++) {
                list.data[i].totaltime = list.data[i].totaltime - 1;

                if (list.data[i].totaltime == 0)   // 3.4) ���� �����ǰ� �ִ� ������
                                                             // �����Ϸ� �Ǿ��ٸ�,
                    temp_cooked = list.deleteFront();    /* 	 block 11	  */
               // 3.5) ��� ������ ������ temp_cooked�� ��´�.
            }
        }

        dst = list;
    }

    return temp_cooked;
}

int main() {
    // ó�� �ֹ����� �޾ƿ��� ����: cooklist
    // cooklist���� ������ totaltime���� cooklist�� �ð� ���������� ������Ʈ��Ų
    // �ֹ�����Ʈ: totaltime_cooklist �ӽ� �ֹ� ����Ʈ: temp
    CooklistDeque cooklist, totaltime_cooklist, temp;
    TableFood predicted;

    // 2.3) ����Ʈ������ �����Ǿ�� �ϴ� �� ���ĵ��� �ֹ����� cooklist��
    // addRear�϶�. hint) 	cooklist.addRear(TableFood{ 1, "food_a", 8});
    cooklist.addRear(TableFood{ 1,"food_a", 8 });
    cooklist.addRear(TableFood{ 1,"food_b", 12 });
    cooklist.addRear(TableFood{ 3,"food_a", 8 });
    cooklist.addRear(TableFood{ 2,"food_c", 9 });
    cooklist.addRear(TableFood{ 3,"food_c", 9 });
    cooklist.addRear(TableFood{ 4,"food_a", 8 });
    cooklist.addRear(TableFood{ 4,"food_b", 12 });

     // 2.4) �� ���ĵ��� �����Ǵ� �� �ɸ��� �ð� ��, totaltime���� ������Ʈ�� ����
     // ����Ʈ ����Ͽ���.
    cooklist = CooklistDeque(cooklist);
    cooklist.display();

    totaltime_cooklist = totaltime_list(cooklist);
    totaltime_cooklist.display();/* 	 block 13	*/;

    predicted = predict_food(totaltime_cooklist, temp, 28);

    // 3.6) 28�е� ������ �������� ���� �ֱٿ� ���� �Ϸ�� ������ ������
    // ����Ͽ���.
    printf("pred: \n");
    printf("tablenumber: [%2d] / foodname: [%s] / totaltime: [%2d] \n",
          predicted.tablenumber  /* 	 block  14 */
        , predicted.foodname    /* 	 block 15	  */
        , predicted.totaltime   /* 	 block 16	  */
        );

    // 3.7) 28�е� ������ �������� ���� �����ǰ� �ִ� ������ ������ ����Ͽ���.
    printf("cooking now : \n");
    printf("tablenumber: [%2d] / foodname: [%s] / totaltime: [%2d] \n",
          temp.getFront().tablenumber     /* block 17 */
        , temp.getFront().foodname  /* 	 block 18	  */
        , temp.getFront().totaltime  /* 	 block 19 	  */
        );
    return 0;
}
