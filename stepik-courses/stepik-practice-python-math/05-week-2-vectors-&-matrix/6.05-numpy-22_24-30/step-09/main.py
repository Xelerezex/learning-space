import numpy as np

Z = np.where(A > 0, np.ceil(A), np.floor(A))

# np.copysign(np.ceil(np.abs(A)), A)
