
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int removeduparray(int *Arr, int len)
{
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
	return templen;
}

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount)
{
	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;

	int length = removeduparray(Arr, len);

	if (length == 1 && score == Arr[0])
	{
		*lessCount = 0;
		*moreCount = 0;
		return NULL;
	}
	else if (length == 1 && score > Arr[0])
	{
		*lessCount = 1;
		*moreCount = 0;
		return NULL;
	}
	else if (length == 1 && score < Arr[0])
	{
		*lessCount = 0;
		*moreCount = 1;
		return NULL;
	}

	int index = 0, temp = 0;
	int final_index;
	int tempvar = score;

	do
	{
		while ((index + temp) < length && Arr[index + temp] < tempvar)
			index = (index * 2) + 1;

		temp = temp + (index / 2);

		index = 0;

		if (temp == length - 1)
		{
			final_index = temp;
			break;
		}
		if (Arr[temp] == tempvar  &&  temp <= length || (Arr[temp] < tempvar && Arr[temp + 1] >= tempvar))
		{
			final_index = temp;
			break;
		}


	} while (Arr[temp] < tempvar  && temp <= length);

	length--;
	if (Arr[final_index] == tempvar)
		*lessCount = final_index;
	else
		*lessCount = final_index + 1;

	if (Arr[final_index + 1] == tempvar)
		*moreCount = length - final_index - 1;
	else
		*moreCount = length - final_index;

	return NULL;
}