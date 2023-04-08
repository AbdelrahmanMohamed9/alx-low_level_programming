#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 *
 * @filename: the name of the file
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_count = 0, length = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

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
