#include <stdio.h>

int PIDS[] = {1, 2, 3, 4};
int arrivals[] = {0, 4, 3, 2};
int bursts[] = {8, 5, 2, 1};
int priorities[] = {4, 2, 1, 3};
int flag[] = {0, 0, 0, 0};
int completions[4];
int turnarounds[4];
int waitings[4];

void completion_time();
void turnaround_time();
void waiting_time();

void completion_time() {
  int ct = 0;
  int nextProcess = 0;
  for (int k = 0; k < 4; k++) {
    int min = 1000;
    for (int i = 0; i < 4; i++) {
      if (arrivals[i] < min && flag[i] != 1) {
        min = arrivals[i];
        nextProcess = i;
      }
    }
    ct = ct + (bursts[nextProcess]);
    completions[nextProcess] = ct;
    printf("Completion time for Process %d is %d ms\n", PIDS[nextProcess], ct);
    flag[nextProcess] = 1;
  }
  printf("\n");
}

void turnaround_time() {
  double tt = 0;
  for (int i = 0; i < 4; i++) {
    turnarounds[i] = completions[i] - arrivals[i];
    printf("Turnaround time for Process %d is %d ms\n", PIDS[i],
           turnarounds[i]);
  }
  for (int j = 0; j < 4; j++) tt = tt + turnarounds[j];
  printf("Average turnaround time is : %.3f ms\n", (tt / 4));
  printf("\n");
}

void waiting_time() {
  double wt = 0;
  for (int i = 0; i < 4; i++) {
    waitings[i] = turnarounds[i] - bursts[i];
    printf("Waiting time for Process %d is %d ms\n", PIDS[i], waitings[i]);
    wt = wt + waitings[i];
  }
  printf("Average waiting time is : %.3f ms\n", (wt / 4));
}

void main() {
  completion_time();
  turnaround_time();
  waiting_time();
}