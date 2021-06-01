a = int(input())
b = int(input())
s = 0
c = 0
for j in range(a, b + 1):
    if j % 3 == 0:
        s = s + j  # 42
        c = c + 1
    j += 1
print(s / c)
