import numpy as np

np.random.seed(42)

Z = np.random.rand(*map(int, input().split()))
print(f'{np.min(Z)}\n{np.max(Z)}')
