from typing import Final, List
from utility import *

NUM_RESOURCES: Final = 4
NUM_PROCESSES: Final = 5


if __name__ == "__main__":

  processes, available = example_processes()




  for i in range(NUM_PROCESSES):
    new_proc = Process(i, NUM_RESOURCES)
