#ifndef QUEUE_INCLUDE
#define QUE_INCLUDE

struct queueList {
        void *data;
        struct queueList *next;
};

struct Queue {
	int queueSize;
	int queueDataSize;
	struct queueList *start;
};

struct Queue *createQueue(int size);
void my_memcpy(void *, const void *, int);
void enQueue(struct Queue *, const void *);
void *deQueue(struct Queue *);
int isQueueEmpty(struct Queue *);
#endif

