#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Invalid amount of arguments provided\n");
    return 1;
  } 

  int fd = open(argv[1], O_RDONLY);
  int buffSize = 100;
  char buff[buffSize];
  long int n;

  while ((n = read(fd, buff, buffSize)) > 0) {
    if (write(1, buff, n) == -1) {
      perror("Error while writing");
      exit(3);
    }
  }

  if (n == -1) {
    perror("Error while writing");
    exit(1);
  }

  close(fd);

  return 0;
}