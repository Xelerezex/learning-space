def front_back(a, b):
    def sep(x): return (len(x) + 1) // 2
    return a[:sep(a)] + b[:sep(b)] + a[sep(a):len(a)] + b[sep(b):len(b)]
