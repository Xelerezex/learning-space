import math


def f(x):
    return (2 * x**2 - 3 * x - 5) / (3 * x**2 + x + 1)


def lim(x):
    eps = 0.0001
    while math.fabs(f(x) - f(10 * x)) > eps:
        x *= 10
    return f(x)


print(round(lim(100), 3))
print(round(lim(-100), 3))
