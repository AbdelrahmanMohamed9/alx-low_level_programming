#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * f4 - determine the maximum value.
 * @usrn: login name
 * @len: number of characters in the username.
 * Return: the maximum value.
 */
int f4(char *usrn, int len)
{
	int cch;
	int vvh;
	unsigned int rd_number;

	cch = *usrn;
	for (vvh = 0; vvh < len; vvh++)
		if (vvh < usrn[vvh])
			cch = usrn[vvh];

	srand(cch ^ 14);
	rd_number = rand();

	return (rd_number & 63);
}

/**
 * f5 -  Unicode code of each character in the username.
 * @usrn: login name.
 * @len: number of characters in the username.
 * Return: esulting value after multiplying the character.
 */
int f5(char *usrn, int len)
{
	int cch;
	int vvh;

	cch = 0;
	for (vvh = 0; vvh < len; vvh++)
		cch = cch + usrn[vvh] * usrn[vvh];

	return (((unsigned int)cch ^ 239) & 63);
}

/**
 * f6 - produce a random character.
 * @usrn: login name.
 * Return: a randomly selected character.
 */
int f6(char *usrn)
{
	int cch;
	int vvh;

	cch = 0;
	for (vvh = 0; vvh < *usrn; vvh++)
		cch = rand();

	return (((unsigned int)cch ^ 229) & 63);
}

/**
 * main - starting point.
 *
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: unchanging value of 0.
 */
int main(int argc, char **argv)
{
	char kg[7];
	int ln, cch, vvh;
	long ap[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	for (ln = 0; argv[1][ln]; ln++)
		;

	kg[0] = ((char *)ap)[(ln ^ 59) & 63];
	cch = 0;
	for (vvh = 0; vvh < ln; vvh++)
		cch = cch + argv[1][vvh];

	kg[1] = ((char *)ap)[(cch ^ 79) & 63];
	cch = 1;
	for (vvh = 0; vvh < ln; vvh++)
		cch = argv[1][vvh] * cch;

	kg[2] = ((char *)ap)[(cch ^ 85) & 63];
	kg[3] = ((char *)ap)[f4(argv[1], ln)];
	kg[4] = ((char *)ap)[f5(argv[1], ln)];
	kg[5] = ((char *)ap)[f6(argv[1])];
	kg[6] = '\0';
	for (cch = 0; kg[cch]; cch++)
		printf("%c", kg[cch]);
	return (0);
}
