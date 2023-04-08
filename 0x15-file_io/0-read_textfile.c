#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters read and write
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t m, s, d;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	m = open(filename, O_RDONLY);
	s = read(m, buf, letters);
	d = write(STDOUT_FILENO, buf, s);

	if (m == -1 || s == -1 || d == -1 || d != so)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(m);

	return (d);
}
