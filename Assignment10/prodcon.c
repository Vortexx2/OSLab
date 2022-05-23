#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5
#define BUFFER_SIZE 5

sem_t empty, full;
int in = 0, out = 0;
int buffer[BUFFER_SIZE];
pthread_mutex_t mLock;

int randomInt(int upper) {
  /**
   * Return a random integer between upper and lower, both inclusive
   */

  int num = (rand() % (upper + 1));
  return num;
}

void *producer(void *pno) {
  int item;

  for (int i = 0; i < MAX_ITEMS; i++) {
    item = rand();  // Produce an random item

    sem_wait(&empty);
    pthread_mutex_lock(&mLock);

    buffer[in] = item;
    printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in],
           in);
    in = (in + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mLock);
    sem_post(&full);
  }
}

void *consumer(void *cno) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    sem_wait(&full);

    pthread_mutex_lock(&mLock);
    int item = buffer[out];
    printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, out);
    out = (out + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&mLock);
    sem_post(&empty);
  }
}

int main() {
  pthread_t pro[5], con[5];
  pthread_mutex_init(&mLock, NULL);
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);

  int a[5] = {1, 2, 3, 4,
              5};  // Just used for numbering the producer and consumer

  for (int i = 0; i < 5; i++) {
    pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
  }
  for (int i = 0; i < 5; i++) {
    pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
  }

  for (int i = 0; i < 5; i++) pthread_join(pro[i], NULL);

  for (int i = 0; i < 5; i++) pthread_join(con[i], NULL);

  pthread_mutex_destroy(&mLock);
  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}