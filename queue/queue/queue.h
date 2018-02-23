#pragma once
#include "q_stdafx.h"

typedef struct {
	int* arr;
	int front;
	int rear;
	int capacity;
	int length;
}queue;

#ifdef _cplusplus
extern "C"{
#endif

queue* EMPTY_QUEUE();

void del_QUEUE(queue* q);

void enqueue(queue* q,int key);

int dequeue(queue* q);

#ifdef _cplusplus
}
#endif