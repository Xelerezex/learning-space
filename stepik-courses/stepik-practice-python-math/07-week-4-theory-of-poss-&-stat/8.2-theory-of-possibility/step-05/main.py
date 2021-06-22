from random import choice

n, m, k = [int(input()) for _ in range(3)]

iters = 100000
dice = [i + 1 for i in range(m)]
positive = sum(1 for _ in range(iters) if sum([choice(dice) for _ in range(n)]) == k)

print(f'{round(positive/iters * 100, 1)}%')
