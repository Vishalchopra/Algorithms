#include <stdio.h>

#define my_sizeof(type) (char *)(&type -1) - (char *)(&type)

void cal_poly_eq(int poly[], int, int);
int main()
{
	int poly[] = {2, -3, 5, -7};
	int xValue = 3;
	int len = (my_sizeof(poly))/(my_sizeof(poly[0]));

	cal_poly_eq(poly, len, xValue);
	return 0;
}

void cal_poly_eq(int poly[], int len, int xValue)
{
	int result = poly[0];
	int loopVar;

	for (loopVar = 1; loopVar < len; loopVar++){
		result = result*xValue + poly[loopVar];
	}
	printf("Result of the polynomial: %d\n", result);
}
