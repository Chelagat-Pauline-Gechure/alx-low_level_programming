#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#include <string.h>

/**
 * create_file - creates a file with the given name
 * and writes text content to it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t lenw;
	mode_t mode = S_IRUSR | S_IWUSR; /* rw------- */

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		lenw = write(fd, text_content, strlen(text_content));
		if (lenw == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
