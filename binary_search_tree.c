#include <stdio.h>
#include <stdlib.h>
#include "queue_header.h"
#include "stack_header.h"

#define QUE_INCLUDE

struct binary_tree{
	int data;
	struct binary_tree *left, *right;
};
enum {
	INSERT=1,
	DISPLAY,
	DISPLAY_PREORDER_NONREC,
	DISPLAY_INORDER_NONREC,
	DISPLAY_POSTORDER_NONREC,
	DISPLAY_LEVEL_ORDER,
	SIZE_OF_BINARY_TREE,
	DELETE_FULL_BINARY_TREE,
	HEIGHT_BINARY_TREE,
};

/**************************Function Prototype**********************/
void insert_binary_tree(struct binary_tree **, int);
struct binary_tree *create_new_node(int);
void display_binary(struct binary_tree *);
void traverse_preorder(struct binary_tree *);
void traverse_inorder(struct binary_tree *);
void levelOrderTraversal(struct binary_tree *);
int sizeOfBinaryTreeRec(struct binary_tree *);
void deleteBinaryTree(struct binary_tree *);
int heightBinaryTree(struct binary_tree *);


/**************************Main Function**************************/
int main()
{
	struct binary_tree *start = NULL;

	while (1){
		int choice = 0;
		printf("\nPress 1 for insert an element\n");
		printf("Press 2 for display binary tree\n");
		printf("Press 3 for display binary tree in non recursive way\n");
		printf("Press 4 for Inorder display binary tree in non recursive way\n");
		printf("Press 6 for display level order in binary tree \n");
		printf("Press 7 size of binary tree \n");
		printf("Press 8 delete Full binary tree \n");
		printf("Press 9 print height of binary tree \n");

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
			if (NULL == start){
				printf("Nothing to display\n");
				break;
			}
			display_binary(start);
		break;

		case DISPLAY_PREORDER_NONREC:
			traverse_preorder(start);
		break;

		case DISPLAY_INORDER_NONREC:
			if (NULL == start){
				printf("Nothing to display\n");
				break;
			}
			traverse_inorder(start);
		break;

		case DISPLAY_LEVEL_ORDER:
			levelOrderTraversal(start);
		break;

		case SIZE_OF_BINARY_TREE:
		{
			int size = 0;
			if (NULL == start){
				printf("Binary Tree is empty\n");
				break;
			}
			size = sizeOfBinaryTreeRec(start);
			printf("Size of the binary %d\n", size);
		}
		break;

		case DELETE_FULL_BINARY_TREE:
			if (NULL == start){
				printf("Nothing to delete\n");
				break;
			}
			deleteBinaryTree(start);
			start = NULL;
		break;
		case HEIGHT_BINARY_TREE:
		{
			int height;
			if (NULL == start){
				printf("Binary tree is empty\n");
				break;
			}
			height = heightBinaryTree(start);
			printf("Height of bianry tree is %d\n", height);
		}
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
		if ((loopVar->data) > data)
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
//	printf("%d ", start->data);	//for preOredr traversal
	display_binary(start->left);
	printf("%d ", start->data);	//for inOrder Traversal
	display_binary(start->right);
//	printf("%d ", start->data);	//for postOrder Traversal
}

/********************************Pre-Order***************************************/
void traverse_preorder(struct binary_tree *root)
{
	struct Stack *stack = create_stack(struct binary_tree);

	while (1){
		while (root != NULL){
			printf("%d ", root->data);
			push(stack, root);
			root = root->left;
		}
		if (!isStackEmpty(stack))
			break;
		root = (struct binary_tree *)pop(stack);
		root = root->right;
	}
	printf("\n");
	free(stack);
	stack = NULL;
}
/////////second method
/*void traverse_preorder(struct binary_tree *root)
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
*/
/**********************************Traverse Inorder*************************************/
void traverse_inorder(struct binary_tree *root)
{
	struct binary_tree *temp;
	struct Stack *stack = create_stack(sizeof(*root));

	while (1){
		while (root){
			push (stack, root);
			root = root->left;
		}
		if (!isStackEmpty(stack))
			break;
		temp = pop(stack);
		printf("%d ", temp->data);//print top element in stack
		root = temp->right;
	}
}


/*************************************Level Order Traversal***************************/
void levelOrderTraversal(struct binary_tree *root)
{
	struct binary_tree *temp;
	struct Queue *queue = createQueue(sizeof(*root));
	if (NULL == root){
		printf("Please check the data %s\n", __func__);
	}
	enQueue(queue, root);	
	while (queue->queueSize){
		temp = (struct binary_tree *)deQueue(queue);
		printf("%d ", temp->data);
		if (temp->left)
			enQueue(queue, temp->left);
		if (temp->right)
			enQueue(queue, temp->right);
	}
	free(queue);
	queue = NULL;
}

//level order traversal in reverse order

void revLevelOrderTraversal(struct binary_tree *root)
{/*
	struct binary_tree *temp;
	struct Stack *stack = create_stack(sizeof(*stack));
	struct stackList = NULL;
	struct Queue *queue = createQueue(sizeof(struct binary_tree));
	if (NULL == root){
		printf("Please check the data %s\n", __func__);
	}
	enQueue(queue, root);	
	while (queue->queueSize){
		temp = (struct binary_tree *)deQueue(queue);
		if (temp->left)
			enQueue(queue, temp->left);
		if (temp->right)
			enQueue(queue, temp->right);
		push(stack, temp);
	}

	while (isStackEmpty(stack)){
		printf("%d " );
	}
	free(queue);
	queue = NULL;
*/
}
/********************************Size of Binary Tree*******************************/
/*int sizeOfBinaryTreeRec(struct binary_tree *root)
{
	if (root == NULL)
		return 0;
	return (1 + sizeOfBinaryTreeRec(root->left) + sizeOfBinaryTreeRec(root->right));

}
*/
// size of binary tree non recurssive
int sizeOfBinaryTreeRec(struct binary_tree *root)
{
	struct Queue *queue = NULL;
	struct binary_tree *temp = NULL;
	int size = 0;
	queue = createQueue(sizeof(*root));
	enQueue(queue, root);
	while (isQueueEmpty(queue)){
		temp = (struct binary_tree *)deQueue(queue);
		size++;
		if (temp->left)
			enQueue(queue, temp->left);
		if (temp->right)
			enQueue(queue, temp->right);

	}
	free (queue);
	queue = NULL;
	return size;
}

/*****************Delete Binary Tree Recursive and Non-Recursive**********************/
/*void deleteBinaryTree(struct binary_tree *root)
{
	if (NULL == root)
		return NULL;
	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);

	free(root);
	root = NULL;

}
*/
void deleteBinaryTree(struct binary_tree *root)
{
	struct Queue *queue = NULL;
	struct binary_tree *temp = NULL;
	if (NULL == root){
		printf("Nothing to delete\n");
		return -1;
	}
	queue = createQueue(sizeof(*root));
	enQueue(queue, root);
	while (isQueueEmpty(queue)){
		temp = (struct binary_tree *)deQueue(queue);
		if (temp->left)
			enQueue(queue, temp->left);
		if (temp->right)
			enQueue(queue, temp->right);
		free(temp);
		temp = NULL;

	}
	free (queue);
	queue = NULL;
	
}

/************************Height of Binary Tree*************************/
/*int heightBinaryTree(struct binary_tree *root)
{
	int leftHeight, rightHeight;

	if (NULL == root)
		return 0;
	else{
		leftHeight = heightBinaryTree(root->left);
		rightHeight = heightBinaryTree(root->right);

		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}
}
*/
int heightBinaryTree(struct binary_tree *root)
{
	struct Queue *queue = NULL;
	struct binary_tree *temp = NULL;
	int height = 0;
	queue = createQueue(sizeof(*root));
	enQueue(queue, root);
	enQueue(queue, NULL);
	while (isQueueEmpty(queue)){
		temp = (struct binary_tree *)deQueue(queue);
		if (NULL == temp){
			if (isQueueEmpty(queue)){
				enQueue(queue, NULL);
			}
			height++;
		}else{
		if (temp->left)
			enQueue(queue, temp->left);
		if (temp->right)
			enQueue(queue, temp->right);
		}
	}
	free (queue);
	queue = NULL;
	return height;
}
