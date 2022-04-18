#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void *sum3(void *start) {
  void *tempSum = malloc(sizeof(int));
  *(int *)tempSum = 0;

  int beg = *(int *)(start);

  for (int i = beg; i < (beg + 4); i++) {
    *((int *)tempSum) += arr[i];
  }

  printf("tempSum: %d with start: %d\n", *((int *)tempSum), beg);
  return NULL;
}

int main() {
  pthread_t tids[4];

  for (int i = 0; i < 4; i++) {
    int beg = 3 * i;
    pthread_create(&tids[i], NULL, sum3, (void *)(&beg));
  }

  // void **retVals[4];
  // for (int i = 0; i < 4; i++) {
  //   pthread_join(tids[i], retVals[i]);
  //   printf("Curr Sum: %d\n", *(int *)retVals[i]);
  // }

  for (int i = 0; i < 4; i++) {
    pthread_join(tids[i], NULL);
  }

  // int temp = 4;
  // void *another = (void *)(&temp);
  // printf("Value: %d", *(int *)(another));
  return 0;
}