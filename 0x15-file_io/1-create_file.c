#include "main.h"

/**
 * create_file - creates a file with the given filename and writes
 * the contents of text_content to it
 *
 * @filename: the name of the file to create
 * @text_content: the content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_count = 0, length = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
			length++;

		write_count = write(file_descriptor, text_content, length);
		if (write_count != length)
			return (-1);
	}

	close(file_descriptor);
	return (1);
}
