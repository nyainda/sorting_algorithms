#include "sort.h"

/**
 * selection_sort - Selection sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{

	size_t counter1, counter2, min_index, temp_swap;


	/*Check inputs*/
	if (array == NULL || size == 0)
	{
		return;
	}

	/* Loop through array*/
	for (counter1 = 0; counter1 < size - 1; counter1++)
	{
		/* Set current number to min_index */
		min_index = counter1;

		/*Find the smallest number and set to min_index  */
		for (counter2 = counter1 + 1; counter2 < size; counter2++)
		{
			if (array[counter2] < array[min_index])
			{
				min_index = counter2;
			}
		}
		/*If current index is not the smallest element*/
		if (min_index != counter1)
		{
			/*Swap element until smallest is before larger numbers*/
			temp_swap = array[min_index];
			array[min_index] = array[counter1];
			array[counter1] = temp_swap;
			print_array(array, size);
		}
	}
}
