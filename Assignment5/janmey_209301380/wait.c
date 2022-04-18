#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid = fork();

  if (pid == 0) {
    // sleep for 7 seconds
    sleep(7);
    printf("I am Child : %d\n", getpid());
    printf("Parent: %d\n", getppid());
  }

  else {
    printf("I am Parent: %d\n", getppid());
    printf("Child : %d\n", getpid());
  }

  return 0;
}