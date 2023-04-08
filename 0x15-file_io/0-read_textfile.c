#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t f, g, s;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	f = open(filename, O_RDONLY);
	g = read(f, buf, letters);
	s = write(STDOUT_FILENO, buf, g);

	if (f == -1 || g == -1 || s == -1 || s != g)
	{
		free(buf);
		return (0);
	}
}
