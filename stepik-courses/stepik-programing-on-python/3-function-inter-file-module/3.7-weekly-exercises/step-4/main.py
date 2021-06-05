n = int(input())
d = {'север': 0, 'запад': 0, 'юг': 0, 'восток': 0}
for i in range(n):
    x = input().split()
    d[x[0]] += int(x[1])
print(d['восток'] - d['запад'], d['север'] - d['юг'])
