#include "sort.h"
size_t max_digits(int *array, size_t size);
size_t count_digits(size_t number);
int recurrences(int *array, size_t size, size_t range, size_t ex);
void r_counting_sort(int *array, size_t size, size_t ex);
/**
 * radix_sort - sort array using radix method
 * @array: array to sort
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t passes, place, i, j;

	if (!array || size < 2) /* if NULL passed, abort function */
		return;

	/* find largest number to determine number of passes */
	for (i = 0, passes = max_digits(array, size); i < passes; i++)
	{
		for (j = 0, place = 1; j < i; j++)
			place *= 10; /* determine digit to sort */
		r_counting_sort(array, size, place);
		print_array(array, size);
	}
}
/**
 * max_digits - determine digits in largest element of array
 * @array: array to parse
 * @size: size of array
 *
 * Return: max digits in elements
 */
size_t max_digits(int *array, size_t size)
{
	size_t i = 0, j, max = 0;

	while (i < size)
	{
		j = count_digits(array[i]);
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}
/**
 * count_digits - count digits in number
 * @number: number to count
 *
 * Return: number of digits in number
 */
size_t count_digits(size_t number)
{
	size_t digits = 0;

	for (; number > 0; digits++)
		number /= 10;

	return (digits);
}
/**
 * recurrences - Count number of time value is in list
 * @array: Array to be sorted
 * @size: Size of the array
 * @range: Distance between largest number
 * @ex: exponent to isolate significant digit
 *
 * Return: total number of recurrences
 */

int recurrences(int *array, size_t size, size_t range, size_t ex)
{
	int total = 0;
	size_t count;

	for (count = 0; count < size; count++)
	{
		if (((array[count] / ex) % 10) == range)
		{
			total++;
		}
	}
	return (total);
}


/**
 * r_counting_sort - Sorts array in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 * @ex: exponent to isolate significant digit
 */

void r_counting_sort(int *array, size_t size, size_t ex)
{
	size_t count1, count2, largest_num = 0, range = 0, temp = 0;
	int *count_array, *sorted_array;

	if (!array || size < 2)
	{
		return;
	}

	/* Find the largest number in list */
	for (count1 = 0; count1 < size; count1++)
	{
		if (((array[count1] / ex) % 10)  > largest_num)
		{
			largest_num = ((array[count1] / ex) % 10);
		}
	}
	/* Init. count_array as size of largest number (range) */
	count_array = malloc(sizeof(int) * (largest_num + 1));

	if (!count_array)
	{
		return;
	}

	/* Count recurrence number within range of largest number*/
	for (count2 = 0; count2 < (largest_num + 1); count2++)
	{
		if (count2 == 0)
		{
			count_array[count2] = recurrences(array, size, range, ex);
		}
		else
		{
			temp = count_array[count2 - 1] + recurrences(array, size, range, ex);
			count_array[count2] = temp;
		}
		range++;
	}
	/* Init. array to return sorted list */
	sorted_array = malloc(sizeof(int) * size);

	if (!sorted_array)
	{
		free(count_array);
		return;
	}

	for (count1 = 0, count2 = size - 1; count1 < size; count1++, count2--)
	{
		sorted_array[count_array[((array[count2] / ex) % 10)] - 1] = array[count2];
		count_array[((array[count2] / ex) % 10)]--;
	}
	for (count1 = 0; count1 < size; count1++)
	{
		array[count1] = sorted_array[count1];
	}
	free(count_array);
	free(sorted_array);
}
