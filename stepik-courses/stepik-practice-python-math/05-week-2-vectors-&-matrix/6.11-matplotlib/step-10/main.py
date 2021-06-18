# Подключаем Библиотеки
import numpy as np
import matplotlib.pyplot as plt

# Вывод в нотбук, для лучшей отладки
# %matplotlib inline

# При решении использовались следующие версии:
import sys
import matplotlib
print(f'python: {sys.version}',
      f'numpy: {np.__version__}',
      f'matplotlib: {matplotlib.__version__}', sep='\n')
fig = plt.figure()

# 4 части комикса записываем в переменные. Файлы должны лежать вместе со скриптом. Либо нужно прописать путь до них
with open('1.png', 'rb') as axes1:
    axes_1 = plt.imread(axes1)

with open('2.png', 'rb') as axes2:
    axes_2 = plt.imread(axes2)

with open('3.png', 'rb') as axes3:
    axes_3 = plt.imread(axes3)

with open('4.png', 'rb') as axes4:
    axes_4 = plt.imread(axes4)

# Создаем 4 оси
axes1 = fig.add_axes([0, 0, 1.5, 1.5])
axes2 = fig.add_axes([-0.4, -1.2, 1.2, 1.2])
axes3 = fig.add_axes([0.1, -1.2, 1.2, 1.2])
axes4 = fig.add_axes([0.65, -1.2, 1.2, 1.2])

# Отображаем в оси переменные с частями комикса
axes1.imshow(axes_1)
axes2.imshow(axes_2)
axes3.imshow(axes_3)
axes4.imshow(axes_4)

# Отключаем все оси X и Y
axes1.get_xaxis().set_visible(False)
axes1.get_yaxis().set_visible(False)

axes2.get_xaxis().set_visible(False)
axes2.get_yaxis().set_visible(False)

axes3.get_xaxis().set_visible(False)
axes3.get_yaxis().set_visible(False)

axes4.get_xaxis().set_visible(False)
axes4.get_yaxis().set_visible(False)

# НЕ РЕАЛИЗОВАЛ СОХРАНЕНИЕ, Т.К. БЫЛ НЕАДЕКВАТНЫЙ ВЫВОД

# Отобразить фигуру
# plt.show()
