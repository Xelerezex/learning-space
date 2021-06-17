def kaprekar_check(n):
    s = str(n)
    return (len(s) in [3, 4, 6]) and (len(set(s)) > 1) and (n not in [100, 1000, 100000])
