def deep(a):
    return a if not isinstance(a, list) else list(map(deep, a))


L2 = deep(L1)
