#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int lswc[2];

  pipe(lswc);

  if (!fork()) {
    close(1);

    dup(lswc[1]);

    close(lswc[0]);

    execlp("ls", "ls", NULL);
  } else {
    close(0);

    dup(lswc[0]);

    close(lswc[1]);

    execlp("wc", "wc", NULL);
  }
}