import random
import numpy as np


n = int(input())
m = int(input())

M = np.array([[random.choice((0, 1)) for i in range(n)] for i in range(100000)])

good = M[np.count_nonzero(M, axis=1) == m].shape

print('{:.1%}'.format(good[0] / M.shape[0]))
