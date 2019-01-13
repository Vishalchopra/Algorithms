#ifndef STACK_INCLUDE
#define STACK_INCLUDE
#include <stdio.h>
#include <stdlib.h>

struct stackList {
        void *data;
        struct stackData *next;
};

struct Stack {
        int stackSize;
	int stackDataSize;
        struct stackList *start;
};

struct Stack *create_stack(int size);
void push (struct Stack *, void *);
void *pop(struct Stack *);
#endif
