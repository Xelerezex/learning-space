from random import uniform

L, N, M = [int(input()) for _ in range(3)]

iters = 100000
positive = 0

for _ in range(iters):
    points = sorted([uniform(0, L) for _ in range(N - 1)] + [0, L])
    positive += any((points[i] - points[i - 1]) >= M for i in range(1, N + 1))

print(f'{round(positive/iters * 100, 1)}%')
