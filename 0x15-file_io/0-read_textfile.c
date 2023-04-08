#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t num_read, num_written;
	FILE *file;
	char *buf;

	if (filename == NULL)
	return (0);

	file = fopen(filename, "r");
	if (file == NULL)
	return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
	fclose(file);
	return (0);
	}

	num_read = fread(buf, sizeof(char), letters, file);
	if (num_read == 0)
	{
	free(buf);
	fclose(file);
	return (0);
	}

	num_written = fwrite(buf, sizeof(char), num_read, stdout);
	if (num_written == 0 || num_written != num_read)
	{
	free(buf);
	fclose(file);
	return (0);
	}

	free(buf);
	fclose(file);
	return (num_written);
}
