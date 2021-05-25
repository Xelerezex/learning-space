class multifilter:
    def judge_half(pos, neg):
        # допускает элемент, если его допускает хотя бы половина фукнций (pos >= neg)
        return True if pos >= neg else False

    def judge_any(pos, neg):
        # допускает элемент, если его допускает хотя бы одна функция (pos >= 1)
        return True if pos >= 1 else False

    def judge_all(pos, neg):
        # допускает элемент, если его допускают все функции (neg == 0)
        return True if neg == 0 else False

    def __init__(self, iterable, *funcs, judge=judge_any):
        # iterable - исходная последовательность
        # funcs - допускающие функции
        # judge - решающая функция
        self.iterable = iterable
        self.funcs = funcs
        self.judge = judge

    def __iter__(self):
        for item in self.iterable:
            pos, neg = 0, 0
            for func in self.funcs:
                if (func(item) == True):
                    pos += 1
                elif (func(item) == False):
                    neg += 1

            if (self.judge(pos, neg) == True):
                yield item
