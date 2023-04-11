#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *allocate_buffer(char *file);
void close_fd(int fd);

/**
 * allocate_buffer - Allocates memory for a buffer.
 * @file: The name of the file for which buffer is allocated.
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *allocate_buffer(char *file)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't allocate buffer for %s\n", file);
        exit(99);
    }

    return (buffer);
}

/**
 * close_fd - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_fd(int fd)
{
    int result;

    result = close(fd);

    if (result == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of parameters supplied to the program.
 * @argv: An array of pointers to the parameters.
 *
 * Return: 0 on success.
 *
 * Description: Incorrect number of parameters - exit code 97.
 *              Source file does not exist or cannot be read - exit code 98.
 *              Destination file cannot be created or written to - exit code 99.
 *              Source or destination file cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
    int src_file, dest_file, read_result, write_result;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: my_cp file_from file_to\n");
        exit(97);
    }

    buffer = allocate_buffer(argv[2]);
    src_file = open(argv[1], O_RDONLY);
    read_result = read(src_file, buffer, 1024);
    dest_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do {
        if (src_file == -1 || read_result == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't read from file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        write_result = write(dest_file, buffer, read_result);
        if (dest_file == -1 || write_result == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        read_result = read(src_file, buffer, 1024);
        dest_file = open(argv[2], O_WRONLY | O_APPEND);

    } while (read_result > 0);

    free(buffer);
    close_fd(src_file);
    close_fd(dest_file);

    return (0);
}
