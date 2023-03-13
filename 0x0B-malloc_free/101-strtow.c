#include <stdlib.h>
#include "main.h"

void util(char **, char *);
void create_word(char **, char *, int, int, int);

/**
* strtow - splits a string into words.
* @str: the string
*
* Return: returns a pointer to an array of strings (words)
*/
char **strtow(char *str)
{
	int i, flag, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
	return (NULL);

	i = flag = len = 0;
	while (str[i])
	{
	if (flag == 0 && str[i] != ' ')
	flag = 1;
	if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
	{
	flag = 0;
	len++;
	}
	i++;
	}

	len += flag == 1 ? 1 : 0;
	if (len == 0)
	return (NULL);

	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
	return (NULL);

	util(words, str);
	words[len] = NULL;
	return (words);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);

				while (start < end)
				*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}
