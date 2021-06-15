A = np.column_stack((A2 - A1, A3 - A1))
S = abs(np.linalg.det(A)) / 2
print(S)

# print(abs(np.cross(A1 - A2, A1 - A3)) / 2)
