#include "sort.h"

void sift_down(int *array, size_t start, size_t end, size_t size);
void swap_elem(int *arr, size_t size, int *a, int *b);


/**
 * sift_down - Builds heap form bottom up
 *
 * @array: List to be sorted
 * @start: Subscript of the root ot the heap
 * @size: Size of array
 * @end: Subscript of the last element of the heap
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child, swap;

	root = start;

	while ((root * 2) + 1 <= end)
	{
		/* Subscript of left child */
		child = (root * 2) + 1;
		swap = root;

		if (array[swap] < array[child])
		{
			/* Swap root and left child */
			swap = child;
		}
		if (child + 1 <= end && array[swap] < array[child + 1])
		{
			/* Swap root with right child */
			swap = child + 1;
		}
		/* If one child is greater than other */
		if (swap != root)
		{
			swap_elem(array, size, &array[root], &array[swap]);
			root = swap;
		}
		else
		{
			return;
		}
	}
}


/**
 * heapify - Arranges heap so largest number is root
 * @array: array (for print)
 * @size: size of array (for print)
 */
void heapify(int *array, size_t size)
{
	int start;

	/* Last non-leaf */
	start = (size / 2) - 1;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}


/**
 * heap_sort - Sort list in ascending order
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	size_t last;

	if (!array || size < 2)
	{
		return;
	}

	last = size - 1;

	heapify(array, size);

	while (last > 0)
	{
		swap_elem(array, size, &array[last], &array[0]);
		last--;
		sift_down(array, 0, last, size);
	}
}

/**
 * swap_elem - swap value of array elements
 * @array: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_elem(int *array, size_t size, int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}
