#include "q_stdafx.h"
#include "queue.h"

#define NEW_QUEUE() ((queue*)malloc(sizeof(queue)))
#define NEW_VOID(num) ((void*)(malloc(sizeof(void*)*num)))

#define VOID(ptr) ((void*)ptr)

static void expand_queue(queue* q);
static void shrink_queue(queue* q);

queue* EMPTY_QUEUE() {
	queue* temp = NEW_QUEUE();
	temp->arr=NEW_VOID(2);
	temp->capacity = 2;
	temp->length = 0;
	temp->front = 0;
	temp->rear = 0;
	return temp;
}

void del_QUEUE(queue* q) {
	int start = q->front;
	for (int i = 0; i < q->length; i++)
	{
		free(q->arr[start]);
		start = (start + 1) % q->capacity;
	}
	free(VOID(q->arr));
	free(q);
}

void enqueue(queue* q, void* key) {
	if (q->length == q->capacity) expand_queue(q);
	if (q->length == 0)
	{
		q->arr[q->rear] = key;
		q->length++;
		return;
	}

	q->rear = (q->rear + 1) % q->capacity;
	q->length++;
	q->arr[q->rear] = key;
}

void* dequeue(queue* q) {
	if (q->length == 0) return NULL;
	if (q->length < q->capacity/4) shrink_queue(q);
	if (q->length == 1) {
		void* temp = q->arr[q->front];
		q->length--;
		return temp;
	}
	//printf("capacity is %d \n",q->capacity);
	void* temp = q->arr[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->length--;
	return temp;
}


static void expand_queue(queue* q) {
	void* (*cache) = NEW_VOID(q->capacity*2);
	int start = q->front;
	for (int i = 0; i < q->length; i++)
	{
		cache[i] =q->arr[start] ;
		start = (start + 1) % q->capacity;
	}
	free(q->arr);
	q->arr = cache;
	q->front = 0;
	q->rear = q->length - 1;
	q->capacity *= 2;
}

static void shrink_queue(queue* q) {
	void* (*cache)
		= NEW_VOID(q->capacity /2);
	int start = q->front;
	for (int i = 0; i < q->length; i++)
	{
		cache[i] = q->arr[start];
		start = (start + 1) % q->capacity;
	}
	free(q->arr);
	q->arr = cache;
	q->front = 0;
	q->rear = q->length - 1;
	q->capacity /= 2;


}