def wisdom_multiplication(x, y, length_check=True):
    d1 = str(x + y - 100)
    d2 = str((100 - x) * (100 - y)).rjust(2 if length_check else 0, '0')
    return ''.join([d1, d2])
