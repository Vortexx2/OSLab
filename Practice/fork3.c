#include <stdio.h>
#include <unistd.h>

int main() {

  execl("/bin/cp", "cp", "fork1.c", "fork3.c");

  return 0;
}
