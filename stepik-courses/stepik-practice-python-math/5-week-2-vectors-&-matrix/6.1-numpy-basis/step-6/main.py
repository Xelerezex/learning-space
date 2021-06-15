import numpy as np

V1 = np.fromstring(input(), dtype=np.int, sep=', ')
V2 = np.fromstring(input(), dtype=np.int, sep=', ')
V3 = V1 + V2
V4 = V1[::2] * V2[::-2]
