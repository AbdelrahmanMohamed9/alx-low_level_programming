#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t mano, scto, dom;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	mano = open(filename, O_RDONLY);
	scto = read(mano, buffer, letters);
	dom = write(STDOUT_FILENO, buf, scto);

	if (mano == -1 || scto == -1 || dom == -1 || dom != scto)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(mano);

	return (dom);
}
