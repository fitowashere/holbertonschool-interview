#include "menger.h"

/**
 * is_center - Checks if the given position is a center that should be empty
 * @row: Row position
 * @col: Column position
 *
 * Return: 1 if position should be empty, 0 otherwise
 */
int is_center(int row, int col)
{
	/* Check all levels from the current down to level 1 */
	while (row > 0 || col > 0)
	{
		/* If both row and col are centered in a 3x3 grid, this is a center */
		if (row % 3 == 1 && col % 3 == 1)
			return (1);

		/* Move up to the next level (divide by 3) */
		row /= 3;
		col /= 3;
	}

	/* If we reach here, this position is not a center */
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	/* Return if level is negative */
	if (level < 0)
		return;

	/* Calculate size of the sponge: 3^level */
	size = pow(3, level);

	/* Draw the sponge row by row */
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			/* If this position is a center (in any level), print a space */
			if (is_center(row, col))
				printf(" ");
			else
				printf("#");
		}
		/* New line after each row */
		printf("\n");
	}
}