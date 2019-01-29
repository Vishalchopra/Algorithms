#include <stdio.h>
#include <stdlib.h>
#include "thread_binary_tree.h"

int main()
{
	func_input();
}

int func_input()
{
	int choice;
	threadBT *start = NULL;
	while (1){
		printf("\nPress 1 to insert TBT node\n");
		scanf("%d", &choice);
		switch (choice){
	
		case TBT_INSERT:
		{
			int data;
			printf("Please enter the data\n");
			scanf("%d", &data);
			insertTBTNode(&start, data); 
		}
		}
	}
}

void insertTBTNode(threadBT **start, int data)
{
	threadBT *newNode, *tempNode;
	int lDirection, rDirection;
	newNode = createTBTRoot(data);
	if (NULL == *start){
		*start = newNode;
		return;
	}
	tempNode = *start;

	while (tempNode){
		if (tempNode->data > data){
			if (tempNode->lBit)
				tempNode = tempNode->left;
			else{
				lDirection = 1;
				rDirection = 0;
				break;
			}
			
		}
		if (tempNode->data < data){
			if (tempNode->rBit)
				tempNode = tempNode->right;
			else{
				lDirection = 0;
				rDirection = 1;
				break;
			}
		}
		if (tempNode->data == data){
			printf("Data already present\n");
			return;
		}
	}

	if (lDirection){
		tempNode->left = newNode;
		tempNode->lBit = 1;

		newNode->left = newNode;
		newNode->right = tempNode->right;
	}

	if (rDirection){
		tempNode->right = newNode;
		tempNode->rBit = 1;

		newNode->left = tempNode;
		newNode->right = newNode;
	}

}
threadBT * createTBTRoot(int data)
{
	threadBT *start = NULL;
	start = (threadBT *)malloc(sizeof(*start));
	start->lBit = 0;
	start->left = NULL;
	start->rBit = 0;
	start->right = NULL;
	start->data = data;
	return start;
}
