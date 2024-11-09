#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int			open_file(const char *filename);
struct stat	get_file_stats(int fd);
char		*map_file_to_memory(int fd, size_t file_size);
void		unmap_file(char *file_in_memory, size_t file_size);

#endif // FILE_UTILS_H
