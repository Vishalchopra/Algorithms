#include <stdlib.h>
#include <stdio.h>
#include "queue_header.h"


/* This function create queue main node
 * size is data size that you want to store
 */
struct Queue *createQueue(int size)
{
	struct Queue *new = (struct Queue *)malloc(sizeof(*new));
	new->queueSize = 0;
	new->queueDataSize = size;
	new->start = NULL;
	return new;
}


void enQueue(struct Queue *queue, const void *data)
{
	struct queueList *temp, *newNode = (struct queueList *)malloc(sizeof(*newNode));
	if (NULL == newNode){
		perror("malloc");
		return;
	}
	temp = queue->start;
	newNode->data = data;
	newNode->next = NULL;
	queue->queueSize++;

	if (NULL == temp){
		queue->start = newNode;
		return;
	}
	while (NULL != temp->next)
		temp = temp->next;
	
	temp->next = newNode;
}
/* 
 * deQueue function remove the data from queue and return address of the data.
 * return type is void * need to type cast before storing to any variable.
 */
void *deQueue(struct Queue *queue)
{
	struct queueList *temp;
	void *data;
	if (NULL == queue){
		printf("Queue is not created\n");
		return;
	}
	if (!queue->queueSize){
		printf("Nothing to dequeu\n");
		return;
	}
	temp = queue->start;
	queue->start = queue->start->next;
	data = temp->data;
	queue->queueSize--;
	free(temp);
	temp = NULL;
	return data;
}

int isQueueEmpty(struct Queue *queue)
{
	return queue->queueSize;
}

void my_memcpy(void *dest, const void *src, int size)
{
	char *csrc, *cdest;
	csrc = (char *)src;
	cdest = (char *)dest;
	while (size--)
		*cdest++ = *csrc++;

}
