def translate(a, n=2):
    if not a:
        return ''
    return translate(a // n, n) + str(a % n)
