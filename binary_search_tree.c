#include <stdio.h>
#include <stdlib.h>

struct binary_tree{
	int data;
	struct binary_tree *left;
	struct binary_tree *right;
};

enum {
	INSERT=1,
	DISPLAY,
};

/**************************Function Prototype**********************/
void insert_binary_tree(struct binary_tree **, int);
struct binary_tree *create_new_node(int);
void display_binary(struct binary_tree *);


/**************************Main Function**************************/
int main()
{
	struct binary_tree *start = NULL;

	while (1){
		int choice = 0;
		printf("Press 1 for insert an element\n");
		printf("Press 2 for display binary tree\n");

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
	else
		temp->right = new_binary_tree;
		
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
