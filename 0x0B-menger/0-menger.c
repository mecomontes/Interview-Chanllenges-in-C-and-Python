#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the menger sponge to draw
 *
 */
void menger(int level)
{
	int i, j, result, ii, jj;
	char simbol;

	result = pow(3, level);

	for (i = 0; i < result; i++)
	{
		for (j = 0; j < result; j++)
		{
			simbol = '#';
			ii = i;
			jj = j;
			while (ii > 0)
			{
				if (ii % 3 == 1 && jj % 3 == 1)
					simbol = ' ';
				ii /= 3;
				jj /= 3;
			}
			printf("%c", simbol);
		}
		printf("\n");
	}
}
