#include "symbol_utils.h"
#include <stdio.h>
#include <elf.h>
#include <string.h>


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
// Function to determine the correct symbol type
char get_symbol_type(const Elf64_Sym *symbol, const Elf64_Shdr *section_headers, const Elf64_Ehdr *elf_header) {
    char symbol_type = '?';
    unsigned char bind = ELF64_ST_BIND(symbol->st_info);
    unsigned char type = ELF64_ST_TYPE(symbol->st_info);
    uint16_t shndx = symbol->st_shndx;

    if (bind == STB_GNU_UNIQUE) {
        symbol_type = 'u';
    } else if (type == STT_GNU_IFUNC) {
        symbol_type = 'i';
    } else if (bind == STB_WEAK) {
        symbol_type = (type == STT_OBJECT) ? ((shndx == SHN_UNDEF) ? 'v' : 'V') : ((shndx == SHN_UNDEF) ? 'w' : 'W');
    } else if (shndx == SHN_UNDEF) {
        symbol_type = 'U';
    } else if (shndx == SHN_ABS) {
        symbol_type = 'A';
    } else if (shndx == SHN_COMMON) {
        symbol_type = 'C';
    } else if (shndx < elf_header->e_shnum) {
        Elf64_Shdr section = section_headers[shndx];
        if (section.sh_type == SHT_NOBITS) {
            symbol_type = 'B';
        } else if (section.sh_flags & SHF_ALLOC) {
            if (section.sh_flags & SHF_EXECINSTR) {
                symbol_type = 'T';
            } else if (section.sh_flags & SHF_WRITE) {
                symbol_type = 'D';
            } else {
                symbol_type = 'R';
            }
        }
    }

    if (bind == STB_LOCAL && symbol_type != '?') {
        symbol_type += 32; // Convert to lowercase to indicate local binding
    }

    return symbol_type;
}

// Function to filter symbols based on criteria
int should_skip_symbol(const Elf64_Sym *symbol, const char *name) {
    if (name == NULL || *name == '\0') {
        return 1; // Skip symbols with no name
    }

    // Filter out startup-related symbols, you can add other symbols as necessary
    if (strcmp(name, "Scrt1.o") == 0 || strcmp(name, "crtstuff.c") == 0) {
        return 1;
    }

    // Skip symbols of type STT_FILE (like "test.c")
    unsigned char type = ELF64_ST_TYPE(symbol->st_info);
    if (type == STT_FILE) {
        return 1;
    }

    return 0;
}

// Function to create a symbol entry
t_symbol_info *create_symbol_info(const Elf64_Sym *symbol, const char *name, const Elf64_Shdr *section_headers, const Elf64_Ehdr *elf_header) {
    t_symbol_info *symbol_info = malloc(sizeof(t_symbol_info));
    if (!symbol_info) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    symbol_info->value = symbol->st_value;
    symbol_info->type = get_symbol_type(symbol, section_headers, elf_header);
    symbol_info->name = strdup(name);
    if (!symbol_info->name) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    return symbol_info;
}

// Function to compare symbols for sorting
int compare_symbols(const void *a, const void *b) {
    const t_symbol_info *symbol_a = (const t_symbol_info *)a;
    const t_symbol_info *symbol_b = (const t_symbol_info *)b;
    return strcmp(symbol_a->name, symbol_b->name);
}

// Function to process and add symbols to linked list
t_list *process_symbols(const char *file_in_memory, const Elf64_Shdr *symtab_header, const Elf64_Shdr *strtab_header, const Elf64_Ehdr *elf_header) {
    t_list *symbol_list = NULL;
    Elf64_Sym *symbol_table = parse_symbols(file_in_memory, symtab_header);
    int symbol_count = get_symbol_count(symtab_header);
    const char *strtab = file_in_memory + strtab_header->sh_offset;
    const Elf64_Shdr *section_headers = (Elf64_Shdr *)(file_in_memory + elf_header->e_shoff);

    for (int i = 0; i < symbol_count; i++) {
        Elf64_Sym *sym = &symbol_table[i];
        const char *name = get_symbol_name(strtab, sym);

        if (should_skip_symbol(sym, name)) {
            continue;
        }

        // Create a symbol entry and add it to the linked list
        t_symbol_info *symbol_info = create_symbol_info(sym, name, section_headers, elf_header);
        t_list *new_node = ft_lstnew(symbol_info);
        ft_lstadd_back(&symbol_list, new_node);
    }

    // Sort the linked list
    // ft_lstsort(symbol_list, compare_symbols, false);

    return symbol_list;
}

void print_symbol_list(t_list *symbol_list) {
    t_list *current = symbol_list;
    while (current) {
        t_symbol_info *symbol_info = (t_symbol_info *)current->content;
        if (symbol_info->value == 0)
            printf("                ");
        else
            printf("%016lx", symbol_info->value);
        printf(" %c %s\n", symbol_info->type, symbol_info->name);
        current = current->next;
    }
}

// ? TODO Create 2 functions that are called in main ? (process and sort_and_print)
void process_and_print_symbols(const char *file_in_memory, const Elf64_Shdr *symtab_header, const Elf64_Shdr *strtab_header, const Elf64_Ehdr *elf_header) {
    // Process symbols and add them to linked list
    t_list *symbol_list = process_symbols(file_in_memory, symtab_header, strtab_header, elf_header);

    // Sort
    ft_lstsort(symbol_list, compare_symbols, false);
    // Print the symbols
    print_symbol_list(symbol_list);

    // Clear the linked list
    ft_lstclear(&symbol_list, free);
}
