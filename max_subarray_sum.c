#include <stdio.h>

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)

int mamSubarraySum(int *, int , int);
int maxCrossingSum(int *, int, int, int);
int max(int, int, int);

int main()
{
	int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int len, loopVar, maxSum;
	len = (my_sizeof(arr))/(my_sizeof(arr[0]));

	maxSum = maxSubarraySum(arr, 0, len-1);

	printf("%d\n",maxSum);

	return 0;
}


int maxSubarraySum(int *arr, int start, int end)
{
	if (start == end)
		return arr[start];
	int mid;
	mid = (end + start)/2;
	return max(maxSubarraySum(arr, start, mid),
		   maxSubarraySum(arr, mid + 1, end),
		   maxCrossingSum(arr, start, mid, end));
}

int maxCrossingSum(int *arr, int start, int mid, int end)
{
	int loopVar, loopVar1;
	int leftSum, rightSum, sum;
	leftSum = rightSum = sum = 0;

	for (loopVar = mid; loopVar >= start; loopVar--){
		sum = sum + arr[loopVar];
		if (sum > leftSum)
			leftSum = sum;
	}
	sum = 0;
	for (loopVar = mid+1; loopVar <= end; loopVar++){
		sum = sum + arr[loopVar];
		if (sum > rightSum)
			rightSum = sum;
	}
	return leftSum + rightSum;
	
}

int max(int a, int b, int c)
{
	return (a > b)?((a > c)?a:b):(b > c)?b:c;
}
