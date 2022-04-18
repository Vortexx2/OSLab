#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid = fork();

  // child process code
  if (pid == 0) {
    printf("This is the child process");
    exit(1);
  }

  else {
    printf("This is the parent process");
    sleep(50);
  }

  return 0;
}