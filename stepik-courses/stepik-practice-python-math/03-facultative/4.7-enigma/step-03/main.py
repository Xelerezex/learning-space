def reflector(symbol, n):
    REFLECTORS = {0: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
                  1: 'YRUHQSLDPXNGOKMIEBFZCWVJAT',
                  2: 'FVPJIAOYEDRZXWGCTKUQSBNMHL',
                  3: 'ENKQAUYWJICOPBLMDXZVFTHRGS',
                  4: 'RDOBJNTKVEHMLFCWZAXGYIPSUQ',
                  }

    return REFLECTORS[n][REFLECTORS[0].index(symbol)]
