#include "elf_utils.h"
#include "elf_parsing_utils.h"
#include "file_utils.h"
#include "symbol_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include "libft.h"
#include "parsing.h"



int main(int argc, char **argv) {

	// Step 0: get the agruments
	char	*file_path;
    t_list *files = NULL; // TODO free
    t_options options = {0};

    parse_args(++argv, &options, &files);
    // printf("The path is '%s'\n", file_path);
    file_path = files[0].content;

	// Step 1: Open and map the file
    int fd = open_file(file_path);
    struct stat sb = get_file_stats(fd);
    char *file_in_memory = map_file_to_memory(fd, sb.st_size);
    close(fd);

    // Step 2: Validate the ELF file
    if (!is_elf_file(file_in_memory)) {
        ft_fprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        unmap_file(file_in_memory, sb.st_size);
        return EXIT_FAILURE;
    }

    // Step 3: Parse ELF header
    Elf64_Ehdr *elf_header = (Elf64_Ehdr *)file_in_memory;
    parse_elf_header(elf_header);

    // Step 4: Get the section headers
    Elf64_Shdr *section_headers = get_section_headers(file_in_memory, elf_header);

    // Step 5: Locate symbol table and string table sections
    const Elf64_Shdr *symtab_header = locate_symbol_table(section_headers, elf_header->e_shnum);
    const Elf64_Shdr *strtab_header = locate_string_table(file_in_memory, section_headers, elf_header->e_shnum, elf_header->e_shstrndx);

    if (symtab_header && strtab_header) {
        // // Step 6: Print symbols using the print_symbols function
        // print_symbols(file_in_memory, symtab_header, strtab_header, elf_header);
        // Step 6: Process symbols and add them to linked list
        t_list *symbol_list = process_symbols(file_in_memory, symtab_header, strtab_header, elf_header);

        // Step 6-8: Process and print symbols
        process_and_print_symbols(file_in_memory, symtab_header, strtab_header, elf_header);

    } else {
        fprintf(stderr, "Error: Could not find symbol table or string table\n");
    }

    // Step 9: Unmap the file
    unmap_file(file_in_memory, sb.st_size);
}
