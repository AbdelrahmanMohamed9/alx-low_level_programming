#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buf(char *file);
void close_file(int fd);

/**
 * create_buf - Allocates 1024 bytes for a buffer.
 * @file: name of the file buf is storing chars for.
 *
 * Return:  pointer to the newly-allocated buf.
 */

char *create_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - Closes the file descriptors.
 * @fd: The file descriptor closed.
 */
void close_file(int fd)
{
	int n;

	n = close(fd);

	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy the file to another file.
 * @argc:  number of arguments supplied to the program.
 * @argv:  array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If argument count is incorrect exit code 97.
 *              If file_from doesn't exist or can't read  exit code 98.
 *              If file_to can't be creat or written to exit code 99.
 *              If file_to or file_from can't be closed exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, R, W;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buf(argv[2]);
	from = open(argv[1], O_RDONLY);
	R = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || R == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		W = write(to, buf, R);
		if (to == -1 || W == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		R = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (R > 0);

	free(buf);
	close_file(from);
	close_file(to);

	return (0);
}
