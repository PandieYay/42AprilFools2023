#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i;
	unsigned long frame_length;

	if (argc == 1)
		return (-1);
	i = 0;
	// + 4 because we want the whole frame (Two spaces and two more *)
	frame_length = strlen(argv[1]) + 4;

	for (unsigned long i = 0; i < frame_length; ++i)
		printf("*");
	printf("\n");
	while (++i < argc)
	{
		printf("* %s", argv[i]);
		// Minus 3 because we already have front frame * and we only want to print the space
		for (unsigned long k = strlen(argv[i]); k < frame_length - 3; ++k)
			printf(" ");
		printf("*\n");
	}
	for (unsigned long i = 0; i < frame_length; ++i)
		printf("*");
	printf("\n");
	return (0);
}