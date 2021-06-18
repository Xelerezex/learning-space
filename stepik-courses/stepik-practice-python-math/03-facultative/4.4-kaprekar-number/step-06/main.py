def convert(num, to_base=10, from_base=10):
    digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    n_decimal = int(str(num), base=from_base)
    res = ''
    while n_decimal != 0:
        res = str(digits[n_decimal % to_base]) + res
        n_decimal //= to_base
    return res


def kaprekar(n, base=10):
    d = int(convert(n, 10, base))
    s = convert(d**2, base, 10)
    for i in range(1, len(s)):
        if int(s[i:], base) != 0 and int(s[0:i], base) + int(s[i:], base) == d:
            return True
    return False
