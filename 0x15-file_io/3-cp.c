#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *filename);
void close_file_descriptor(int file_descriptor);

/**
 * allocate_buffer - copies the content of a file to another file.
 * @filename: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *allocate_buffer(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int read_result;

	read_result = close(fd);

	if (read_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of parameters supplied to the program.
 * @argv: An array of pointers to the parameters
 *
 * Return: 0 on success.
 *
 * Description: Incorrect parameter - exit code 97.
 *              file does not exist or cant be read - exit code 98.
 *              file cannot be created or written to - exit code 99.
 *             file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, readfile, writefile;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	readfile = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || readfile == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		writefile = write(file_to, buffer, readfile);
		if (file_to == -1 || writefile == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		readfile = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (readfile > 0);

	free(buffer);
	close_file_descriptor(file_from);
	close_file_descriptor(file_to);

	return (0);
}

