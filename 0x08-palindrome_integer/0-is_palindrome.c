#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - check if an int is palindrome
 * @n: the integer to check
 * Return: 1 if n is palindrome, otherwise 0
**/
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, copy_n = n, tmp = 0;

	while (n != 0)
	{
		tmp = n % 10;
		reversed = reversed * 10 + tmp;
		n /= 10;
	}

	if (copy_n == reversed)
		return (1);
	return (0);
}
