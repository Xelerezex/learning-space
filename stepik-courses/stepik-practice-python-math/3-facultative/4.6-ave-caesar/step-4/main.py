def caesar(text, key, alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ"):
    return "".join(
        alphabet[(alphabet.index(letter) + key) % len(alphabet)]
        for letter in filter(alphabet.__contains__, text.upper())
    )


def bruteforce(text, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ'):
    for key in range(1, len(alphabet)):
        print(caesar(text, -key, alphabet))
