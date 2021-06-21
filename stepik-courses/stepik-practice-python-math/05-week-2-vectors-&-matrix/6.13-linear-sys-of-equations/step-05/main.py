import numpy as np

M = np.array(tuple(input().split() for _ in range(3)), dtype=int)

try:
    print(*np.linalg.solve(M[:, :-1], M[:, -1]))
except:
    print("Система не имеет решений")
