#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int fd1, fd2;

  fd1 = open("red.c", O_RDONLY);
  close(0);

  dup(fd1);
  fd2 = open("red1", O_WRONLY | O_CREAT, 0744);
  close(1);
  dup(fd2);

  execlp("ls", "ls", 0);

  return 0;
}