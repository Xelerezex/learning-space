def factorial(x):
    return int(x <= 1) or factorial(x - 1) * x


def sf(x):
    return int(x <= 1) or factorial(x) * sf(x - 1)
