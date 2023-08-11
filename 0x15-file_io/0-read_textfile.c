#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads the text file print out to STDOUT.
 * @filename: the text file which is being read
 * @letters: the no of letters which are to be read to STDOUT.
 * Return: w- The actual no of bytes that was read and printed
 *        0 if the function fails or the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t gf;
	ssize_t w;
	ssize_t txt;

	gf = open(filename, O_RDONLY);
	if (gf == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	txt = read(gf, buff, letters);
	w = write(STDOUT_FILENO, buff, txt);

	free(buff);
	close(gf);
	return (w);
}
