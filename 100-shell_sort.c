#include "sort.h"

/**
 * knuth_seq - Find largest gap for a given size
 * @size: Size of the array
 * Return: Void
 */

size_t knuth_seq(size_t size)
{
	size_t counter;

	for (counter = 1; counter < size; counter = (counter * 3) + 1)
	{
		;
	}
	return ((counter - 1) / 3);
}


/**
 * shell_sort - Sorts an array of integers
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

    /*Check inputs*/
	if (array == NULL || size == 0)
	{
		return;
	}

	/* Begin gap at largest knuth seq. For each pass, reduce gap by 1/3*/
	for (gap = knuth_seq(size); gap; gap = (gap - 1) / 3)
	{
		/* Check elements to the right of gap */
		for (i = gap; i < size; i++)
		{
			/* Save elements in first gap to array[counter1]*/
			temp = array[i];

			/* Shift gapped element left until array[i] is in correct position*/
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
