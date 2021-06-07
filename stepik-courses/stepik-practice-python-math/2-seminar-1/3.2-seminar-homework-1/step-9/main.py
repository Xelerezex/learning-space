def front_x(words):
    return sorted(words, key=lambda x: (x[:1] != 'x', x))
