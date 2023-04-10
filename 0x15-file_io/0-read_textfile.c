#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: number of letters actually read and printed, or 0 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buffer[1024];
	ssize_t lenr, lenw;
	ssize_t total = 0; /* Use ssize_t for signed integer comparison */

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	while ((lenr = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if (letters > 0 && total + lenr > (ssize_t)letters) /* Cast letters to ssize_t for comparison */
			lenr = (ssize_t)letters - total; /* Cast letters to ssize_t for arithmetic */
		lenw = write(STDOUT_FILENO, buffer, lenr);
		if (lenw != lenr)
		{
			close(fd);
			return (0);
		}
		total += lenw;
		if (letters > 0 && total >= (ssize_t)letters) /* Cast letters to ssize_t for comparison */
			break;
	}

	close(fd);
	return (total);
}
