#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	open_file(const char *filename) {
	int	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		ft_fprintf(STDERR_FILENO, "nm: '%s': No such file\n", filename);
    	exit(EXIT_FAILURE);
	}
}

struct stat	get_file_stats(int fd) {
	struct stat sb;
	if (fstat(fd, &sb) == -1) {
		perror("fstat\n");
		close(fd);
    	exit(EXIT_FAILURE);
	}
	return (sb);
}

char		*map_file_to_memory(int fd, size_t file_size) {
	char *file_in_memory = mmap(NULL, file_size, PROT_READ,
			MAP_PRIVATE, fd, 0); // 0 to start at the beginning of the file
	if (file_in_memory == MAP_FAILED) {
		perror("mmap");
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (file_in_memory);
}

void		unmap_file(char *file_in_memory, size_t file_size) {
	if (munmap(file_in_memory, file_size) == -1) {
    	perror("munmap");
    	exit(EXIT_FAILURE);
	}
}
