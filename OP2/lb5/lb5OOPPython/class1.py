import math

class TVector:

    def __init__(self, value):
        self.arr = [float(0) for i in range(int(value))]

    def  __getitem__(self, index):
       return self.arr[index]

    def __setitem__(self, index, value):
       self.arr[index] = value

    def __len__(self):
       return len(self.arr)

    def perp(self, vec):
        sum = float(0)
        if len(self.arr) != len(vec.arr):
            return False
        else:
            for i in range(len(self.arr)):
                sum += float(self.arr[i]) * float(vec.arr[i])
        return sum == 0

    def parall(self, vec):
        b = True
        if len(self.arr) != len(vec.arr):
            return False
        else:
            for i in range(len(self.arr)):
                b = b and ((self.arr[i - 1] / vec.arr[i - 1]) == (self.arr[i] / vec.arr[i]))
        return b

    def __str__(self):
        return str(self.arr)

    def input(self):
        for i in range(len(self.arr)):
            self.arr[i] = float(input())

    def length(self):
        sum = float(0)
        for i in range(len(self.arr)):
            sum += float(self.arr[i]) * float(self.arr[i])
        return math.sqrt(sum)

class R2Vector(TVector):

    def __init__(self):
       super().__init__(2)


class R3Vector(TVector):

    def __init__(self):
       super().__init__(3)