def dfactorial(n):
  return n * dfactorial(n - 2) if n > 1 else 1
