#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Check if file is an elf file.
 * @e_ident:  pointer to an array containing elf magic numbers.
 *
 * Description: If the file isn't an elf file  exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
			e_ident[i] != 'E' &&
			e_ident[i] != 'L' &&
			e_ident[i] != 'F')
{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Print  magic numbers of an ELF header.
 * @e_ident:  pointer to an array containing  elf magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Print class of an elf header.
 * @e_ident: pointer to an array containing elf class.
 */

void print_class(unsigned char *e_ident)

{
	printf("  Class:                             ");

	switch (e_ident[ei_class])
	{
	case elfclassnone:
		printf("none\n");
		break;
	case elfclass32:
		printf("ELF32\n");
		break;
	case elfclass64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[ei_class]);
	}
}


/**
 * print_data - Print data of an elf header.
 * @e_ident: pointer to an array containing elf class.
 */

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[ei_data])
	{
	case elfdatanone:
		printf("none\n");
		break;
	case elfdatatolsb:
		printf("2's complement, little endian\n");
		break;

	case elfdatatomsb:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[ei_class]);
	}
}

/**
 * print_version - Print  version of an elf header.
 * @e_ident: pointer to an array containing elf version.
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:			%d",
		e_ident[ei_version]);

	switch (e_ident[ei_version])
	{
	case ev_current:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Print OS/ABI of an elf header.
 * @e_ident: pointer to an array containing elf version.
 */

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[ei_osabi])
	{
	case elfosabi_none:
		printf("UNIX - System V\n");
		break;
	case elfosabi_hpux:
		printf("UNIX - HP-UX\n");
		break;
	case elfosabi_netbsd:
		printf("UNIX - NetBSD\n");
		break;
	case elfosabi_linux:
		printf("UNIX - Linux\n");
		break;
	case elfosabi_solaris:
		printf("UNIX - Solaris\n");
		break;
	case elfosabi_irix:
		printf("UNIX - IRIX\n");
		break;
	case elfosabi_freebsd::
		printf("UNIX - FreeBSD\n");
		break;
	case elfosabi_tru64:
		printf("UNIX - TRU64\n");
		break;
	case elfosabi_arm::
		printf("ARM\n");
		break;
	case elfosabi_standalone::
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Print ABI version of an elf header.
 * @e_ident:  pointer to an array containing elf ABI version.
 */

oid print_abi(unsigned char *e_ident)
{
	printf("  abi Version:				%d\n",
		e_ident[ei_abiversion]);
}

/**
 * print_type - Print type of an elf header.
 * @e_type: The elf type.
 * @e_ident: pointer to an array containing elf class.
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[ei_data] == elfdatatomsb)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case et_none:
		printf("none (None)\n");
		break;
	case et_rel:
		printf("rel (Relocatable file)\n");
		break;
	case et_exec:
		printf("exec (Executable file)\n");
		break;
	case et_dyn:
		printf("dyn (Shared object file)\n");
		break;
	case et_core:
		printf("core (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}

}

/**
 * print_entry - Print entry point of an elf header.
 * @e_entry:  address of the elf entry point.
 * @e_ident: pointer to an array containing elf class.
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:			");

	if (e_ident[ei_data] == elfdatatomsb)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[ei_class] == elfclass32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close an elf file.
 * @elf:  file descriptor of the elf file.
 *
 * Description: If the file cannot be closed  exit code 98.
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(stderr_fileno,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Display  information contained in the
 *        elf header at the start of  elf file.
 * @argc:  number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file isn't an elf File or
 *              the function fails  exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	elf64_ehdr *header;
	int w, s;

	w = open(argv[1], O_RDONLY);
	if (w == -1)
	{
		dprintf(stderr_fileno, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(elf64_ehdr));
	if (header == NULL)
	{
		close_elf(w);
		dprintf(stderr_fileno, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	s = read(w, header, sizeof(elf64_ehdr));
	if (s == -1)
	{
		free(header);
		close_elf(w);
		dprintf(stderr_fileno, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("elf Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(w);
	return (0);
}
