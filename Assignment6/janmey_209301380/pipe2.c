#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pipe1[2], pipe2[2], id1, id2;

  pipe(pipe1);

  id1 = fork();

  if (id1 == 0) {
    pipe(pipe2);
    id2 = fork();
    
    if (id2 == 0) {
      close(1);
      dup(pipe2[1]);

      close(pipe1[0]);
      close(pipe1[1]);
      close(pipe2[0]);
      close(pipe2[1]);

      execl("/bin/ls", "ls", 0);
    }

    else {
      close(0);
      dup(pipe2[0]);
      close(1);

      dup(pipe1[1]);

      close(pipe1[0]);
      close(pipe1[1]);
      close(pipe2[0]);
      close(pipe2[1]);

      execl("/bin/sort", "sort", 0);
    }
  }

  else {
    close(0);
    dup(pipe1[0]);
    close(pipe1[0]);
    close(pipe1[1]);
    execlp("wc", "wc", 0);
  }

  return 0;
}