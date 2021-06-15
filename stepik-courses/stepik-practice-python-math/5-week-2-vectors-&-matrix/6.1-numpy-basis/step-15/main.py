M2 = M1.copy()
M2[-2] = np.sin(M2[-2] * np.pi / 6)
M2[:, -2] = np.exp(M2[:, -2])
