#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_APPEND, 0700);

  if (fd1 == -1 || fd2 == -1) {
    perror("Error occurred in opening file");
    exit(1);
  }

  int buffSize = 100;
  char buffer[buffSize];
  long int n;

  while ((n = read(fd1, buffer, buffSize)) > 0) {
    if (write(fd2, buffer, n) == -1) {
      perror("Error occurred while writing");
      exit(3);
    }
  }

  if (n == -1) {
    perror("Error occurred while writing");
    exit(3);
  }

  close(fd1);
  close(fd2);
  return 0;
}
