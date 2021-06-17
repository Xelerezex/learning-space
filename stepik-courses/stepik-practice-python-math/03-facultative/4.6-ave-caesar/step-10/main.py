def disc_generator(alphabet):
    from random import shuffle
    alphabet = [i for i in alphabet]
    shuffle(alphabet)
    return ''.join(alphabet)


discs = [disc_generator(clear_alphabet) for i in range(n)]


def caesar(text, key, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ'):
    return ''.join([alphabet[(alphabet.find(ch) + key) % len(alphabet)] for ch in text.upper() if ch in alphabet])


def jefferson_encryption(text, discs, step, reverse=False):
    text = ''.join([i for i in text.upper() if i in clear_alphabet])
    return ''.join([caesar(text[i], step * (1, -1)[reverse], discs[i % n]) for i in range(len(text))])
