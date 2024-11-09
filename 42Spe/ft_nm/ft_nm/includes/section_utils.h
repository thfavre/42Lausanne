#ifndef SECTION_UTILS_H
#define SECTION_UTILS_H

#include <elf.h>

void	parse_sections(const char *file_in_memory, const Elf64_Ehdr *elf_header);

#endif // SECTION_UTILS_H
