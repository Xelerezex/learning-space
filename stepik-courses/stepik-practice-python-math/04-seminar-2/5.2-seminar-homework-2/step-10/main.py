def print_mimic(mdict, word, n=200):
    res = []
    for _ in range(n):
        res.append(word)
        word = random.choice(mdict.get(word, mdict['']))
    return ' '.join(res)
