#include "elf_utils.h"
#include <stdio.h>

int		is_elf_file(const char *file_in_memory) {
	const unsigned char *e_ident = (const unsigned char *)file_in_memory;
	// for (int i=0; i< 10; i++) {
	// 	printf("%c ", e_ident[i]);
	// }
	return (e_ident[EI_MAG0] != ELFMAG0 ||
		e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 ||
		e_ident[EI_MAG3] != ELFMAG3);
}

