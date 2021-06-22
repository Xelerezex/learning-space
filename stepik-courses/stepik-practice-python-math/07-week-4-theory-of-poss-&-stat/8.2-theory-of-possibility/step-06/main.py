n, m, k = [int(input()) for i in range(3)]

dice = range(1, m + 1)
results = [sum([random.choice(dice) for i in range(n)]) for i in range(100000)]
p = len([i for i in results if i >= k]) / len(results)

print(str(round(p * 100, 1)) + '%')
