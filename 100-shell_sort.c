#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			insert = array[i];
			for (j = i; j >= gap && array[j - gap] > insert; j = j - gap)
				array[j] = array[j - gap];
			array[j] = insert;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
