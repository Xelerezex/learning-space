import numpy as np


n, m = map(int, input().split())
k = int(input())
Z = np.tile(np.arange(k, k + m, dtype=np.float), (n, 1))
