from typing import List, Optional, Tuple


# ---------------- Below all of the utility methods have been defined ----------------------

def example_processes() -> Tuple[List["Process"], List[int]]:
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
  def __init__(self, pid: int, num_resources: int,
               allocated: Optional[List[int]] = None, max_need: Optional[List[int]] = None):
    self.pid = pid
    self.num_resources = num_resources
    self.executed = False

    if allocated and max_need:
      assert (len(allocated) == self.num_resources and len(
          max_need) == self.num_resources)

      self.allocated, self.max_need = allocated, max_need

    else:
      self.allocated = [0] * self.num_resources
      self.max_need = [0] * self.num_resources

  @property
  def need(self) -> List[int]:
    """ The need array for a process which is (max_need - allocated) """
    return [(max_res - alloc) for (max_res, alloc) in zip(self.max_need, self.allocated)]

  def can_execute(self, available: List[int]) -> bool:
    """
      Returns True if process can execute - respective available resources > need resources\n
      Else returns False
    """
    if self.executed:
      return False

    for avail, need in zip(available, self.need):
      if avail < need:
        return False

    return True

  def execute(self, available: List[int]) -> List[int]:
    """
      Executes the current process. Should only be done after checking if `can_execute()`.\n
      Sets `self.executed` flag to `True` and returns new list of available resources.
    """
    self.executed = True
    return [(avail + alloc) for avail, alloc in zip(available, self.allocated)]


class Gantt:

  def __init__(self, num_procs: int):
    self.num_procs = num_procs
    self.arr = []

  def add(self, proc: Process, available: List[int]) -> None:
    self.arr.append((proc, available))

  def __str__(self) -> str:

    if len(self.arr) != self.num_procs:
      return "There is no viable sequence\n"

    res = ""
    for proc, available in self.arr:
      res += f"Process {proc.pid} has been executed. New available resource list is {available}\n"

    return res

  def __len__(self) -> int:
    return len(self.arr)
