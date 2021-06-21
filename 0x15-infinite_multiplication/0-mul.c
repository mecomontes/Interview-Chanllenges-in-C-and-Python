#include "holberton.h"

/**
 * error - error and exit 98.
 * Return: no return
 */
void error(void)
{
	int i;
	char err[] = "Error\n";

	for (i = 0; i <= 5; i++)
	{
		_putchar(err[i]);
	}
	exit(98);
}

/**
 * main - prints the number of arguments passed into it.
 * @argc: - # of parameters
 * @argv: - array of parameters
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		error();

	if (argv)
	{
	}
	return (0);
}
