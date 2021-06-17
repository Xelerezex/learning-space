def multiplication_check(x, y, length_check=True):
    begin = str(100 - (100 - x + 100 - y))
    end = str((100 - x) * (100 - y))
    if (length_check) & (len(end) == 1):
        end = '0' + end
    return int(begin + end) == x * y


def multiplication_check_list(start=10, stop=99, length_check=True):
    l = [1 for i in range(start, stop + 1) for j in range(start, stop + 1) if multiplication_check(i, j, length_check)]
    print('Правильных результатов:', len(l))
    print('Неправильных результатов:', (stop + 1 - start) ** 2 - len(l))
