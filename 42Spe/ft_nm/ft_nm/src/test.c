#include <stdio.h>
#include <unistd.h> // open
#include <fcntl.h> // open flages
#include <sys/stat.h>
#include <time.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>

#define PAGESIZE 4096

int main() {
	int fd = open("tests/a.out", O_RDONLY);
	if (fd == -1) {
		perror("open");
    	exit(EXIT_FAILURE);
	}

	struct stat sb;
	if (fstat(fd, &sb) == -1) {
		perror("couldn't get file size\n");
		close(fd);
    	exit(EXIT_FAILURE);
	}

	printf("I-node number:            %ld\n", (long) sb.st_ino);
	printf("Mode:                     %lo (octal)\n", (unsigned long) sb.st_mode);
	printf("Link count:               %ld\n", (long) sb.st_nlink);
	printf("Ownership:                UID=%ld   GID=%ld\n",(long) sb.st_uid, (long) sb.st_gid);
	printf("Preferred I/O block size: %ld bytes\n",(long) sb.st_blksize);
	printf("File size:                %lld bytes\n",(long long) sb.st_size);
	printf("Blocks allocated:         %lld\n",(long long) sb.st_blocks);
	printf("Last status change:       %s", ctime(&sb.st_ctime));
	printf("Last file access:         %s", ctime(&sb.st_atime));
	printf("Last file modification:   %s", ctime(&sb.st_mtime));

	char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ,
			MAP_PRIVATE,
			fd, 0); // 0 to start at the beginning of the file
	if (file_in_memory == MAP_FAILED) {
		perror("mmap");
		close(fd);
		exit(EXIT_FAILURE);
	}

	close(fd);


	Elf64_Ehdr *elf_header = (Elf64_Ehdr *)file_in_memory; // Executable and Linkable Format
		// 		typedef struct {
		//     unsigned char   e_ident[16];    // ELF Identification
		//     uint16_t        e_type;         // Object file type
		//     uint16_t        e_machine;      // Machine type
		//     uint32_t        e_version;      // Object file version
		//     uint64_t        e_entry;        // Entry point address
		//     uint64_t        e_phoff;        // Program header offset
		//     uint64_t        e_shoff;        // Section header offset
		//     uint32_t        e_flags;        // Processor-specific flags
		//     uint16_t        e_ehsize;       // ELF header size in bytes
		//     uint16_t        e_phentsize;    // Program header entry size
		//     uint16_t        e_phnum;        // Number of program header entries
		//     uint16_t        e_shentsize;    // Section header entry size
		//     uint16_t        e_shnum;        // Number of section header entries
		//     uint16_t        e_shstrndx;     // Section header string table index
		// } Elf64_Ehdr;
	// Verify that the file is an ELF file by checking the magic number.
	if (elf_header->e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header->e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header->e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header->e_ident[EI_MAG3] != ELFMAG3) {
		fprintf(stderr, "Error: Not an ELF file\n");
		munmap(file_in_memory, sb.st_size);
		exit(EXIT_FAILURE);
	}

	if (elf_header->e_ident[EI_CLASS] == ELFCLASS64) {
		printf("This is a 64-bit ELF file\n");
		// You can use the Elf64_Ehdr structure here
	} else if (elf_header->e_ident[EI_CLASS] == ELFCLASS32) {
		printf("This is a 32-bit ELF file\n");
		// Cast the map pointer to Elf32_Ehdr if necessary
		Elf32_Ehdr *elf_header_32 = (Elf32_Ehdr *)file_in_memory;
		// Access fields using elf_header_32...
	} else {
		fprintf(stderr, "Error: Unknown ELF class\n");
		munmap(file_in_memory, sb.st_size);
		exit(EXIT_FAILURE);
	}

	// Check the ELF file type using e_type
    switch (elf_header->e_type) {
        case ET_REL: // should parse .symtab (if available)
            printf("This is a Relocatable file (object file).\n");
            break;
        case ET_EXEC: // should parse .symtab (if available) or .dynsym if use dynamic linking.
            printf("This is an Executable file.\n");
            break;
        case ET_DYN: // should parse .dynsym
            printf("This is a Shared object file (shared library).\n");
            break;
        case ET_CORE:
            printf("This is a Core dump file.\n");
            break;
        default:
            printf("Unknown ELF file type.\n");
            break;
    }


	// Get the section header table information
    Elf64_Off shoff = elf_header->e_shoff;      // Offset of section header table
    uint16_t shnum = elf_header->e_shnum;       // Number of section headers
    // uint16_t shentsize = elf_header->e_shentsize; // Size of each section header entry

	// Pointer to the start of the section header table
    Elf64_Shdr *section_headers = (Elf64_Shdr *)((char *)file_in_memory + shoff);

	// Get the section header string table index
    uint16_t shstrndx = elf_header->e_shstrndx;

	Elf64_Shdr *strtab_header = NULL;
    Elf64_Shdr *symtab_header = NULL;

	// Locate the symbol table and string table sections
	 for (int i = 0; i < shnum; i++) {
        if (section_headers[i].sh_type == SHT_SYMTAB) {
            symtab_header = &section_headers[i];
        } else if (section_headers[i].sh_type == SHT_STRTAB) {
			// Ensure this is the correct string table (not the section header string table)
			if (strcmp((char *)file_in_memory + section_headers[elf_header->e_shstrndx].sh_offset + section_headers[i].sh_name, ".strtab") == 0) {
				strtab_header = &section_headers[i];
    		}
		}
    }

	if (!symtab_header || !strtab_header) {
        fprintf(stderr, "Error: Could not find symbol table or string table\n");
        munmap(file_in_memory, sb.st_size);
        exit(EXIT_FAILURE);
    }


	// Get pointers to the symbol table and string table
    Elf64_Sym *symbol_table = (Elf64_Sym *)((char *)file_in_memory + symtab_header->sh_offset);
    const char *strtab = (const char *)file_in_memory + strtab_header->sh_offset;

    int symbol_count = symtab_header->sh_size / symtab_header->sh_entsize;

    // Iterate over symbols and print their information
    for (int i = 0; i < symbol_count; i++) {
        Elf64_Sym *sym = &symbol_table[i];

        // Get symbol name
        const char *name = strtab + sym->st_name;
        if (name == NULL || *name == '\0') {
            continue; // Skip symbols with no name
        }

        // Print symbol value (address)
		if (sym->st_value != 0)
        	printf("%016lx ", sym->st_value);
		else {
			// Undefined symbol
			printf("                 U %s\n", name);
			continue;
		}

        // Print symbol type
        unsigned char type = ELF64_ST_TYPE(sym->st_info);
        switch (type) {
            case STT_NOTYPE: printf(" "); break;
            case STT_OBJECT: printf("D "); break;  // Data object
            case STT_FUNC:   printf("T "); break;  // Function
            case STT_SECTION: printf("S "); break; // Section
            case STT_FILE:   printf("F "); break;  // File
            default:         printf("? "); break;  // Unknown type
        }

        // Print symbol name
        printf("%s\n", name);
    }

	if (munmap(file_in_memory, sb.st_size) == -1) {
    	perror("munmap");
    	exit(EXIT_FAILURE);
	}

}
