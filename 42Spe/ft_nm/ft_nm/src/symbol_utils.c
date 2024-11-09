#include "symbol_utils.h"
#include <stdio.h>
#include <elf.h>

// Function to parse the symbol table
Elf64_Sym *parse_symbols(const char *file_in_memory, const Elf64_Shdr *symtab_header) {
    // Pointer to the symbol table
    Elf64_Sym *symbol_table = (Elf64_Sym *)(file_in_memory + symtab_header->sh_offset);
    return symbol_table;
}

// Function to get the symbol count from the symbol table header
int get_symbol_count(const Elf64_Shdr *symtab_header) {
    return symtab_header->sh_size / symtab_header->sh_entsize;
}

// Function to get the symbol name
const char *get_symbol_name(const char *strtab, Elf64_Sym *symbol) {
    return strtab + symbol->st_name;
}

// Function to print a single symbol
void print_symbol(const Elf64_Sym *symbol, const char *name) {
    if (symbol->st_shndx == SHN_UNDEF) {
        printf("                 U %s\n", name);
    } else {
        printf("%016lx ", symbol->st_value);

        // Print symbol type
        unsigned char type = ELF64_ST_TYPE(symbol->st_info);
        switch (type) {
            case STT_OBJECT: printf("D "); break;  // Data object
            case STT_FUNC:   printf("T "); break;  // Function
            default:         printf("? "); break;  // Unknown type
        }
        printf("%s\n", name);
    }
}

// Function to print the symbols
void print_symbols(const char *file_in_memory, const Elf64_Shdr *symtab_header, const Elf64_Shdr *strtab_header) {
    // Parse symbols using the parse_symbols function
    Elf64_Sym *symbol_table = parse_symbols(file_in_memory, symtab_header);

    // Calculate number of symbols in the symbol table
    int symbol_count = get_symbol_count(symtab_header);

    // Pointer to the string table
    const char *strtab = file_in_memory + strtab_header->sh_offset;

    for (int i = 0; i < symbol_count; i++) {
        Elf64_Sym *sym = &symbol_table[i];
        const char *name = get_symbol_name(strtab, sym);

        if (name == NULL || *name == '\0') {
            continue; // Skip symbols with no name
        }

        // Print the symbol
        print_symbol(sym, name);
    }
}
