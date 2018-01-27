#include <stdio.h>

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)

void merge_sort(int *, int , int);
void merge_array(int *, int, int, int);

int main()
{
	int arr[] = {5, 3, 4,1,9, 33, 0, 43, 7, 1000};
	int len, loopVar;
	len = (my_sizeof(arr))/(my_sizeof(arr[0]));

	merge_sort(arr, 0, len - 1);

	for (loopVar = 0; loopVar < len; loopVar++)
		printf("%d ", arr[loopVar]);

	printf("\n");
	return 0;
}


void merge_sort(int *arr, int start, int end)
{
	if (start == end)
		return;
	int mid;
	mid = (end + start)/2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);
	merge_array(arr, start, mid, end);
}

void merge_array(int *arr, int start, int mid, int end)
{
	int loopVar1, loopVar2, loopVar3, len1, len2;
	len1 = mid - start + 1;
	len2 = end - mid;
	int leftArr[len1], rightArr[len2];
	for (loopVar1 = 0; loopVar1 < len1; loopVar1++){
		leftArr[loopVar1] = *(arr + start + loopVar1);
	}
	for (loopVar2 = 0; loopVar2 < len2; loopVar2++){
		rightArr[loopVar2] = *(arr + mid + loopVar2 + 1);
	}
	loopVar2 = loopVar3 = 0;
	for (loopVar1 = start; loopVar1 <= end; loopVar1++){
		if (((leftArr[loopVar2] <= rightArr[loopVar3]) && (loopVar2 < len1)) || (loopVar3 >= len2)){

			*(arr + loopVar1) = leftArr[loopVar2++];
		} else  {
			*(arr + loopVar1) = rightArr[loopVar3++];
		}
	}

}
