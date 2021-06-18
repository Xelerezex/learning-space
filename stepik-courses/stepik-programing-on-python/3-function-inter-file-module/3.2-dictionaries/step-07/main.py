d = {}
k = []
n = int(input())
for i in range(n):
    x = int(input())
    k.append(x)
for j in range(0, len(k)):
    key = k[j]
    if key in d:
        print(d[key])
    elif key not in d:
        p = k[j]
        d[key] = f(p)
        print(d.get(key))
