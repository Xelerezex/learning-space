import numpy as np

n, m = map(int, input().split())
k = float(input())
Z = np.tile(np.arange(k, k + n), (m, 1)).T
