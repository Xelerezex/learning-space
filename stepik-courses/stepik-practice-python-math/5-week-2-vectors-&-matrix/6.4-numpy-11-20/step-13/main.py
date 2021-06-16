import numpy as np

n, m = map(int, input().split())
Z = np.tile([[0., 1.], [1., 0.]], (1 + n // 2, 1 + m // 2))[:n, :m]
