import numpy as np

Z = np.ones(tuple(map(int, input().split())))

Z[1:-1, 1:-1] = 0
