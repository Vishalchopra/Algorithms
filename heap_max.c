#include <stdio.h>
#include <stdlib.h>

#define my_sizeof(type)  (char *)(&type + 1) - (char *)(&type)

void heapMax(int *, int, int);
void swap(int *, int, int);

int main ()
{
	int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int len = (my_sizeof(arr))/(my_sizeof(arr[0]));

	int loopVar;
	for (loopVar = len/2; loopVar >= 0; --loopVar){
		heapMax(arr, loopVar, len);
	}

	for (loopVar = len -1; loopVar >= 0; --loopVar){
		swap(arr, 0, loopVar);
		heapMax(arr, 0, loopVar-1);
	}

	for (loopVar = 0; loopVar < len; loopVar++){
		printf("%d ", arr[loopVar]);
	}
	printf("\n");
	return 0;
}


void heapMax(int arr[], int i, int len)
{
	int large, l, r;
	l = 2*i + 1;
	r = 2*(i + 1);

	if (l <= len && arr[i] < arr[l])
		large = l;
	else
		large = i;
	if (r <= len && arr[large] < arr[r])
		large = r;
	if (large != i){
		swap(arr,  large, i);
		heapMax(arr, large, len);
	}
}

void swap(int arr[], int var, int var1)
{
	arr[var]  = arr[var] ^ arr[var1];
	arr[var1] = arr[var] ^ arr[var1];	
	arr[var]  = arr[var] ^ arr[var1];

}


