#pragma once
#include "q_stdafx.h"

typedef struct {
	void* (*arr);
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

void enqueue(queue* q,void* key);

void* dequeue(queue* q);

#ifdef _cplusplus
}
#endif