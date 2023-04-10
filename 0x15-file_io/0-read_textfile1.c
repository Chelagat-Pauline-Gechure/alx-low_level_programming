#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: number of letters actually read and printed, or 0 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	char buffer[1024];
	ssize_t lenr, lenw, total = 0;

	while ((lenr = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if (letters > 0 && total + lenr > letters)
			lenr = letters - total;
		lenw = write(STDOUT_FILENO, buffer, lenr);
		if (lenw != lenr)
		{
			close(fd);
			return (0);
		}
		total += lenw;
		if (letters > 0 && total >= letters)
			break;
	}

	close(fd);
	return (total);
}
