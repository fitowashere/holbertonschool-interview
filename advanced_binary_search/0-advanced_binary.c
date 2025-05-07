#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to print
 * @left: The left index of the array
 * @right: The right index of the array
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_recursive - Recursively searches for a value in a sorted array
 * @array: Pointer to the first element of the array
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	/* Base case: If subarray is empty */
	if (left > right)
		return (-1);

	/* Print the current subarray */
	print_array(array, left, right);

	/* Calculate mid point */
	mid = left + (right - left) / 2;

	/* If we found the value at mid */
	if (array[mid] == value)
	{
		/* If this is the first occurrence or we reached the leftmost element */
		if (mid == 0 || array[mid - 1] != value)
			return (mid);

		/* Otherwise, continue searching in the left half (including mid) */
		return (binary_search_recursive(array, left, mid, value));
	}
	/* If value is in the left half */
	else if (array[mid] > value)
	{
		return (binary_search_recursive(array, left, mid - 1, value));
	}
	/* If value is in the right half */
	else
	{
		return (binary_search_recursive(array, mid + 1, right, value));
	}
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	/* Check if array is NULL or empty */
	if (array == NULL || size == 0)
		return (-1);

	/* Call the recursive function */
	return (binary_search_recursive(array, 0, size - 1, value));
}
