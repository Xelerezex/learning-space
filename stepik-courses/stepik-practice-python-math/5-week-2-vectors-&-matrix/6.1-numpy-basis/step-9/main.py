import numpy as np

first = np.fromstring(input(), dtype=np.int, sep=', ')
divider = np.fromstring(input(), dtype=np.int, sep=', ')[-2]

mask = first % divider == 0
V = first[mask] / divider
