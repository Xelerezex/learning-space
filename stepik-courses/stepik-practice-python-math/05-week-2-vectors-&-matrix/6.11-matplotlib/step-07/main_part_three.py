# Подключаем Библиотеки
import numpy as np
import matplotlib.pyplot as plt
import sys
import matplotlib

# Вывод в нотбук, для лучшей отладки
# %matplotlib inline

# Задаем функию F


def f(X, alpha, beta):
    return (((X ** beta) + (alpha ** beta)) / (X ** beta))


# При решении использовались следующие версии:
print(f'python: {sys.version}',
      f'numpy: {np.__version__}',
      f'matplotlib: {matplotlib.__version__}', sep='\n')

# Задаем основные объекты для дальнешей работы, ставим размер фигуры, и нормальный dpi, что б было не размыто
fig = plt.figure(figsize=(13, 8), dpi=120)

# Создаем 2 объекта axes, для:
# Основного графика
axes1 = fig.add_axes([0, 0, 1, 1])
# Малого графика, где X - малые
axes2 = fig.add_axes([0.09, 0.2, 0.3, 0.3])

# Задаем две переменный, с выколотым нулем (x_p) и для больших, отрицательных значений X
# x_positive
x_n = np.arange(-5, 0, 0.05)
# x_large
x_l = np.arange(-5000, -4000, 0.01)

# ПРИМИНИМО К ОСНОВНОМУ ГРАФИКУ
# Создаем основной график, рассматривая значения только при x < 0
# 1
alpha, beta = 1, 1
axes1.plot(x_n, f(x_n, alpha, beta), color='red', linestyle='-', linewidth=2, label=r'$\alpha = 1$, $\beta = 1$')
# 2
alpha, beta = 1, 2
axes1.plot(x_n, f(x_n, alpha, beta), color='blue', linestyle='-', linewidth=2, label=r'$\alpha = 1$, $\beta = 2$')
# 3
alpha, beta = 2, 1
axes1.plot(x_n, f(x_n, alpha, beta), color='green', linestyle='-', linewidth=2, label=r'$\alpha = 2$, $\beta = 1$')
# f(x) = 0
# Задаем переменную-вектор, для отрисовки f(x) = 0
x_0 = [0 for item in x_n]
axes1.plot(x_n, x_0, color='orange', linestyle=':', linewidth=2, label=r'$f(x) = 0$')


# Обозначаем предел отрисовки по Y
axes1.set_ylim(-20, 10)


# Задаем название для оси X и Y
axes1.set_xlabel('X', fontsize=14)
axes1.set_ylabel('f(X)', fontsize=14)

# Включаем отображение легенды
axes1.legend(fontsize=12)

# Задаем название графика
axes1.set_title('График при x < 0', fontsize=14)

# ПРИМИНИМО К МАЛОМУ ГРАФИКУ (ПРИ БОЛЬШИХ ОТРИЦАТЕЛЬНЫХ Х)
#
# P.S. На вставке(малом графике), линию f(x)=0 не указал, т.к. отрисовывается только 1 линия, из-за супер малого расстояния между линиями графика.
# Но и по основному графику понятно, что пересечения нет.
#
# 1
alpha, beta = 1, 1
axes2.plot(x_l, f(x_l, alpha, beta), color='red', linestyle='-', linewidth=2,)
# 2
alpha, beta = 1, 2
axes2.plot(x_l, f(x_l, alpha, beta), color='blue', linestyle='-', linewidth=2,)
# 3
alpha, beta = 2, 1
axes2.plot(x_l, f(x_l, alpha, beta), color='green', linestyle='-', linewidth=2,)

# Обозначаем предел отрисовки по X
axes2.set_xlim(-5000, -4000)

# Задаем название для оси X и Y
axes2.set_xlabel('X', fontsize=14)
axes2.set_ylabel('f(X)', fontsize=14)

# Задаем название графика
axes2.set_title('График при больших отрицательных x\n', fontsize=14)

# Сохраняем в svg-файл, при необходимости изменить PATH (сейчас он сохраняется в директорию, где лежит notebook)
PATH = 'ExerciseOne_PartThree.svg'
plt.savefig(PATH)

# Отображаем график в notebook
plt.show()
