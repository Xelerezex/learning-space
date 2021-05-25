_max, to_find = map(int, input().split(" "))
try:
    x = list(map(int, input().split(" ")))
    print(sum([i for i in x[:x.index(to_find)]]))
except ValueError:
    print(0)
