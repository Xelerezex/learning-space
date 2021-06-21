import sys
import numpy as np

n = int(input())

a = np.loadtxt(sys.stdin)

print(*np.linalg.solve(a[:, :1] ** np.arange(n), a[:, 1]))
