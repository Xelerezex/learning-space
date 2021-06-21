import numpy as np

m = np.array((input().split()), dtype=int)

n = np.linalg.solve(np.array([[1, 1], [1, -1]]), m)

print("Такой класс не существует") if len(n[n < 0]) or len([i for i in n if i % 1]) else print(*n.astype(int))
