#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  int pid = fork();

  if (pid > 0) {
    printf("I am the Parent %d. I am going to wait for my child\n", getppid());
    int child_status = wait(NULL);

    printf("I am the Parent %d. My child's return status is %d \n", getppid(),
           child_status);
  }

  else if (pid == 0) {
    printf("I am child %d\n", getpid());
    printf("My parent is %d\n", getppid());

    exit(0);
  }

  else
    printf("ERROR");

  return 0;
}