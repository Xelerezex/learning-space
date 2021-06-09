from itertools import cycle


def jarriquez_encryption(text, key, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ', reverse=False):
    n = len(alphabet)
    sign = -1 if reverse else 1
    return "".join(
        alphabet[(alphabet.index(letter) + sign * int(skey)) % n]
        for letter, skey in zip(
            filter(alphabet.__contains__, text.upper()), cycle(str(key))
        )
    )
