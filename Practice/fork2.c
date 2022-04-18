#include <stdio.h>
#include <unistd.h>

int main() {

  execlp("cp", "cp", "fork1.c", "fork2.c");

  return 0;
}
