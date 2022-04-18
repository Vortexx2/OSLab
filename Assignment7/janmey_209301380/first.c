/**
 * Multithreaded program for summing 3 elements at a time in a 12 element array
 */

#include <pthread.h>
#include <stdio.h>

int sum[4];
int i[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void *sum3(void *arg) {
  int ind = (int)arg;
  int start = ind * 3;
  int cnt = 0;

  while (cnt < 3) {
    sum[ind] += *(i + cnt + start);
    cnt++;
  }
  printf("index = %d, its sum = %d \n", ind, sum[ind]);
}

void main() {
  pthread_t t1, t2, t3, t4;
  pthread_create(&t1, NULL, sum3, (void *)0);
  pthread_create(&t2, NULL, sum3, (void *)1);
  pthread_create(&t3, NULL, sum3, (void *)2);
  pthread_create(&t4, NULL, sum3, (void *)3);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);

  printf("%d\n", sum[0] + sum[1] + sum[2] + sum[3]);
}