#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - this allocates 1024 bytes to a buffr.
 * @file: it's the name of the file buffr is storing chars for.
 *
 * Return: And this is a pointer to the new buffr.
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - this then closes the file descriptors.
 * @fd: The file descriptor being closed.
 */
void close_file(int fd)
{
	int d;

	d = close(fd);

	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - this fn copies contents of a file to another.
 * @argc: These are the number of arguments supplied to the exe.
 * @argv: this is simply an array of pointers to the arguments.
 *
 * Return: on success - 0.
 *
 * Description: If argument count is incorrect ? - exit code 97.
 * If file_from does not exist or cannot be read ? - exit code 98.
 * If file_to cannot be created / written to ? - exit code 99.
 * If file_to or file_from cannot be closed ? - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, rd, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		wr = write(to, buff, rd);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		rd = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
