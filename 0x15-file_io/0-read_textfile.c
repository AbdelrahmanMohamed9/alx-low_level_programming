#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read the text file and prints it
 * @fn:  pointer to name of the file
 * @let: The number of letters
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *fn, size_t let)
{
	ssize_t p, e, t;
	char *buf;

	if (fn == NULL)
		return (0);

	buf = malloc(sizeof(char) * let);
	if (buf == NULL)
		return (0);

	p = open(fn, O_RDONLY);
	e = read(p, buf, let);
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
