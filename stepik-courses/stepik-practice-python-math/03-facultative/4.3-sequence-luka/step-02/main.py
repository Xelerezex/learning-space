def luka(L0, L1, n):
    for _ in range(n):
        L0, L1 = L1, L0 + L1
    return L0
