#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_id);
void print_magic(unsigned char *e_id);
void print_class(unsigned char *e_id);
void print_data(unsigned char *e_id);
void print_version(unsigned char *e_id);
void print_abi(unsigned char *e_id);
void print_osabi(unsigned char *e_id);
void print_type(unsigned int e_tp, unsigned char *e_id);
void print_entry(unsigned long int e_ent, unsigned char *e_id);
void close_elf(int ce);

/**
 * check_elf - Check if file is an elf
 * @e_id:  pointer to an array
 *
 * Description: If the file isn't an elf file  exit code 98.
 */
void check_elf(unsigned char *e_id)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_id[indx] != 127 &&
		    e_id[indx] != 'E' &&
		    e_id[indx] != 'L' &&
		    e_id[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Print  magic numbers
 * @e_id:  pointer to  array containing  elf magic numbers
 *
 * Description: Magic numbers  separated by spaces.
 */
void print_magic(unsigned char *e_id)
{
	int indx;

	printf("  Magic:   ");

	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_id[indx]);

		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Print class of  elf
 * @e_id: pointer to array containing elf
 */
void print_class(unsigned char *e_id)
{
	printf("  Class:                             ");

	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * print_data - Print data of elf header.
 * @e_id: pointer to array containing elf
 */
void print_data(unsigned char *e_id)
{
	printf("  Data:                              ");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * print_version - Print version of elf header.
 * @e_id: pointer to array containing elf version
 */
void print_version(unsigned char *e_id)
{
	printf("  Version:                           %d",
	       e_id[EI_VERSION]);

	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Print OS/ABI of elf header.
 * @e_id: pointer to array containing elf version
 */
void print_osabi(unsigned char *e_id)
{
	printf("  OS/ABI:                            ");

	switch (e_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
}

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

	check_elf(hdr->e_id);
	printf("ELF Header:\n");
	print_magic(hdr->e_id);
	print_class(hdr->e_id);
	print_data(hdr->e_id);
	print_version(hdr->e_id);
	print_osabi(hdr->e_id);
	print_abi(hdr->e_id);
	print_type(hdr->e_tp, hgr->e_id);
	print_entry(hdr->e_ent, hdr->e_id);

	free(hdr);
	close_elf(x);
	return (0);
}
