import sys
import numpy as np

n = int(input())

try:
    print(*np.linalg.solve(*np.hsplit(np.loadtxt(sys.stdin), [n])).ravel())
except np.linalg.LinAlgError:
    print('Система не имеет решений')
