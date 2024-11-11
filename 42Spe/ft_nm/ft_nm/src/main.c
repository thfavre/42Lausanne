#include "elf_utils.h"
#include "elf_parsing_utils.h"
#include "file_utils.h"
#include "symbol_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include "libft.h"



int main(int argc, char **argv) {

	// Step 0: get the agruments
	char	*file_path;
	if (argc == 1)
		file_path = "tests/a.out"; // TODO change to ./a.out
	else if (argc == 2)
		file_path = argv[1];
	else {
		fprintf(stderr, "usage : ./ft_nm file_path (optional)");
		exit(EXIT_FAILURE);
	}
    printf("The path is %s\n", file_path);


	// Step 1: Open and map the file
    int fd = open_file(argv[1]);
    struct stat sb = get_file_stats(fd);
    char *file_in_memory = map_file_to_memory(fd, sb.st_size);
    close(fd);

    // Step 2: Validate the ELF file
    if (!is_elf_file(file_in_memory)) {
        fprintf(stderr, "Error: Not an ELF file\n");
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

        // Step 7: Iterate over the list and print the symbols
        ft_lstiter(symbol_list, (void (*)(void *))puts);

        // Step 8: Clear the linked list
        ft_lstclear(&symbol_list, free);
    } else {
        fprintf(stderr, "Error: Could not find symbol table or string table\n");
    }

    // Step 7: Unmap the file
    unmap_file(file_in_memory, sb.st_size);
}
