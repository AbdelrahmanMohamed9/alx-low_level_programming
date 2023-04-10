#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t p, e, t;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	p = open(filename, O_RDONLY);
	e = read(p, buf, letters);
	t = write(STDOUT_FILENO, buf, e);

	if (p == -1 || e == -1 || t == -1 || t != e)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(p);

	return (t);
}
