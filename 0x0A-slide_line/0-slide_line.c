#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * right - if the case if move to the direction right
 * @line: pointer to a first number
 * @size: size of the array
 */
void right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] + line[j - 1];
					line[j - 1] = 0;
					break;
				}
				if (line[i - 1] != line[j - 1] &&
				    line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}

/**
 * left - if the case if move to the direction left
 * @line: pointer to a first number
 * @size: size of the array
 */
void left(int *line, size_t size)
{
	size_t i, j, p;

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
			while (line[i] == 0)
				i++;
		if (i == (size - 1))
			break;

		j = i + 1;
		if (line[j] == 0)
			while (line[j] == 0)
				j++;

		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}

	for (i = 0, p = 0; i < size; i++)
		if (line[i] != 0)
			line[p++] = line[i];
	while (p < size)
		line[p++] = 0;
}

/**
 * slide_line - slide & merge it to the left or to the right
 * @line: pointer to an arrray of int conteining size n
 * @size: Number of elements in line
 * @direction: directions
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == 0)
		left(line, size);
	if (direction == 1)
		right(line, size);
	return (1);
}
