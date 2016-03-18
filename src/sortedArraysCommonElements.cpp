/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <stdlib.h>
int valid_dates_equal(char *date1, char *date2);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if ((A) && (B) && ALen > 0 && BLen > 0)
	{
		struct transaction *result_array;
		struct transaction *common;
		result_array = (struct transaction*)malloc(sizeof(struct transaction)*10);
		common = (struct transaction*)malloc(sizeof(struct transaction)*10);
		int new_arr_index = 0, i = 0, j = 0, temp = 0,common_index=0;
		while (i < ALen && j < BLen)
		{
			printf("hi");
			temp = valid_dates_equal(A[i].date, B[j].date);
			if (temp == -1)
			{
				result_array[new_arr_index] = A[i];
				new_arr_index++;
				i++;
			}
			if (temp == -2)
			{
				result_array[new_arr_index] = B[j];
				new_arr_index++;
				j++;
			}
			if (temp == 1)
			{
				result_array[new_arr_index] = A[i];
				new_arr_index++;
				i++;
			}
		}
		if ((i == ALen) && j < BLen)
		{
			while (j < BLen)
			{
				result_array[new_arr_index] = B[j];
				j++;
				new_arr_index++;
			}
		}
		if ((j == BLen) && i < ALen)
		{
			while (i < ALen)
			{
				result_array[new_arr_index] = A[i];
				i++;
				new_arr_index++;
			}
		}

		for (int i = 0; i < new_arr_index; i++)
		{
			if (result_array[i].amount == result_array[i + 1].amount)
			{
				common[common_index] = result_array[i];
				common_index++;
			}
		}

		if (common_index == 0)
			return NULL;
		return common;

	}
	return NULL;
}
int valid_dates_equal(char *date1, char *date2)
{
	int day1 = 0, day2 = 0, year1 = 0, year2 = 0, month1 = 0, month2 = 0;
	year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
	year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
	month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
	month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	day1 = (date1[0] - '0') * 10 + (date1[1] - '0');
	day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (day1 == day2)
			{
				//printf("found equality");
				return 1;
			}
			else return day1>day2 ? -2 : -1;
		}
		else return month1>month2 ? -2 : -1;
	}
	else return year1>year2 ? -2 : -1;
}