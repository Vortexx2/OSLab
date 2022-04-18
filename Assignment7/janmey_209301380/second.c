/**
 * Multithreaded program to calculate average of array elements using one thread and factorial using one thread for each array element
 */

#include <pthread.h>
#include <stdio.h>

int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int res[10];

void *average() {
  float sum = 0;
  for (int j = 0; j < 10; j++) sum += *(i + j);
  printf("\nThe average of the array is: %f",
         sum / 10);  // 10 elements in the array.
}

void *factorial(void *arg) {
  int ind = (int)arg;
  int element = ind;
  int ans = 1;

  while (element > 1) {
    ans *= element;
    element--;
  }
  res[ind] = ans;
}

int main() {
  pthread_t t1, fac[10];

  pthread_create(&t1, NULL, average, NULL);

  for (int j = 0; j < 10; j++) {
    pthread_create(&fac[j], NULL, factorial, (void *)i[j]);
  }

  pthread_join(t1, NULL);
  for (int j = 0; j < 10; j++) {
    pthread_join(fac[j], NULL);
  }

  printf("\nThe output of the factorial of each number is:\n");
  for (int j = 1; j < 11; j++) {
    printf("%d, ", res[j]);
  }

  return 0;
}