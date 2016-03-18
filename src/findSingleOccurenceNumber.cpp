/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include <stdlib.h>
int findSingleOccurenceNumber(int *A, int len) {
	if ((A) && len > 0)
	{
		int max_value = 0;
		char *new_array;
		for (int i = 0; i < len; i++)
		{
			if (A[i]>max_value)
				max_value = A[i];
		}
		new_array = (char*)malloc(sizeof(char)*max_value);
		for (int i = 0; i <= max_value; i++)
		{
			new_array[i] = 0;
		}
		for (int j = 0; j < len; j++)
		{
			new_array[A[j]]++;
		}
		for (int j = 0; j <= max_value; j++)
		{
			if (new_array[j] == 1)
				return j;
		}
	}
	return -1;
}