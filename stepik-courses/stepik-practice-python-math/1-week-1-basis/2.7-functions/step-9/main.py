def Kfactorial(n, k=1):
    return n * Kfactorial(n - k, k) if n > k else max(n, 1)
