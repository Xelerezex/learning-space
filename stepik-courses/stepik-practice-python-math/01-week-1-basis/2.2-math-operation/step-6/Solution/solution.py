a, b, c = map(int, [input() for _ in range(3)])
p = (a + b + c) / 2
print(int(p * 2), ((p * (p - a) * (p - b) * (p - c))**0.5), sep="\n")
