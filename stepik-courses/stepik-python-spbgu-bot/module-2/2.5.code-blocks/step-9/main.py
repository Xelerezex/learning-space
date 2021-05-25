import math

a = float(input())
b = float(input())
c = float(input())

discr = b ** 2 - 4 * a * c

if discr > 0:
    x1 = round(((-b + math.sqrt(discr)) / (2 * a)), 2)
    x2 = round(((-b - math.sqrt(discr)) / (2 * a)), 2)
    print((x1 if (x1 <= x2) else x2))
    print((x2 if (x2 >= x1) else x1))
elif discr == 0:
    x = round((-b / (2 * a)), 2)
    print(x)
else:
    print("No roots")
