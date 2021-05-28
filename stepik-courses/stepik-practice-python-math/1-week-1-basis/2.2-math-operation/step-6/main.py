a = int(input())
b = int(input())
c = int(input())

P = a + b + c
S = (1 / 4) * (((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c)) ** 0.5)
print(P)
print(S)
