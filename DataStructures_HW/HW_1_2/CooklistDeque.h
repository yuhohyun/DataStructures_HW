#pragma once

#include "CircularQueue.h"

class CooklistDeque :
	public CircularQueue {
public:
	CooklistDeque() {}

	void addRear(TableFood val) { enqueue(val); }

	TableFood deleteFront() { return dequeue(); }

	TableFood getFront() { return peek(); }

	void addFront(TableFood val) {
		if (isFull())
			error("  Error: Deque is full \n");
		else {
			data[front] = val;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}

	TableFood deleteRear() {
		if (isEmpty())
			error("  Error: Deque is empty \n");
		else {
			TableFood ret = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}

	TableFood getRear() {
		if (isEmpty())
			error("  Error: Deque is empty \n");
		else return data[rear];
	}

	void display() {
		printf("Deque elements : \n");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			printf("tablenumber: [%2d] / foodname: [%s] / totaltime: [%2d] \n", data[i % MAX_QUEUE_SIZE].tablenumber
				, data[i % MAX_QUEUE_SIZE].foodname
				, data[i % MAX_QUEUE_SIZE].totaltime
			);
		// printf( "\n");
	}
};
