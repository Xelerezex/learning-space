# Подключаем Библиотеки
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import requests
import statistics

# Вывод в нотбук, для лучшей отладки
# %matplotlib inline

# При решении использовались следующие версии:
import sys
import matplotlib
print(f'python: {sys.version}',
      f'numpy: {np.__version__}',
      f'matplotlib: {matplotlib.__version__}',
      f'pandas: {pd.__version__}',
      f'requests: {requests.__version__}', sep='\n')

# Собираем данные, через request
def Data_Mining():
    url = 'https://math-praktikum-stepik.herokuapp.com/api/assignment/a368500_10/'
    with open('data.txt', 'a') as file:
        for i in range(10000):
            r = requests.get(url)
            if r.status_code == 200:
                file.write(r.text + '\n')
            print(i)

# Считываем данные из файла в переменную
PATH = "data.txt"
with open(PATH, 'r') as file:
    data = np.array(file.read().strip().split('\n')).astype('float64')

# Строим Гистограмму
fig, axes = plt.subplots(figsize = (13, 8), dpi = 120)
axes.hist(data, bins = 1000, label = 'data')
mean = data.mean()
axes.hist([mean for _ in range(50)], label = r'$\mu$')
std = np.std(data, ddof = 1)
axes.hist([mean - std for _ in range(50)], label = r"$\mu - \sigma$")
axes.hist([mean + std for _ in range(50)], label = r"$\mu + \sigma$")
axes.hist([mean - 2*std for _ in range(50)], label = r"$\mu - 2\sigma$")
axes.hist([mean + 2*std for _ in range(50)], label = r"$\mu + 2\sigma$")
axes.legend()
# plt.show()
