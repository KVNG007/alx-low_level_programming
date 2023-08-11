#include "main.h"

/**
 * append_text_to_file - this appends a text at the end of the file.
 * @filename: this is a pointer indicating the name of the file.
 * @text_content: this is the string to be added to the end of the file.
 *
 * Return: -1 If the function fails or the filename is NULL.
 *         and If file no exist user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int j, t, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	j = open(filename, O_WRONLY | O_APPEND);
	t = write(j, text_content, length);

	if (j == -1 || t == -1)
		return (-1);

	close(j);

	return (1);
}
