import sys
import numpy as np

try:
    print(*np.linalg.solve(*np.hsplit(np.loadtxt(sys.stdin), [2])).ravel())
except np.linalg.LinAlgError:
    print('Система не имеет решений')
