#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	char *buffer;
	ssize_t read_count;

	if (filename == NULL)
	return (0);

	fp = fopen(filename, "r");
	if (fp == NULL)
	return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(fp);
		return (0);
	}

	read_count = fread(buffer, sizeof(char), letters, fp);
	if (read_count == -1)
	{
		free(buffer);
		fclose(fp);
		return (0);
	}


	fwrite(buffer, sizeof(char), read_count, stdout);

	free(buffer);
	fclose(fp);

	return (read_count);
}
