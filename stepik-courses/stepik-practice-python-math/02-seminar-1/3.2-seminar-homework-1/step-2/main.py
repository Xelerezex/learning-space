from math import atan, inf


def f(x):
    return 2 * atan(x)


lim = f(inf)


print(round(lim, 3))
