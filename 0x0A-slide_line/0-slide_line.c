#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: size of the array
 * @direction: left or right
 * Return: 1 on success 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction == 0)
		slide_left(line, size);
	else if (direction == 1)
		slide_right(line, size);
	else
		return (0);
	return (1);
}

/**
 * slide_right - slides all numbers to the right
 * @line: array of integers
 * @size: size of array
 */
void slide_right(int *line, size_t size)
{
	int i, next, j;

	for (i = (int) size - 1, next = i - 1; next >= 0;)
	{
		if (!line[i])
		{
			i--;
			next--;
			continue;
		}
		while (next >= 0 && line[next] == 0)
			next--;
		if (next < 0)
			break;
		if (line[i] == line[next])
		{
			line[i] *= 2;
			line[next] = 0;
			i = next - 1;
			next = i - 1;
		}
		else
		{
			i = next;
			next--;
		}
	}
	i = (int)size - 1;
	for (j = (int)size - 1; j >= 0; j--)
	{
		if (line[j] != 0)
		{
			line[i] = line[j];
			if (j < i)
				line[j] = 0;
			i--;
		}
	}
}
/**
 * slide_left - slides all numbers to the right
 * @line: array of integers
 * @size: size of array
 */
void slide_left(int *line, size_t size)
{
	int i, next, j;

	for (i = 0, next = 1; next < (int) size;)
	{
		if (!line[i])
		{
			i++;
			next++;
			continue;
		}
		while (next < (int) size && line[next] == 0)
			next++;
		if (next >= (int) size)
			break;
		if (line[i] == line[next])
		{
			line[i] *= 2;
			line[next] = 0;
			i = next + 1;
			next = i + 1;
		}
		else
		{
			i = next;
			next = i + 1;
		}
	}
	i = 0;
	for (j = 0; j < (int)size; j++)
	{
		if (line[j] != 0)
		{
			line[i] = line[j];
			if (j > i)
				line[j] = 0;
			i++;
		}
	}
}
