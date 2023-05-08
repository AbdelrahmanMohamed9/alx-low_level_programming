#include "elf_header.h"
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



/**
 * print_abi - Print ABI version of elf header
 * @e_id: the pointer to array containing elf ABI version.
 */
void print_abi(unsigned char *e_id)
{
	printf("  ABI Version:                       %d\n",
	       e_id[EI_ABIVERSION]);
}

/**
 * print_type - Print type of  elf header.
 * @e_tp:  elf type.
 * @e_id:the pointer to an array containing elf class.
 */
void print_type(unsigned int e_tp, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_tp >>= 8;

	printf("  Type:                              ");

	switch (e_tp)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_tp);
	}
}

/**
 * print_entry - Print entry point of elf header
 * @e_ent: the address of  elf entry point.
 * @e_id:the pointer to  array containing elf class.
 */
void print_entry(unsigned long int e_ent, unsigned char *e_id)
{
	printf("  Entry point address:               ");

	if (e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_ent = ((e_ent << 8) & 0xFF00FF00) |
			  ((e_ent >> 8) & 0xFF00FF);
		e_ent = (e_ent << 16) | (e_ent >> 16);
	}

	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_ent);

	else
		printf("%#lx\n", e_ent);
}

/**
 * close_elf - Close elf file
 * @ce :the file descriptor of elf file
 *
 * Description: If the file cannot be closed  exit code 98.
 */
void close_elf(int ce)
{
	if (close(ce) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", ce);
		exit(98);
	}
}

/**
 * main - Display  information contained in the
 *        elf header at the start of  elf file.
 * @argc:  number of arguments supplied to program.
 * @argv: the array of pointers to arguments.
 *
 * Return: 0 on success.
 *
 * Description: If  file isn't  elf File or
 *               function fails  exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *hdr;
	int x, v;

	x = open(argv[1], O_RDONLY);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	hdr = malloc(sizeof(Elf64_Ehdr));
	if (hdr == NULL)
	{
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	v = read(x, hdr, sizeof(Elf64_Ehdr));
	if (v == -1)
	{
		free(hdr);
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	return (0);
}
