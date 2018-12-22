#include <stdio.h>
#include <stdlib.h>

struct binary_tree{
	int data;
	struct binary_tree *left, *right;
};

struct stackData {
	struct binary_tree *current;
	struct stackData *next;
};

struct Stack {
	int count;
	struct stackData *stackAddr;
};

enum {
	INSERT=1,
	DISPLAY,
	DISPLAY_PREORDER_NONREC,
};

/**************************Function Prototype**********************/
void insert_binary_tree(struct binary_tree **, int);
struct binary_tree *create_new_node(int);
void display_binary(struct binary_tree *);
struct Stack *create_stack();
void push (struct Stack *, struct binary_tree *);
void traverse_preorder(struct binary_tree *);
struct binary_tree *pop (struct Stack *);
int isStackEmpty(struct Stack *);


/**************************Main Function**************************/
int main()
{
	struct binary_tree *start = NULL;

	while (1){
		int choice = 0;
		printf("\nPress 1 for insert an element\n");
		printf("Press 2 for display binary tree\n");
		printf("Press 3 for display binary tree in non recursive way\n");

		scanf("%d", &choice);
		switch(choice){
		
		case INSERT:
		{
			int data;
			printf("Enter the data to be inserted\n");
			scanf("%d", &data);
			insert_binary_tree(&start, data);
		}
		break;
		
		case DISPLAY:
			display_binary(start);
		break;
		case DISPLAY_PREORDER_NONREC:
			traverse_preorder(start);
		break;
		default:
			printf("Enter a valid option\n");
		}
	
	}

	return 0;
}

/*********************************Insert Function************************/
void insert_binary_tree(struct binary_tree **start, int data)
{
	struct binary_tree *temp, *loopVar, *new_binary_tree;
	temp = NULL;
	loopVar = *start;

	new_binary_tree = create_new_node(data);
	
	while (loopVar != NULL){
		temp = loopVar;
		if (loopVar->data > data)
			loopVar = loopVar->left;
		else
			loopVar = loopVar->right;
	}

	if (temp == NULL){
		*start = new_binary_tree;
		return ;
	}
	if (temp->data > data)
		temp->left = new_binary_tree;
	else if (temp->data < data)
		temp->right = new_binary_tree;
	else{
		free(new_binary_tree);
		new_binary_tree = NULL;
	}
		
		
}

/**********************************Create New Node*****************************/
struct binary_tree *create_new_node(int data)
{
	struct binary_tree *new;
	new = (struct binary_tree *)malloc(sizeof(*new));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return new;

}

/**********************************Display************************************/
void display_binary(struct binary_tree *start)
{
	if (start == NULL)
		return;
	display_binary(start->left);
	printf("%d ", start->data);
	display_binary(start->right);
}

/********************************Pre-Order***************************************/
/*void traverse_preorder(struct binary_tree *root)
{
	struct Stack *stack = create_stack();

	while (1){
		while (root != NULL){
			printf("%d ", root->data);
			push(stack, root);
			root = root->left;
		}
		if (!isStackEmpty(stack))
			break;
		root = pop(stack);
		root = root->right;
	}
	printf("\n");
	free(stack);
	stack = NULL;
}*/
/////////second method
void traverse_preorder(struct binary_tree *root)
{
	struct Stack *stack = create_stack();
	struct stackData *stackList = NULL;
	push(stack, root);
	//stackList = stack->stackAddr;
	while (stack->count){
		printf("%d ", stack->stackAddr->current->data);
		pop(stack);
		if (root->right)
			push(stack, root->right);
		if (root->left)
			push(stack, root->left);
		if (stack->stackAddr)
			root = stack->stackAddr->current;
		//stackList = stack->stackAddr;
	}
}

/**********************************Traverse Inorder*************************************/
void traverse_inorder(struct binary_tree *root)
{
	struct Stack *stack = create_stack();
	while (1){
		while (root){
			push (stack, root);
			root = root->left;
		}
		if (!isStackEmpty(stack))
			break;
		printf("%d ", stack->stackAddr->current->data);//print top element in stack
		root = stack->stackAddr->current->right;
		pop(stack);
	}
}

/*******************************Create Stack*********************************************/
struct Stack *create_stack()
{
	struct Stack *S = NULL;
	S = (struct Stack *)malloc(sizeof(struct Stack *));
	S->count = 0;
	S->stackAddr = NULL;
	return S;	
		
}

void push (struct Stack *stack, struct binary_tree *nodeAddr)
{
	if (nodeAddr == NULL){
		printf("Please check the data\n");
		return;
	}
	struct stackData *top;
	top = (struct stackData *)malloc(sizeof(struct stackData));
	if (0 == stack->count){
		stack->count++;
		top->current = nodeAddr;
		top->next = NULL;
	} else {
		stack->count++;
		top->current = nodeAddr;
		top->next = stack->stackAddr;
		
	}
	stack->stackAddr = top;
}

struct binary_tree *pop (struct Stack *stack)
{
	struct binary_tree *temp = NULL;
	struct stackData *temp2 = NULL;
	if (stack == NULL && stack->stackAddr == NULL){
		printf ("Nothing to pop\n");
		return ;
	}
	stack->count--;
	temp = stack->stackAddr->current;
	temp2 = stack->stackAddr;
	stack->stackAddr = stack->stackAddr->next;
	free(temp2);
	temp2 = NULL;
	return temp;

}
int isStackEmpty(struct Stack *stack)
{
	return stack->count;
}
