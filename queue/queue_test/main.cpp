#include "test_stdafx.h"
#include "queue.h"

#define count 20

int main() {
	queue* temp = EMPTY_QUEUE();
	for (int i = 0; i < count; i++)
	{
		enqueue(temp, i);
	};
	printf("\n");
	for (int i = 0; i < count; i++)
		printf("%d\n",dequeue(temp));
	del_QUEUE(temp);
	system("pause");
	return 0;
}