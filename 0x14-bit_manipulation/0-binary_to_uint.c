#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string containing the binary number.
 *
 * Return: The converted number, or 0
 * if there is an invalid character in b or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;	/* The result of the conversion */
	int i = 0;	/* Index for iterating through the string */

	/* If b is NULL, return 0 */
	if (b == NULL)
		return (0);

	/* Iterate through the string */
	while (b[i] != '\0')
	{
	/* Check if the current character is not '0' or '1' */
	if (b[i] != '0' && b[i] != '1')
		return (0);

	/* Shift the result left and add the value of the current bit */
	result = (result << 1) + (b[i] - '0');

	/* Move to the next character in the string */
	i++;
	}

	/* Return the final result */
	return (result);
}
