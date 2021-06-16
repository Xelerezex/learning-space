import numpy as np

np.random.seed(42)

print(np.random.random(list(map(int, input().split()))).mean())
