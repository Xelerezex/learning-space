def calculate_mode(x):
    x = {i: x.count(i) for i in x}
    return min([i for i in x.keys() if x[i] == max(x.values())])


n = int(input())
a = list(map(float, input().split()))

print(calculate_mode(a))
