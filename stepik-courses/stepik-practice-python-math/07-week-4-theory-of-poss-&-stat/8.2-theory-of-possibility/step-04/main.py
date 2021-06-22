import random

n, m = int(input()), int(input())

results = [sum([random.randint(0, 1) for i in range(n)]) for i in range(100000)]
less_m = [i for i in results if i <= m]

p = round(len(less_m) / len(results) * 100, 1)
print(f'{p}%')
