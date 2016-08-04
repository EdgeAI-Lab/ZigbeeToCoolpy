#include "CycQueue.h"
#include <stdlib.h>
#include <arduino.h>

//initialize queue
CycQueue *CycQueueInit()
{
	CycQueue *q;
	if(q = (CycQueue *)malloc(sizeof(CycQueue)))
	{
		q->head  = MAXSIZE - 1;
		q->rear  = MAXSIZE - 1;
		q->count = 0;
		return q;
	}
	else
	{
		return NULL;
	}
}


//free the queue
void CycQueueFree(CycQueue *q)
{
	if(q != NULL)
		free(q);
}


//queue is empty?
bool CycQueueIsEmpty(CycQueue *q)
{
	return (q->count == 0);
}

//queue is full?
bool CycQueueIsFull(CycQueue *q)
{
	return (q->count == MAXSIZE);
}


//in queue
bool CycQueueIn(CycQueue *q, DATA data)
{
	if(q->count == MAXSIZE)
	{
		//Serial.printf("The queue is full!\n");
		return 0;
	}
	else
	{
		q->rear = (q->rear + 1) % MAXSIZE;
		q->data[q->rear] = data;
		q->count += 1;
		return 1;
	}
}


//out queue
DATA *CycQueueOut(CycQueue *q)
{
	if(q->count == 0)
	{
		//Serial.printf("The queue is empty!\n");
		return NULL;
	}
	else
	{
		q->head = (q->head + 1) % MAXSIZE;
		q->count -= 1;
		return &(q->data[q->head]);
	}
}

//get the length of the queue
byte CycQueueLen(CycQueue *q)
{
	return q->count;
}


//get the head element of the queue
DATA *CycQueuePeek(CycQueue *q)
{
	if(q->count == 0)
	{
		//Serial.printf("The queue is empty!\n");
		return NULL;
	}
	else
	{
		return &(q->data[(q->head + 1)%MAXSIZE]);
	}
}

