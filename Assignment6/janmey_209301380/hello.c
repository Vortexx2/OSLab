#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pfd[2], n, id;
  char buff[1024];

  pipe(pfd);
  id = fork();

  if (id == 0) {
    close(pfd[0]);
    write(pfd[1], "hello", 5);
  }

  else {
    close(pfd[1]);
    n = read(pfd[0], buff, 1024);
    write(1, buff, n);
  }

  return 0;
}