#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - function that reads a text file
 * & prints the output to the POSIX standard output
 * @filename: the name of the file
 * @letters: number of letters to read & print
 * Return: 1 on success else 0
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t open_file, read_file, write_file;
	char *text_buffer;

	if (!filename)
	{
	return (0);
	}

	text_buffer = malloc(sizeof(char) * letters);

	if (!text_buffer) /* Checks whether the allocation was successful or not*/
	{
	return (0);
	}

	/*Open the file*/
	open_file = open(filename, O_RDONLY);

	/* Read text from the file*/
	read_file = read(open_file, text_buffer, letters);

	/* Write file content to standard output*/
	write_file = write(STDOUT_FILENO, text_buffer, read_file);
	/* Error handling*/
	if (open_file == -1 || read_file == -1)
	{
	free(text_buffer);
	return (0);
	}

	if (write_file == -1 || write_file != read_file)
	{
	free(text_buffer);
	return (0);
	}

	free(text_buffer);
	close(open_file);
	return (write_file);
}
