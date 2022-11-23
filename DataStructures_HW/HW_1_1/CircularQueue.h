#pragma once
#include <stdio.h>
#include <stdlib.h>

// 2) MAX_QUEUE_SIZE의 적절한 수를 정의하시오.
#define MAX_QUEUE_SIZE 13

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};


class CircularQueue
{
	int	front;
	int	rear;
	int	data[MAX_QUEUE_SIZE];

public:
	CircularQueue() { front = rear = 0; }
	~CircularQueue() { }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(int val) {
		if (isFull())
			error("  Error: Queue is full \n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			printf("rear index is : %d\n", rear);
			data[rear] = val;
		}
	}
	int dequeue() {
		if (isEmpty())
			error("  Error: Queue is empty \n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			printf("front index is : %d\n", front);
			return data[front];
		}
	}
	int peek() {
		if (isEmpty())
			error("  Error: Queue is full \n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {
		printf("Queue elements : ");

		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

		for (int i = front + 1; i <= maxi; i++)
			printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
};
