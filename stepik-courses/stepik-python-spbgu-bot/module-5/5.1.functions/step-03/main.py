from statistics import mean


def calculate_mean(x):
    return mean(x)


n = int(input())
a = list(map(float, input().split()))

print(calculate_mean(a))
