#ifndef ELF_UTILS_H
#define ELF_UTILS_H

#include <elf.h>

int		is_elf_file(const char *file_in_memory);
// void	parse_elf_header(const Elf64_Ehdr *elf_header);

#endif // ELF_UTILS_H
