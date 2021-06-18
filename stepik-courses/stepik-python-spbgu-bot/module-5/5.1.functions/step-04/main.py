from statistics import median


def calculate_median(x):
    return median(x)


n = int(input())
a = list(map(float, input().split()))

print(calculate_median(a))
