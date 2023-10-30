#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * main - Copy the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success, 97, 98, 99, or 100 on failure.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, read_result, write_result;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", argv[1]);
		exit(98);
	}

	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (to_fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		close(from_fd);
		exit(99);
	}

	while ((read_result = read(from_fd, buffer, 1024)) > 0)
	{
		write_result = write(to_fd, buffer, read_result);
		if (write_result == -1 || write_result != read_result)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			close(from_fd);
			close(to_fd);
			exit(99);
		}
	}

	if (read_result == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", argv[1]);
		close(from_fd);
		close(to_fd);
		exit(98);
	}

	if (close(from_fd) == -1 || close(to_fd) == -1)
	{
		dprintf(2, "Error: Can't close fd\n");
		exit(100);
	}

	return (0);
}

