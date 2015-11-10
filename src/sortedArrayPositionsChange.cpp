/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;

	int i, j;
	for (i = len - 1; len > 0; i--)
	{

		if (Arr[i] < Arr[i - 1])
		{
			int j = i - 1;
			while (Arr[i] < Arr[j] && j >= 0)
				j--;

			swap(&Arr[i], &Arr[j + 1]);
			break;
		}
	}

}