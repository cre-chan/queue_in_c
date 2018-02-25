#include "test_stdafx.h"
#include "queue.h"
#include "Header.h"

#define count 20

int main() {
	queue* temp = EMPTY_QUEUE();
	student* stu = new student(1);
	enqueue(temp,(void*)stu);
	for (int i = 0; i < 3; i++)
	{
		student* p = (student*)dequeue(temp);
		int score = p->getscore();
		printf("%d ",score);
		p = new student(score*2);
		enqueue(temp,(void*)p);
		p = new student(score * 2+1);
		enqueue(temp, (void*)p);
	}
	/*for (int i = 0; i < count/2; i++)
	{
		student *p = new student(i);
		enqueue(temp, (void*)p);
	};
	
	dequeue(temp);
	for (int i = 0; i < count-1; i++)
	{
		student* p = (student*)dequeue(temp);
		printf("%d\n",p->getscore()); 
	}
		*/
	del_QUEUE(temp);
	system("pause");
	return 0;
}