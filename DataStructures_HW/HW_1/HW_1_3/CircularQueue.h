#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "TableFood.h"

#define MAX_QUEUE_SIZE	100

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};


class CircularQueue
{
public:
	int	front;
	int	rear;
	TableFood	data[MAX_QUEUE_SIZE];

public:
	CircularQueue()
		: front(0), rear(0), data{ 0 } { }
	~CircularQueue() { }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(TableFood val) {
		if (isFull())
			error("  Error: Queue is full \n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	TableFood dequeue() {
		if (isEmpty())
			error("  Error: Queue is empty \n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	TableFood peek() {
		if (isEmpty())
			error("  Error: Queue is empty \n");
		else
			return data[(front + 1) % MAX_QUEUE_SIZE];
	}
	void display() {
		printf("Queue elements : ");
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++)
			printf("tablenumber: [%2d] / foodname: [%s] / totaltime: [%2d] \n", data[i % MAX_QUEUE_SIZE].tablenumber
				, data[i % MAX_QUEUE_SIZE].foodname
				, data[i % MAX_QUEUE_SIZE].totaltime
			);
		printf("\n");
	}
};
