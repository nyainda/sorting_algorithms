#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t counter1, counter2;
	int temp_swap, flag = 0;

	/*Check inputs*/
	if (array == NULL || size == 0)
	{
		return;
	}

	/* Counts through the current step in the sort */
	for (counter1 = 0; counter1 < size - 1; counter1++)
	{
		/* Loop through array */
		for (counter2 = 0; counter2 < size - counter1 - 1; counter2++)
		{
			if (array[counter2] > array[counter2 + 1])
			{
				/* Swap a[i] with a[1 + 1] */
				temp_swap = array[counter2];
				array[counter2] = array[counter2 + 1];
				array[counter2 + 1] = temp_swap;
				/* Print result */
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
