s = [int(i) for i in input().split()]
t = []
s.sort()
l = len(s) - 1
k = 100000
if len(s) != 1:
    for i in range(0, l):
        if s[i] == s[i + 1] and s[i] != k:
            t.append(s[i])
            k = s[i]
    for j in range(l, l + 1):
        if s[-1] == s[-2] and s[j] != k:
            t.append(s[j])
n = len(t)
for g in range(0, n):
    print(t[g], end=' ')
