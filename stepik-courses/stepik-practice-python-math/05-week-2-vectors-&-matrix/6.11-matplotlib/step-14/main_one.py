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


# Создаем обьект: фигура и ось
fig, axes = plt.subplots(1, 3, figsize=(17, 11), dpi=120)
plt.suptitle('Графики функций \n', fontsize=20)

# ПЕРВЫЙ ГРАФИК
x1 = np.arange(-100, 150, 0.01, dtype=np.float128)
axes[0].plot(x1, f(x1), x1, g(x1), x1, h(x1))
axes[0].legend(['f(x)', 'g(x)', 'h(x)'])
axes[0].set_xlabel('Ось X')
axes[0].set_ylabel('Ось У')
axes[0].set_ylim(-20000, 60000)
axes[0].axhline(y=0, color='k', lw=0.6)
axes[0].axvline(x=0, color='k', lw=0.6)
axes[0].set_title(r'$f(x) = \sin(\frac{x}{5})\cdot  e^(\frac{x}{10}) + 5 \cdot \exp(\frac{-x}{2})$' + '\n', fontsize=14)

# ВТОРОЙ ГРАФИК
x2 = np.arange(-40, 40, 0.1, dtype=np.float128)
axes[1].plot(x2, f(x2), x2, g(x2), x2, h(x2))
axes[1].legend(['f(x)', 'g(x)', 'h(x)'])
axes[1].set_xlabel('Ось X')
axes[1].set_ylabel('Ось У')
axes[1].set_ylim(-100, 100)
axes[1].set_title(r'$g(x) = 1 - x^3 + x^5$, \n$' + '\n', fontsize=14)

# ТРЕТИЙ ГРАФИК
x3 = np.arange(-40, 40, 0.1, dtype=np.float128)
axes[2].plot(x3, f(x3), x3, g(x3), x3, h(x3))
axes[2].legend(['f(x)', 'g(x)', 'h(x)'])
axes[2].set_xlabel('Ось X')
axes[2].set_ylabel('Ось У')
axes[2].set_ylim(-10, 10)
axes[2].set_title(r'$h(x) =\frac{5\cdot \sin^2(\exp^{0.8 \cdot x})\cdot x^2}{exp(\frac{x^2}{2})}$' + '\n', fontsize=14)

# Отобразить фигуру
# plt.show()
