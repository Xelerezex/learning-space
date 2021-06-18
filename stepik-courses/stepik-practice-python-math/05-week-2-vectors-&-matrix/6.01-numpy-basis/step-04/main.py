import numpy as np

V1 = np.fromstring(input(), sep=', ')
V2 = np.array(V1[-2])
V3 = V1[::-1]
V4 = V1[::3]
V5 = np.arange(V1.shape[0])
