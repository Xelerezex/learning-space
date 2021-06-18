def f(x):
    # put your python code here
    if x <= -2:
        f = 1 - (x + 2)**2
    elif x > -2 and x <= 2:
        f = -(x / 2)
    elif x > 2:
        f = (x - 2)**2 + 1
    return f
