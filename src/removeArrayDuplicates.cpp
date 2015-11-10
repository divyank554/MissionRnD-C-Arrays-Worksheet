/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;
	
		int i, j;

		int templen = 1;

		for (i = 1; i < len; i++)
		{

			for (j = 0; j < templen; j++)
			{

				if (Arr[i] == Arr[j])
					break;
			}

			if (j == templen)
				Arr[templen++] = Arr[i];
		}

		for (i = 0; i < templen; i++)
			printf(" %d", Arr[i]);

}