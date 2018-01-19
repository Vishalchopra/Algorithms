#include <stdio.h>

void insert_sort(int *, int);

#define my_Sizeof(ptr) (char *)(&ptr + 1) - (char *)(&ptr)

int main()
{
	int arr[] = {5, 1, 6, 2, 0, 10};
	int siz, i;
	siz = (my_Sizeof(arr))/(my_Sizeof(arr[0]));
	insert_sort(arr, siz);
	 for (i = 0; i < siz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void insert_sort(int *arr, int size)
{
	int var, var1, key;
	for (var = 1; var < size; var++){
		key = *(arr + var);
		var1 = var - 1;
		while (var1 >= 0 && key > arr[var1]){
			*(arr + var1 + 1) = *(arr + var1);
			var1--;
		}
		*(arr + var1 + 1) = key;
	}
}
