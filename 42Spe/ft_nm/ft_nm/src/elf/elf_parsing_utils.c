#include "elf_parsing_utils.h"
#include <stdio.h>
#include <string.h>
#include <elf.h>

// Function to parse the ELF header
void parse_elf_header(const Elf64_Ehdr *elf_header) {
    // ? TODO
    return ;
    if (elf_header->e_ident[EI_CLASS] == ELFCLASS64) {
        printf("This is a 64-bit ELF file\n");
    } else if (elf_header->e_ident[EI_CLASS] == ELFCLASS32) {
        printf("This is a 32-bit ELF file\n");
    } else {
        printf("Unknown ELF class\n");
    }

    switch (elf_header->e_type) {
        case ET_REL: printf("This is a Relocatable file (object file).\n"); break;
        case ET_EXEC: printf("This is an Executable file.\n"); break;
        case ET_DYN: printf("This is a Shared object file (shared library).\n"); break;
        case ET_CORE: printf("This is a Core dump file.\n"); break;
        default: printf("Unknown ELF file type.\n"); break;
    }
}


// Function to get the section headers from the ELF file
Elf64_Shdr *get_section_headers(const char *file_in_memory, const Elf64_Ehdr *elf_header) {
    return (Elf64_Shdr *)(file_in_memory + elf_header->e_shoff);
}

// Function to locate the symbol table section header
const Elf64_Shdr *locate_symbol_table(const Elf64_Shdr *section_headers, int shnum) {
    for (int i = 0; i < shnum; i++) {
        if (section_headers[i].sh_type == SHT_SYMTAB) {
            return &section_headers[i];
        }
    }
    return NULL;
}

// Function to locate the string table section header
const Elf64_Shdr *locate_string_table(const char *file_in_memory, const Elf64_Shdr *section_headers, int shnum, int shstrndx) {
    for (int i = 0; i < shnum; i++) {
        if (section_headers[i].sh_type == SHT_STRTAB) {
            const char *section_name = (char *)(file_in_memory + section_headers[shstrndx].sh_offset + section_headers[i].sh_name);
            if (strcmp(section_name, ".strtab") == 0) {
                return &section_headers[i];
            }
        }
    }
    return NULL;
}
