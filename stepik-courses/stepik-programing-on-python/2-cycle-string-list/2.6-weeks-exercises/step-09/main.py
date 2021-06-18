s = [int(i) for i in input().split()]
n = int(input())
t = []
l = len(s) - 1
if n in s:
    for i in range(0, l + 1):
        if s[i] == n:
            t.append(i)
    g = len(t) - 1
    for j in range(0, g + 1):
        print(t[j], end=' ')
else:
    print('Отсутствует')
