#ifndef CYCQUEUE_H
#define CYCQUEUE_H

#define MAXSIZE 50   //define the length of the queue

typedef unsigned char byte;

//queue element data structure
typedef union{
	char buf[5];
	struct {
		char nodeName;
		char temperature[2];
		char humidity[2];
	}nodeUARTData_t;
}DATA;

//queue manager
typedef struct {
	DATA data[MAXSIZE];
	byte head;
	byte rear;
	byte count;
}CycQueue;

CycQueue *CycQueueInit();
void CycQueueFree(CycQueue *q);
bool CycQueueIsEmpty(CycQueue *q);
bool CycQueueIsFull(CycQueue *q);
bool CycQueueIn(CycQueue *q, DATA data);
DATA *CycQueueOut(CycQueue *q);
byte CycQueueLen(CycQueue *q);
DATA *CycQueuePeek(CycQueue *q);

#endif
