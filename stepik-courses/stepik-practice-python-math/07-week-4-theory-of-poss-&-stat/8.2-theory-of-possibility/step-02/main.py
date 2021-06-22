import random

dice = [i for i in range(1, int(input()) + 1)]
results = [random.choice(dice) for _ in range(1_000_000)]

print(f'{round(results.count(1) / len(results) * 100, 1)}%')
