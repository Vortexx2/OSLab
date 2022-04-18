#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t wrt;
pthread_mutex_t mLock;
int count = 1;
int numreader = 0;

void *writerProc(void *wno) {
  sem_wait(&wrt);
  count *= 2;

  printf("Writer %d modified count to %d\n", (*((int *)wno)), count);
  sem_post(&wrt);
}

void *readerProc(void *rno) {
  pthread_mutex_lock(&mLock);
  numreader++;

  if (numreader == 1)
    sem_wait(
        &wrt);  // if this is the first reader, it will block the first writer

  pthread_mutex_unlock(&mLock);

  // Section where reading is done
  printf("Reader id: %d, reads count as %d\n", (*(int *)(rno)), count);

  // Reader acquires the lock before modifying `numreader`
  pthread_mutex_lock(&mLock);
  numreader--;

  if (!numreader)
    sem_post(&wrt);  // if this is the last reader, it will wake up the writer

  pthread_mutex_unlock(&mLock);
}

int main() {
  int readLen = 5, writeLen = 3;

  pthread_t read[readLen], write[writeLen];
  pthread_mutex_init(&mLock, NULL);
  sem_init(&wrt, 0, 1);

  int a[5] = {1, 2, 3, 4, 5};  // used for numbering readers and writers

  for (int i = 0; i < readLen; i++)
    pthread_create(&read[i], NULL, readerProc, (void *)&a[i]);
  
  for (int i = 0; i < writeLen; i++) pthread_create(&write[i], NULL, writerProc, (void *)&a[i]);

  pthread_mutex_destroy(&mLock);
  sem_destroy(&wrt);

  return 0;
}