#include <stdio.h>

void displayMem(int mainMem[], int numParts) {
  printf("The main memory blocks are:\n");
  printf("-----------------\n");
  for (int i = 0; i < numParts; i++) {
    printf("|\t%d\t|\n", mainMem[i]);
    printf("-----------------\n");
  }
}

void enterMemBlocks(int mainMem[], int numParts) {
  printf("Enter %d memory block sizes\n", numParts);
  for (int i = 0; i < numParts; i++) scanf("%d", &mainMem[i]);
}

int allocateBestFit(int mainMem[], int numParts, int procSize) {
  int minMemInd = -1;
  for (int i = 0; i < numParts; i++) {
    if (mainMem[i] >= procSize) {
      if (minMemInd == -1 || mainMem[i] < mainMem[minMemInd]) {
        minMemInd = i;
      }
    }
  }

  if (minMemInd != -1) mainMem[minMemInd] -= procSize;

  return minMemInd;
}

int main() {
  int numParts;
  printf("Enter number of partitions that you want in memory:\t");
  scanf("%d", &numParts);

  int mainMem[numParts];
  enterMemBlocks(mainMem, numParts);
  displayMem(mainMem, numParts);

  while (1) {
    printf("Enter new process size or 0 to quit:\t");
    int procSize;
    scanf("%d", &procSize);

    if (!procSize) return 0;

    int allocated = allocateBestFit(mainMem, numParts, procSize);

    if (allocated == -1) {
      printf("Not enough space to allocate given process\n");
    }

    else {
      printf("New Process has been allocated\n");
      displayMem(mainMem, numParts);
    }
  }

  return 0;
}
