s = [int(i) for i in input().split()]
t = []
l = len(s) - 1
k = 0
i = 0
if len(s) == 0:
    print(str(0))
else:
    for st in s:
        if len(s) > 1:
            if i == 0:
                k = s[i + 1] + s[-1]
                t.append(k)
            elif i > 0 and i < l:
                k = s[i - 1] + s[i + 1]
                t.append(k)
            elif i == l:
                k = s[i - 1] + s[0]
                t.append(k)
        elif len(s) == 1:
            k = s[i]
            t.append(k)
        i += 1
    j = 0
    for st2 in t:
        print(str(t[j]) + ' ', end='')
        j += 1
