import numpy as np

num, tries, success = int(input()), 1000000, 0
tickets = np.arange(1, num + 1)
golden_standart = np.arange(1, num + 1)

for x in range(tries):
    np.random.shuffle(tickets)
    success += (1 if any(tickets == golden_standart) else 0)

print('{:.1%}'.format(success / tries))
