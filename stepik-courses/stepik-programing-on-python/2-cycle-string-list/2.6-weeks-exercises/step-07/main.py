a1 = int(input())
s = a1
s2 = 0 + abs(a1**2)
while s != 0:
    a1 = int(input())
    s = s + a1
    s2 = s2 + abs(a1)**2
    if s == 0:
        break
print(s2)
