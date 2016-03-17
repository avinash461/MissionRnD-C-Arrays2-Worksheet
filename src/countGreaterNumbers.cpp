/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stddef.h>
#include <stdio.h>
int binary_search(struct transaction *array, int low, int high, char *date);
int is_dates_equal(char *date1, char *date2);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if ((Arr) && len > 0 && (date))
	{
		int temp2 = 0;
		int date_index = binary_search(Arr, 0, len, date);
		while (is_dates_equal(Arr[date_index].date, date) == 1 && date_index<len)
		{
			date_index++;
		}
		//printf("%d", len - date_index);
		return len - date_index;

	}

	return 0;
}
int binary_search(struct transaction *array, int low, int high, char *date)
{
	int temp = 0;
	int mid = 0;
	while (low < high)
	{
		printf("%d %d\n", low, high);
		mid = (low + high) / 2;
		temp = is_dates_equal(array[mid].date, date);
		if (temp == 1)
			return mid;
		else if (temp == -1)
		{
			low = mid + 1;
			//printf("low=%d\n", low);
		}
		else if (temp == -2)
		{
			high = mid - 1;
			//printf("high=%d\n", high);
		}

		//printf("%d\n mid value\n", mid);
	}
	if (is_dates_equal(array[low].date, date))
		return low;
	if (is_dates_equal(array[low - 1].date, date) == -2)
	{
		return low - 1;
	}
	else
	{
		return low + 1;
	}

}
int is_dates_equal(char *date1, char *date2)
{
	int day1 = 0, day2 = 0, year1 = 0, year2 = 0, month1 = 0, month2 = 0;
	year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
	year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
	month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
	month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	day1 = (date1[0] - '0') * 10 + (date1[1] - '0');
	day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	//printf("%d %d %d %d %d %d\n", day1, month1, year1, day2, month2, year2);
	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (day1 == day2)
			{
				printf("found equality");
				return 1;
			}
			else return day1>day2 ? -2 : -1;
		}
		else return month1>month2 ? -2 : -1;
	}
	else return year1>year2 ? -2 : -1;
}