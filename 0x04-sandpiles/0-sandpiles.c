#include "sandpiles.h"

/**
 * sandpiles_sum - adds two sandpiles and prints each topple
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, not_even = 0;

	while (1)
	{
		not_even = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += grid2[i][j];
				grid2[i][j] = 0;
				if (grid1[i][j] > 3)
					not_even = 1;
			}
		if (not_even == 0)
			return;
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;

					if (i < 2)
						grid2[i + 1][j] += 1;
					if (j < 2)
						grid2[i][j + 1] += 1;
					if (i > 0)
						grid2[i - 1][j] += 1;
					if (j > 0)
						grid2[i][j - 1] += 1;
				}
			}
	}
}

/**
 * print_grid - prints sandpile grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
