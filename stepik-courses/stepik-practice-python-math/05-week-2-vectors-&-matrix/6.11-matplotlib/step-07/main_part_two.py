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

# Создаем 3 объекта axes, для:
# Основного графика
axes1 = fig.add_axes([0, 0, 1, 1])
# Малого графика, где X - большие
axes2 = fig.add_axes([0.7, 0.55, 0.25, 0.25])
# Малого графика, где X - малые
axes3 = fig.add_axes([0.7, 0.15, 0.25, 0.25])

# Задаем две переменный, с выколотым нулем (x_p) и для больших X
# x_positive
x_p = np.arange(0.05, 5, 0.05)
# x_large
x_l = np.arange(4000, 5000, 0.01)

# ПРИМИНИМО К ОСНОВНОМУ ГРАФИКУ
# Создаем основной график, рассматривая значения только при x > 0
# 1
alpha, beta = 1, 1
axes1.plot(x_p, f(x_p, alpha, beta), color='red', linestyle='-', linewidth=2, label=r'$\alpha = 1$, $\beta = 1$')
# 2
alpha, beta = 1, 2
axes1.plot(x_p, f(x_p, alpha, beta), color='blue', linestyle='-', linewidth=2, label=r'$\alpha = 1$, $\beta = 2$')
# 3
alpha, beta = 2, 1
axes1.plot(x_p, f(x_p, alpha, beta), color='green', linestyle='-', linewidth=2, label=r'$\alpha = 2$, $\beta = 1$')

# Обозначаем предел отрисовки по Y
axes1.set_ylim(0, 30)

# Задаем название для оси X и Y
axes1.set_xlabel('X', fontsize=14)
axes1.set_ylabel('f(X)', fontsize=14)

# Включаем отображение легенды
axes1.legend(fontsize=12)

# Задаем название гравика
axes1.set_title('График при x > 0', fontsize=14)

# ПРИМИНИМО К МАЛОМУ ГРАФИКУ №1(ПРИ БОЛЬШИХ Х)
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
axes2.set_xlim(4000, 5000)

# Задаем название для оси X и Y
axes2.set_xlabel('X', fontsize=14)
axes2.set_ylabel('f(X)', fontsize=14)

# Задаем название гравика
axes2.set_title('График при больших x\n', fontsize=14)

# ПРИМИНИМО К МАЛОМУ ГРАФИКУ №2(ПРИ МАЛЫХ Х)
# делаем всё для третьего графика при малых x
# 1
alpha, beta = 1, 1
axes3.plot(x_p, f(x_p, alpha, beta), color='red', linestyle='-', linewidth=2,)
# 2
alpha, beta = 1, 2
axes3.plot(x_p, f(x_p, alpha, beta), color='blue', linestyle='-', linewidth=2,)
# 3
alpha, beta = 2, 1
axes3.plot(x_p, f(x_p, alpha, beta), color='green', linestyle='-', linewidth=2,)

# Обозначаем предел отрисовки по X, и по Y
axes3.set_ylim(1, 6)
axes3.set_xlim(0.1, 1.6)

# Задаем название для оси X и Y
axes3.set_xlabel('X', fontsize=14)
axes3.set_ylabel('f(X)', fontsize=14)


# Задаем название гравика
axes3.set_title('График при малых x\n', fontsize=14)

# Сохраняем в svg-файл, при необходимости изменить PATH (сейчас он сохраняется в директорию, где лежит notebook)
PATH = 'ExerciseOne_PartTwo.svg'
plt.savefig(PATH)

# Отображаем график в notebook
# plt.show()
