#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * display_error - Displays an error message and exits with a status code.
 * @msg: The error message to display.
 * @exit_code: The exit status code.
 */
void display_error(char *msg, int exit_code)
{
	dprintf(2, "%s\n", msg);
       	exit(exit_code);
}

/**
 * read_elf_header - Reads and displays the ELF header information.
 * @fd: The file descriptor of the ELF file.
 */
void read_elf_header(int fd)
{
	Elf64_Ehdr header;
	ssize_t bytes_read;

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1 || bytes_read != sizeof(header))
		display_error("Error: Unable to read ELF header", 98);

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
		printf("%02x%c", header.e_ident[i], i < 15 ? ' ' : '\n');

	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %02x>\n", header.e_ident[EI_CLASS]);
	}

	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %02x>\n", header.e_ident[EI_DATA]);
    }

    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    default:
        printf("<unknown: %02x>\n", header.e_ident[EI_OSABI]);
    }

    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header.e_type)
    {
    case ET_NONE:
        printf("NONE (Unknown type)\n");
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
        printf("<unknown: %04x>\n", header.e_type);
    }

    printf("  Entry point address:               0x%lx\n", header.e_entry);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an exit status code on failure.
 */
int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
        display_error("Usage: elf_header elf_filename", 98);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        display_error("Error: Can't open ELF file", 98);

    read_elf_header(fd);

    if (close(fd) == -1)
        display_error("Error: Can't close file descriptor", 98);

    return (0);
}

