inp = input().split(" ")
lst = list(map(int, [i for i in inp if i != '']))
print(*(lst[(i - 1) % len(lst)] * lst[(i + 1) % len(lst)] + lst[i]
        for i in range(len(lst))))
