from scipy.optimize import golden
from functools import partial


def f(x):
    return (x + a)**2 - b


def g(x):
    return abs(f(x))


funcs = (f, g)
golden_with_params = partial(golden, brack=(-10, -4), full_output=True)
funcs_mins = [m[1] for m in map(golden_with_params, funcs)]

print(*funcs_mins)
