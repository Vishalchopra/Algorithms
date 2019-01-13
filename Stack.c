#include "stack_header.h"


struct Stack *create_stack(int size)
{
        struct Stack *S = NULL;
        S = (struct Stack *)malloc(sizeof(struct Stack *));
        S->stackSize = 0;
	S->stackDataSize = size;
        S->start = NULL;
        return S;

}

void push (struct Stack *stack, void *data)
{
        struct stackList *top;
        top = (struct stackList *)malloc(sizeof(*top));
	if (NULL == top){
		perror("malloc");
		return ;
	}
      	if (0 == stack->stackSize){
                stack->stackSize++;
                top->data = data;
                top->next = NULL;
        } else {
                stack->stackSize++;
                top->data = data;
                top->next = stack->start;

        }
        stack->start = top;
}

void *pop (struct Stack *stack)
{
        void *data;
	struct stackList *temp = NULL;
        if (NULL == stack){
                printf ("Stack is not created\n");
                return ;
        }
	if (!stack->stackSize){
		printf("Nothing to pop\n");
		return;
	} 
        stack->stackSize--;
        temp = stack->start;
        stack->start = temp->next;
        data = temp->data;

        free(temp);
        temp = NULL;
        return data;

}
int isStackEmpty(struct Stack *stack)
{
        return stack->stackSize;
}

