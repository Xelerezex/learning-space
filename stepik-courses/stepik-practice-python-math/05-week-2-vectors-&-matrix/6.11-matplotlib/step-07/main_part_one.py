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

#Задаем основные объекты для дальнешей работы, ставим размер фигуры, и нормальный dpi, что б было не размыто
fig, axes = plt.subplots(figsize=(13, 8), dpi = 120)

#Задаем две переменный, что б "выколоть" ноль
# x_positive
x_p = np.arange(0.05,5, 0.05)
# x_negative
x_n =  np.arange(-5,0, 0.05)

#Отрисовываем графики
#1
alpha, beta = 1, 1
axes.plot(x_p, f(x_p, alpha, beta), color = 'red', linestyle = '-', linewidth = 2, label = r'$\alpha = 1$, $\beta = 1$')
axes.plot(x_n, f(x_n, alpha, beta), color = 'red', linestyle = '-', linewidth = 2,)
#2
alpha, beta = 2, 1
axes.plot(x_p, f(x_p, alpha, beta), color = 'green', linestyle = '-', linewidth = 2, label = r'$\alpha = 2$, $\beta = 1$')
axes.plot(x_n, f(x_n, alpha, beta), color = 'green', linestyle = '-', linewidth = 2,)
#3
alpha, beta = 1, 2
axes.plot(x_p, f(x_p, alpha, beta), color = 'blue', linestyle = '-', linewidth = 2, label = r'$\alpha = 1$, $\beta = 2$')
axes.plot(x_n, f(x_n, alpha, beta), color = 'blue', linestyle = '-', linewidth = 2,)

#Отрисовываем оси на графике
# Обозначаем предел оси Y
axes.set_ylim(-20, 30)

# Даем наименование оси X и Y
axes.set_xlabel('X', fontsize = 18)
axes.set_ylabel('f(X)', fontsize = 18)

# Задаем название графика
axes.set_title(r'График функции $f(x)=\frac{x^\beta + \alpha^\beta}{x^\beta}$ при различных $\alpha$ и $\beta$', fontsize = 14)

# Включаем отрисовку легенды
axes.legend(fontsize = 18)

# Сохраняем в svg-файл, при необходимости изменить PATH (сейчас он сохраняется в директорию, где лежит notebook)
PATH = 'ExerciseOne_PartOne.svg'
plt.savefig(PATH)

# Отображаем график в notebook
# plt.show()
