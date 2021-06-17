# Для построения таблицы будем использовать библиотеку pandas
import pandas as pd

# Функция умножения по методу «Мудреца»


def wisdom_multiplication(x, y, length_check=True):
    p1 = str((100 - (100 - x) - (100 - y)))  # Первые две цифры результата
    p2 = str((100 - x) * (100 - y))  # Вторые две цифры результата
    # Если требуется, удостоверяемся, что вторых цифр действительно две
    if length_check:
        # когда результат подсчёта второй половины состоит лишь из одной цифры
        # добавим 0 между ними
        if len(p2) < 2:
            return int(p1 + '0' + p2)

    return int(p1 + p2)

# функция для проверки результата перемножения по методу «Мудреца»


def wisdom_multiplication_check(x: int, y: int) -> dict:
    correct = x * y
    # отдельной проверим без проверки длины
    no_check = correct == wisdom_multiplication(x, y, False)
    # если результат перемножения без проверки длины верен,
    # то и с проверкой тоже будет верный результат
    if no_check:
        return {"no_check": True,
                "check": True}
    # если без проверки длины результат оказался неверным,
    # проверим какой результат даст метод с использованием проверкой длины
    else:
        return {"no_check": no_check,
                "check": correct == wisdom_multiplication(x, y, True)}

# функция для покраски ячеек


def wisdom_style(val, no_check_color='green', check_color='orange'):
    # извлекаем числа из строчных данных, записанных в ячейках
    n, m = (int(x) for x in val.split('x'))

    # проверяем верность метода «Мудреца»
    w_check = wisdom_multiplication_check(n, m)
    if w_check["no_check"]:
        return f"background-color: {no_check_color}"
    elif w_check["check"]:
        return f"background-color: {check_color}"
    else:
        return ""


# настраиваем отображение таблиц в pandas так, чтобы в нашей таблице отображались все столбцы и строки
pd.set_option("display.max_columns", 100)
pd.set_option("display.max_rows", 100)
# дополнительно укажем, чтобы столбец расширялся, если его ширине не хватит для отображения содержимого
pd.set_option("display.max_colwidth", None)
# задачём границы таблицы
start, stop = 10, 99

# создаём таблицу, заполняя строковыми значениями выражающими умножение n на m.
table = pd.DataFrame([[f'{n}x{m}' for n in range(start, stop + 1)] for m in range(start, stop + 1)],
                     index=range(start, stop + 1), columns=range(start, stop + 1), )

# красим ячейки таблицы в зависимости от верности результатов перемножения
# зелёные ячейки → те, где результат расчёта по методу «Мудреца» верен и без проверки на длину
# оранжевые ячейки → те, где результат расчёта по методу «Мудреца» верено, но только с проверкой на длину
styled = table.style.applymap(wisdom_style, no_check_color='lightgreen', check_color='orange')

# сохраним получившуюся таблицу в файл
with open('wisdom_table_correctness.html', 'w') as f:
    f.write(styled.render())

# отобразим получившуюся таблицу таблицу тут
styled
