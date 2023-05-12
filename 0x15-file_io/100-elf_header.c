#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

void is_file_elf(unsigned char *e_ident);
void print_elf_magic_number(unsigned char *e_ident);
void print_file_class(unsigned char *e_ident);
void print_data_encoding(unsigned char *e_ident);
void print_file_version(unsigned char *e_ident);
void print_file_abi(unsigned char *e_ident);
void print__ile_osabi(unsigned char *e_ident);
void print_file_type(unsigned int e_type, unsigned char *e_ident);
void print_file_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);
