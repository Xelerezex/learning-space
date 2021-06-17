import numpy as np

x, k = map(int, input().split())

Z = np.diag(np.arange(1,k+1), x)

# import numpy as np
# x, k = map(int, input().split())
# Z = np.diagflat(np.arange(1, k+1), x)
