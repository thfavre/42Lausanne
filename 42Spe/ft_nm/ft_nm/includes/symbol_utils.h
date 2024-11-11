#ifndef SYMBOL_UTILS_H
#define SYMBOL_UTILS_H

#include <elf.h>
#include "libft.h"

Elf64_Sym	*parse_symbols(const char *file_in_memory, const Elf64_Shdr *symtab_header);
int			get_symbol_count(const Elf64_Shdr *symtab_header);
const char	*get_symbol_name(const char *strtab, Elf64_Sym *symbol);
void 		print_symbol(const Elf64_Sym *symbol, const char *name, const Elf64_Shdr *section_headers, const Elf64_Ehdr *elf_header);
t_list		*process_symbols(const char *file_in_memory, const Elf64_Shdr *symtab_header, const Elf64_Shdr *strtab_header, const Elf64_Ehdr *elf_header);
#endif // SYMBOL_UTILS_H
