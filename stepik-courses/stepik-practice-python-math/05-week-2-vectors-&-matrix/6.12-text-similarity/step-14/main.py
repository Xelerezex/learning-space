def list_pull(L):
    return [x for y in L for x in list_pull(y)] if isinstance(L, list) else [L]


L2 = list_pull(L1)

# L2 = sum(L1, [])
