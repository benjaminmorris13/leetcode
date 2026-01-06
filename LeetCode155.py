class MinStack:

    def __init__(self):
        self.values = []
        self._size = 0

    def push(self, val: int) -> None:
        self.values.append(val)
        self._size = self.size + 1

    def pop(self) -> None:
        self.values.pop(self.size - 1)
        self._size = self.size - 1

    def top(self) -> int:
        return self.values[self._size - 1]

    def getMin(self) -> int:
        return sorted(self.values)[0]
    
    @property
    def size(self):
        return self._size
