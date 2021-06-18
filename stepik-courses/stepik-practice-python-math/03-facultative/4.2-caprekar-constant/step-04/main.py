def numerics(n):
    return [int(i) for i in str(n)]


def kaprekar_step(L):
    x = "".join(map(str, sorted(numerics(L))))
    return int(x[::-1]) - int(x)


def kaprekar_loop(n):
    print(n)
    while n != 6174:
        return kaprekar_loop(kaprekar_step(n))
