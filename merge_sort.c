#include <stdio.h>

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)

void merge_sort(int *, int , int);

int main()
{
	int arr[] = {5, 3, 4,1,9, 33};
	int len;
	len = (my_sizeof(arr))/(my_sizeof(arr[0]));

	merge_sort(arr, arr[0], arr[len - 1]);
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
	merge_array(arr, start, mid, end)
}

void merge_array(int *arr, int start, int mid, int end)
{
	int loopVar1, loopVar2, loopVar3, len1, len2;
	len1 = mid - start + 1;
	len2 = end - mid;
	int leftArr[len1], rightArr[len2];
	for (loopVar1 = 0; loopVar1 < len1; loopVar1++)
		leftArr[loopvar1] = *(arr + start + loopVar1);
	for (loopVar2 = 0; loopVar2 < len1; loopVar2++)
		rightArr[loopvar2] = *(arr + mid + loopVar1 + 1);
	loopVar2 = loopVar3 = 0;
	for (loopvar1 = 0; loopVar1 < end; loopVar1++){
		if ((leftArr[loopVar1] <= rightArr[loopVar1]) && loopVar2 < len1){
			*(arr + loopVar1) = leftArr[loopVar2++];
		} else {
			*(arr + loopVar1) = rightArr[loopVar3++];
		}
	}

}
