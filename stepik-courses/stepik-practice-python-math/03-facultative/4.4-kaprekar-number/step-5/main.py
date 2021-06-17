def convert(num, to_base=10, from_base=10):
    alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    decimal = int(str(num), from_base)
    target = ""
    while decimal > 0:
        target = alpha[decimal % to_base] + target
        decimal = decimal // to_base
    return target
