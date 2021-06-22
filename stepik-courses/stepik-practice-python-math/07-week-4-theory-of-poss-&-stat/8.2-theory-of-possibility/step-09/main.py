import random

n, m = int(input()), int(input())
depo = list('1' * n + '2' * m)
results = [random.choice(depo) == '1' for _ in range(500_000)]

answer = (sum(results) / len(results)) * 100

print(f"{round(answer, 1)}%")
