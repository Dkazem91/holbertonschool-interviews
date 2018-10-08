#include "search_algos.h"
/**
 * print_array - prints array
 * @array: array to print
 * @start: start of array
 * @end: end of array
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	while (i <= end)
	{
		if (i != end)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
		i++;
	}
}
/**
 * recursive - finds value at index
 * @array: array to print values
 * @start: start of array
 * @end: end of array
 * @value: value to find
 * Return: index or -1
 */
int recursive(int *array, size_t start, size_t end, int value)
{
	size_t mid = (start + end) / 2;

	print_array(array, start, end);
	if (array[mid] == value)
		return (mid);
	if (end > start)
	{
		if (array[mid] < value)
			return (recursive(array, mid + 1, end, value));
		return (recursive(array, start, mid, value));
	}
	return (-1);
}
/**
 * binary_search - searches binarily
 * @array: array to print values
 * @size: size of array
 * @value: value to find
 * Return: recursive value
 */
int binary_search(int *array, size_t size, int value)
{
	if (!(array))
		return (-1);
	return (recursive(array, 0, size - 1, value));
}
