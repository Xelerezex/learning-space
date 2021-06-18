s = [int(i) for i in input().split()]
summ = 0
l = len(s) - 1
for i in range(0, l + 1):
    summ = summ + s[i]
print(summ)
