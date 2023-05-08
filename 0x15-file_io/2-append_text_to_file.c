#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 *
 * @fn: the name of the file
 * @tx_con: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *fn, char *tx_con)
{
	int file_descriptor, write_count = 0, length = 0;

	if (fn == NULL)
		return (-1);

	file_descriptor = open(fn, O_WRONLY | O_APPEND);

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
