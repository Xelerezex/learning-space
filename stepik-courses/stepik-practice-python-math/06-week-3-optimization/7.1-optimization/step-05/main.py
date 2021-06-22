from math import ceil, sqrt


def s6(a):
    return 3 ** 1.5 * a * a / 2


def s5(a):
    return a ** 2 * sqrt(25 + 10 * sqrt(5)) / 4


def S(x):
    return 20 * s6(a) + 12 * s5(a)


def S_ceil(x):
    return ceil(S(a))
