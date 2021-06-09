def get_mean(i, data):
    res = sum(data) / len(data)
    print(f'Среднее {i+1} выборки: {round(res, 2)}')


def get_mode(i, data):
    n = len(data)
    counts = [data.count(elem) for elem in set(data)]
    res = [elem for elem in data if data.count(elem) == max(counts)]
    print(f'Мода {i+1} выборки: {round(sorted(res)[0], 2)}')


def get_median(i, data):
    n = len(data)
    data = sorted(data)
    res = data[n // 2] if n % 2 == 1 else (data[n // 2 - 1] + data[n // 2]) / 2
    print(f'Медиана {i+1} выборки: {round(res, 2)}')


n = int(input())
stats = {
    'mean': get_mean,
    'mode': get_mode,
    'median': get_median,
}

for i in range(n):
    mode = input()
    data = [float(elem) for elem in input().split()]
    stats[mode](i, data)
