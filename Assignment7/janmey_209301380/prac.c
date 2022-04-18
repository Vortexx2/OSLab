#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *myTurn(void *arg) {
  while (1) {
    printf("My Turn\n");
    sleep(1);
  }
}

void *yourTurn(void *arg) {
  while (1) {
    printf("Your Turn\n");
    sleep(2);
  }
}

int main() {
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, myTurn, NULL);
  pthread_create(&tid2, NULL, yourTurn, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}