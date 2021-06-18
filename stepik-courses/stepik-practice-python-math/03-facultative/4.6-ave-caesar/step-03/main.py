def caesar(text, key, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ'):
    data = [i.upper() for i in text if i.upper() in alphabet]
    return ''.join([alphabet[(alphabet.index(x) + key) % len(alphabet)] for x in data])
