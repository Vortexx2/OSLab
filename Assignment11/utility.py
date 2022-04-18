from typing import List, Optional, Tuple


# ---------------- Below all of the utility methods have been defined ----------------------

def example_processes() -> Tuple(List["Process"], List[int]):
  """
    Method to return (Processes, Initial_Available_Resources)
  """
  p = []
  p.append(Process(0, 4, [0, 0, 1, 2], [0, 0, 1, 2]))
  p.append(Process(1, 4, [1, 0, 0, 0], [1, 7, 5, 0]))
  p.append(Process(2, 4, [1, 3, 5, 4], [2, 3, 5, 6]))
  p.append(Process(3, 4, [0, 6, 3, 2], [0, 6, 5, 2]))
  p.append(Process(4, 4, [0, 0, 1, 4], [0, 6, 5, 6]))

  return p, [1, 5, 2, 0]


# ---------------- Below all of the utility classes have been defined ----------------------

class Process:
  def __init__(self, pid: int, num_resources: int, allocated: List[int] = [], max_need: List[int] = []):
    self.pid = pid
    self.num_resources = num_resources

    if allocated and max_need:
      assert (len(allocated) == self.num_resources and len(
          max_need) == self.num_resources)

      self.allocated, self.max_need = allocated, max_need

    else:
      self.allocated = [0] * self.num_resources
      self.max_need = [0] * self.num_resources
