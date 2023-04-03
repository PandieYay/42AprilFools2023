#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int input = atoi(av[1]);
	if (input <= 0)
		return 2;
	int width = 7;
	int height = (3 * input);
	int last_height = 3;
	for (int j = 1; j < input; j++)
	{
		height += j;
		if (j == input - 1)
			last_height += j;
	}
	int width_layer[height];
	int width_layer_end = 0;
	int currblockHeight = 3;
	int currlayrWidth = 3;
	int step = 1;
	int blocksteps = 6;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0 ; j < currblockHeight; ++j)
		{
			width_layer[width_layer_end++] = currlayrWidth;
			currlayrWidth += 2;
		}
		currblockHeight++;
		currlayrWidth += blocksteps - 2;
		if (step++ == 2)
		{
			step = 1;
			blocksteps += 2;
		}
	}
	width = width_layer[width_layer_end - 1];
	int jng_index = -1;
	int door_size;
	if (input % 2 == 0)
		door_size = input - 1;
	else
		door_size = input;
	for (int i = 0; i < height - last_height; i++)
	{
		for (int x = 0; x < ((width - width_layer[i]) / 2); x++)
		{
			printf(" ");
		}
		for (int x = 0; x < width_layer[i] - 1; x++)
		{
			if (x == 0)
				printf("/");
			else
				printf("*");
		}
		printf("\\\n");
		jng_index = i;
	}
	for (int i = jng_index + 1; i < height; i++)
	{
		if (i - height + door_size < 0)
		{
			for (int x = 0; x < ((width - width_layer[i]) / 2); x++)
			{
				printf(" ");
			}
			for (int x = 0; x < width_layer[i] - 1; x++)
			{
				if (x == 0)
					printf("/");
				else
					printf("*");
			}
			printf("\\\n");
		}
		else
		{
			for (int x = 0; x < ((width - width_layer[i]) / 2); x++)
			{
				printf(" ");
			}
			for (int x = 0; x < width_layer[i] - 1; x++)
			{
				if (x > (width_layer[i]/2) - (door_size/2 + 1) && x < (width_layer[i]/2) + (door_size/2 + 1))
				{
					if (door_size >= 5 && x == (width_layer[i]/2) + (door_size/2 + 1) - 2 && i == height - (door_size/2) - 1)
						printf("$");
					else
						printf("|");
				}
				else if (x == 0)
					printf("/");
				else
					printf("*");
			}
			printf("\\\n");
		}
	}
}
