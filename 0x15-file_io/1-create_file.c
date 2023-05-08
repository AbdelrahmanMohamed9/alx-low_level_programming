#include "main.h"

/**
 * create_file - creates a file with the given filename and writes
 * the contents of text_content to it
 *
 * @fn: the name of the file to create
 * @tx_con: the content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *fn, char *tx_con)
{
	int file_descriptor, write_count = 0, length = 0;

	if (fn == NULL)
		return (-1);

	file_descriptor = open(fn, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (tx_con != NULL)
	{
		while (tx_con[length] != '\0')
			length++;

		write_count = write(file_descriptor, tx_con, length);
		if (write_count != length)
			return (-1);
	}

	close(file_descriptor);
	return (1);
}
