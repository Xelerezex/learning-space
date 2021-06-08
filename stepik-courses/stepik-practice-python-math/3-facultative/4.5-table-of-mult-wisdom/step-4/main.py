def multiplication_check(x, y):
    return simple_multiplication(x, y) == x * y


def simple_multiplication(x, y):
    return (x + y - 100) * 100 + (100 - x) * (100 - y)


def multiplication_check_list(start=10, stop=99):
    answ = [multiplication_check(i, j) for i in range(start, stop + 1) for j in range(start, stop + 1)]
    print('Правильных результатов: {}\nНеправильных результатов: {}'.format(answ.count(True), answ.count(False)))


# def multiplication_check_list(start = 10, stop = 99):
#    t = (stop + 1 - start) ** 2
#    print ('Правильных результатов:', t)
#    print ('Неправильных результатов: 0')
