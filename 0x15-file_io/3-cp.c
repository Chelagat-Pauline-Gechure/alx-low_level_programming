#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_error_and_exit(int exit_code, const char* format, const char* arg) {
    dprintf(STDERR_FILENO, format, arg);
    exit(exit_code);
}

int main(int argc, char* argv[]) {
    int fd_from, fd_to;
    ssize_t read_bytes, write_bytes;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        print_error_and_exit(97, "Usage: %s file_from file_to\n", argv[0]);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        print_error_and_exit(99, "Error: Can't write to file %s\n", argv[2]);
    }

    while ((read_bytes = read(fd_from, buffer, BUF_SIZE)) > 0) {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes) {
            print_error_and_exit(99, "Error: Can't write to file %s\n", argv[2]);
        }
    }
    if (read_bytes == -1) {
        print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
    }

    if (close(fd_from) == -1 || close(fd_to) == -1) {
        print_error_and_exit(100, "Error: Can't close fd %d\n", errno);
    }

    return 0;
}
