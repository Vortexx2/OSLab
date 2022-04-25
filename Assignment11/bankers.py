from typing import Final, List

from utility import *

NUM_RESOURCES: Final = 4
NUM_PROCESSES: Final = 5


if __name__ == "__main__":

  processes, available = example_processes()
  gantt = Gantt(NUM_PROCESSES)

  for i in range(NUM_PROCESSES):
    did_proc_exec = False

    for proc in processes:
      if proc.can_execute(available):
        available = proc.execute(available)

        gantt.add(proc, available)

        did_proc_exec = True

  print(gantt)
