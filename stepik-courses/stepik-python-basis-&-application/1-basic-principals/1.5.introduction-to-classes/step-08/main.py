class MoneyBox:
    def __init__(self, capacity=0):
        self.capacity = capacity
        self.val = 0

    def can_add(self, v):
        return True if self.capacity >= (self.val + v) else False

    def add(self, v):
        self.val += v
