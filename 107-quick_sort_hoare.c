#include "sort.h"
size_t qsh_partition(int *arr, size_t size, size_t left, size_t right);
void swap_elem(int *arr, size_t size, int *a, int *b);
void qsh_manager(int *arr, size_t size, size_t left, size_t right);
/**
 * quick_sort_hoare - quick sort, Hoare partition scheme
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		qsh_manager(array, size, 0, size - 1);
}
/**
 * qsh_manager - manage sort recursion
 * @arr: original array
 * @size: size of original array
 * @left: leftmost element of partition
 * @right: rightmost element of partition
 */
void qsh_manager(int *arr, size_t size, size_t left, size_t right)
{
	size_t p;

	if (left < right)
	{
		p = qsh_partition(arr, size, left, right);

		qsh_manager(arr, size, left, p - 1);
		qsh_manager(arr, size, p, right);
	}
}
/**
 * qsh_partition - sorts partition according to pivot
 * @arr: original array
 * @size: size of original array
 * @left: leftmost element of partition
 * @right: rightmost element of partition
 *
 * Return: split point for new partitions
 */
size_t qsh_partition(int *arr, size_t size, size_t left, size_t right)
{
	int pivot = arr[right]; /* pivot is last elem */
	size_t l = left - 1, r = right + 1;

	while (1)
	{
		do {
			l++;
		} while (arr[l] < pivot);

		do {
			r--;
		} while (arr[r] > pivot);

		if (l >= r)
			break;

		swap_elem(arr, size, &arr[l], &arr[r]);
	}
	return (l);
}
/**
 * swap_elem - swap value of array elements
 * @arr: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_elem(int *arr, size_t size, int *a, int *b)
{
	int tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(arr, size); /* print updated array */
	}
}
