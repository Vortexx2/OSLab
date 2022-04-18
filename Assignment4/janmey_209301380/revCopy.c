#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Invalid no. of arguments provided");
    return 1;
  }

  int fd1 = open(argv[1], O_RDONLY);
  int fd2 = open(argv[2], O_CREAT | O_WRONLY, 0700);
  long int fileSize = 0, n;
  char buff;

  while ((n = read(fd1, &buff, 1)) > 0) fileSize++;

  for (int i = 1; i <= fileSize; i++) {
    lseek(fd1, i * -1, SEEK_END);
    read(fd1, &buff, 1);
    write(fd2, &buff, 1);
  }

  close(fd1);
  close(fd2);

  return 0;
}
