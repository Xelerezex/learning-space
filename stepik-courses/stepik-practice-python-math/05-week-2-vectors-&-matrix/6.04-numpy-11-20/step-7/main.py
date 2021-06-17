import numpy as np

np.random.seed(42)

Z = np.random.rand(*map(int, input().split())).mean(axis=0)

print(Z.min(), Z.max(), sep='\n')
