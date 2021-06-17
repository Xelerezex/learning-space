import numpy as np

args = input().split()

try:
    Z = np.zeros(tuple(map(int, args)))
except ValueError:
    Z = np.zeros(tuple(map(int, args[:-1])), args[-1])
