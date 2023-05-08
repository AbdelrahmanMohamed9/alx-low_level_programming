#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buf(char *fl);
void close_file(int gg);

/**
 * create_buf - Allocates 1024 bytes for a buffer.
 * @fl: name of the file buf is storing chars for.
 *
 * Return:  pointer to the newly-allocated buf.
 */

char *create_buf(char *fl)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", fl);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - Closes the file descriptors.
 * @gg: The file descriptor closed.
 */
void close_file(int gg)
{
	int n;

	n = close(gg);

	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", gg);
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
	int f, t, e, m;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buf(argv[2]);
	f = open(argv[1], O_RDONLY);
	e = read(f, buf, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || e == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		m = write(t, buf, e);
		if (t == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		e = read(f, buf, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (e > 0);

	free(buf);
	close_file(f);
	close_file(t);

	return (0);
}
