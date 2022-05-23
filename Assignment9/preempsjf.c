#include <stdio.h>

int main() {
  int arr_time[10], burst_time[10], temp[10];
  int i, smallest, count = 0, time, limit;
  double wait_time = 0, ta_time = 0, end;
  float avgwait_time, avgta_time;

  printf("Enter the Total Number of Processes: ");
  scanf("%d", &limit);
  printf("Enter Details of %d Processes", limit);

  for (i = 0; i < limit; i++) {
    printf("\nEnter Arrival Time : ");
    scanf("%d", &arr_time[i]);
    printf("Enter Burst Time : ");
    scanf("%d", &burst_time[i]);
    temp[i] = burst_time[i];
  }

  burst_time[9] = 9999;

  for (time = 0; count != limit; time++) {
    smallest = 9;

    for (i = 0; i < limit; i++) {
      if (arr_time[i] <= time && burst_time[i] < burst_time[smallest] &&
          burst_time[i] > 0) {
        smallest = i;
      }
    }

    burst_time[smallest]--;
    if (burst_time[smallest] == 0) {
      count++;
      end = time + 1;
      wait_time = wait_time + end - arr_time[smallest] - temp[smallest];
      ta_time = ta_time + end - arr_time[smallest];
    }
  }

  avgwait_time = wait_time / limit;
  avgta_time = ta_time / limit;
  printf("Average Waiting Time : t %lf \n", avgwait_time);
  printf("Average Turn-Around Time: t %lf\n", avgta_time);

  return 0;
}