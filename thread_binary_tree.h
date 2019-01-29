#include <stdio.h>
#include <stdlib.h>

typedef struct threadBinaryTree {
	struct threadBinaryTree *right;
	struct threadBinaryTree *left;
	int data;
	int lBit:1;
	int rBit:1;

}threadBT;

enum {
	TBT_INSERT = 1,
};

int func_input();
int func_selection(int);
void insertTBTNode(threadBT **start, int data);
threadBT * createTBTRoot(int size);
