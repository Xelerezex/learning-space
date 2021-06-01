s = str(input())
l = len(s) - 1
c = 1
t = ''
if len(s) == 1:
    t = t + s + str(c)
else:
    for i in range(0, l):
        if s[i] == s[i + 1]:
            c += 1
        elif s[i] != s[i + 1]:
            t = t + s[i] + str(c)
            c = 1
    for j in range(l, l + 1):
        if s[-1] == s[-2]:
            t = t + s[j] + str(c)
        elif s[-1] != s[-2]:
            t = t + s[j] + str(c)
            c = 1
print(t)
