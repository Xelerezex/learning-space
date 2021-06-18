# Подключаем Библиотеки
import sys
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

# Вывод в нотбук, для лучшей отладки
# %matplotlib inline

# При решении использовались следующие версии:
print(f'python: {sys.version}',
      f'numpy: {np.__version__}',
      f'matplotlib: {matplotlib.__version__}', sep='\n')

# Задаем первую функцию f(x)


def f(x):
      return (np.sin(x / 5) * np.exp(x / 10)) + (5 * np.exp(-x / 2))

# Задаем вторую функцию g(x)


def g(x):
      return 1 - (x ** 3) + (x ** 5)

# Задаем вторую функцию h(x)


def h(x):
      return ((5 * (np.sin(np.exp(0.8 * x)) ** 2)) * (x ** 2)) / (np.exp((x ** 2) / 2))


# Создаем объект: фигура и 2 оси
fig, (axes1, axes2) = plt.subplots(1, 2, figsize=(12, 9), dpi=120)
plt.suptitle('Пересечения графиков функций:', fontsize=20)

# ПЕРВЫЙ ГРАФИК
x = np.arange(-10, 80, 0.01, dtype=np.float128)
axes1.plot(x, f(x), x, g(x), x, h(x))
axes1.legend(['f(x)', 'g(x)', 'h(x)'])
axes1.set_xlabel('Ось X')
axes1.set_ylabel('Ось У')
axes1.set_ylim(-1, 7)
axes1.set_xlim(-3, 5)
axes1.plot(-1.15, 0.55, 0.45, 0.95, 1.1, 1.35, color='r', marker='o')
axes1.plot(1.35, 2.85, color='c', marker='o')
axes1.plot(1.78, 2.47, 2.05, 2.3, color='m', marker='o')
axes1.set_title(r'$f(x) = \sin(\frac{x}{5})\cdot  e^(\frac{x}{10}) + 5 \cdot \exp(\frac{-x}{2})$ и' + '\n', fontsize=14)


# ВТОРОЙ ГРАФИК
axes2.plot(x, f(x), x, g(x), x, h(x))
axes2.legend(['f(x)', 'g(x)', 'h(x)'])
axes2.set_xlabel('Ось X')
axes2.set_ylabel('Ось У')
axes2.set_ylim(-100, 100)
axes2.set_xlim(0, 80)
axes2.plot(16, 0, 31, 0, 47, 0, 62.5, 0, 78.5, 0, color='m', marker='o')
axes2.set_title(r'$g(x) = 1 - x^3 + x^5$,  $h(x) =\frac{5\cdot \sin^2(\exp^{0.8 \cdot x})\cdot x^2}{exp(\frac{x^2}{2})}$', fontsize=14)

# Отобразить фигуру
# plt.show()
