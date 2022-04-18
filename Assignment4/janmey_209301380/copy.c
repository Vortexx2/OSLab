#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char buffer[100];
  long int n1;

  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0700);

  if (fd1 == -1 || fd2 == -1) {
    perror("Error occurred");
    exit(1);
  }

  while ((n1 = read(fd1, buffer, 100)) > 0) {
    if (write(fd2, buffer, n1) == -1) {
      perror("Error while writing");
      exit(3);
    }
  }

  if (n1 == -1) {
    perror("Error while writing");
    exit(3);
  }

  close(fd1);
  close(fd2);
  exit(0);

  return 0;
}
