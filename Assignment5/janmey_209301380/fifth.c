#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid = fork();

  if (pid > 0) {
    printf("parent %d\n", getppid());
  }

  else if (pid == 0) {
    printf("child %d", getpid());
  }

  else {
    printf("error");
  }
  return 0;
}