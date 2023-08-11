#include "main.h"

/**
 * create_file - this simply creates a file.
 * @filename: it is a pointer to the file to be created
 * @text_content: it is a pointer to a string to write into the file.
 *
 * Return: -1 If the function fails.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int gf, w, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	gf = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(gf, text_content, length);

	if (gf == -1 || w == -1)
		return (-1);

	close(gf);

	return (1);
}
