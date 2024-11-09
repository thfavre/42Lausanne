#ifndef ELF_PARSING_UTILS_H
#define ELF_PARSING_UTILS_H

#include <elf.h>

// Function to parse the ELF header
void parse_elf_header(const Elf64_Ehdr *elf_header);

// Function to get the section headers from the ELF file
Elf64_Shdr *get_section_headers(const char *file_in_memory, const Elf64_Ehdr *elf_header);

// Function to locate the symbol table section header
const Elf64_Shdr *locate_symbol_table(const Elf64_Shdr *section_headers, int shnum);

// Function to locate the string table section header
const Elf64_Shdr *locate_string_table(const char *file_in_memory, const Elf64_Shdr *section_headers, int shnum, int shstrndx);

#endif // ELF_PARSING_UTILS_H
