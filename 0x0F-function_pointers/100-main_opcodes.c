#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *main_addr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	main_addr = (unsigned char *)&main;

	for (i = 0; i < num_bytes - 1; i++)
		printf("%02x ", main_addr[i]);

	printf("%02x\n", main_addr[i]);

	return (0);
}

