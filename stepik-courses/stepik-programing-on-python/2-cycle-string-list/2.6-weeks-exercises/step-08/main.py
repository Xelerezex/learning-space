p = []
t = []
M = []
n = int(input())
l = len(t)
k = 0
m = 2
for h in range(1, n + 1):
    p.append(str(h))
for i in range(0, len(p)):
    if i == 0:
        t.insert(l, p[i])
        k = 0
    elif i == 1:
        while i >= k:
            l = len(t)
            t.insert(l, p[i])
            k += 1
        k -= 2
    elif i > 1:
        while i >= k:
            l = len(t)
            t.insert(l, p[i])
            k += 1
        k = i - m
        m += 1
    l = len(t)
x = len(t)
if len(t) == 1:
    print(1)
else:
    for j in range(0, x - 1):
        M.append(t[j])
    for g in range(0, n):
        print(M[g], end=' ')
