def kaprekar(number):
    str_square = str(number ** 2)
    for i in range(1, len(str_square)):
        a, b = int(str_square[:i]), int(str_square[i:])
        if a * b and a + b == number:
            return True
    return False
