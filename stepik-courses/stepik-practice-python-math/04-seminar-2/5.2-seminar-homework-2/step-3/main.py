from math import sin, pi


def f(x):
    return sin((pi * x) / 2) / x


inf = 1e9
print(round(f(inf), 3))


# print(0)
