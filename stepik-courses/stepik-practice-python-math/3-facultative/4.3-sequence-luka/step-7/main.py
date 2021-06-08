import numpy as np


def super_L(n):
    return np.linalg.matrix_power(np.array([[0, 1], [1, 1]], 'O'), n).dot([2, 1])[0] if n else 2

# def super_L(n):
#     for i in (6, 5, 4, 3, 2, 1):
#         if not n % i:
#             n, n1, L, L1 = n // i, n // i, 2, 1
#             while n1:
#                 L, L1, n1 = L1, L + L1, n1 - 1
#             return {1: L,
#                     2: L**2-2*(-1)**n,
#                     3: L**3-3*(-1)**n*L,
#                     4: L**4-4*(-1)**n*L**2+2,
#                     5: L**5-5*(-1)**n*L**3+5*L,
#                     6: L**6-6*(-1)**n*L**4+9*L**2-2*(-1)**n}[i]
