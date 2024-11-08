#include <stdio.h>
#include <unistd.h> // open
#include <fcntl.h> // open flages
#include <sys/stat.h>
#include <time.h>
#include <sys/mman.h>


#define PAGESIZE 4096

int main() {
  int fd = open("tests/a.out", O_RDONLY);
  printf("hello lil world!%d\n", fd);
  struct stat sb;
  fstat(fd, &sb);
  close(fd);

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

  void *mmap(NULL, size_t length, int prot, int flags,
                  int fd, off_t offset);
}
