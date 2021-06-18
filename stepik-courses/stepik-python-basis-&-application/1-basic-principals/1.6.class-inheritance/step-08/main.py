class ExtendedStack(list):
    def sum(self):
        top1 = self.pop()
        top2 = self.pop()
        self.append(top1 + top2)
        return self

    def sub(self):
        top1 = self.pop()
        top2 = self.pop()
        self.append(top1 - top2)
        return self

    def mul(self):
        top1 = self.pop()
        top2 = self.pop()
        self.append(top1 * top2)
        return self

    def div(self):
        top1 = self.pop()
        top2 = self.pop()
        self.append(top1 // top2)
        return self
