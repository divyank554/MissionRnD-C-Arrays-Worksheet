/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void copy(char *des, char *soc)
{
	int temp = 0;

	while (soc[temp] != '\0')
	{
		des[temp] = soc[temp];
		temp++;
	}
	des[temp] = '\0';
}

void * scoresDescendingSort(struct student *students, int len)
{
	if (students[0].name == '\0')
		return NULL;

	if (len < 0)
		return NULL;

	int i, j;
	int temp;
	char name1[10];
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < (len - i - 1); j++)
		{
			if (students[j].score < students[j + 1].score)
			{
				copy(name1, students[j].name);
				temp = students[j].score;
				copy(students[j].name, students[j + 1].name);
				students[j].score = students[j + 1].score;
				copy(students[j + 1].name, name1);
				students[j + 1].score = temp;
			}
		}
	}

}