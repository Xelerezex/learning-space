a, b, c, d = input(), input(), input(), input()
print(''.join(b[a.index(i)] for i in c))
print(''.join(a[b.index(i)] for i in d))
