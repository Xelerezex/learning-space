def rotor(symbol, n, reverse=False):
    RDICT = {0: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
             1: 'EKMFLGDQVZNTOWYHXUSPAIBRCJ',
             2: 'AJDKSIRUXBLHWTMCQGZNPYFVOE',
             3: 'BDFHJLCPRTXVZNYEIWGAKMUSQO',
             4: 'ESOVPZJAYQUIRHXLNFTGKDCMWB',
             5: 'VZBRGITYUPSDNHLXAWMJQOFECK',
             6: 'JPGVOUMFYQBENHZRDKASXLICTW',
             7: 'NZJHGRCXMYSWBOUFAIVLPEKQDT',
             8: 'FKQHTLXOCBJSPDZRAMEWNIUYGV',
             'beta': 'LEYJVCNIXWPBQMDRTAKZGFUHOS',
             'gamma': 'FSOKANUERHMBTIYCWLQPZXVGJD'
             }

    r_out, r_in = (RDICT[0], RDICT[n]) if reverse else (RDICT[n], RDICT[0])
    return r_out[r_in.index(symbol)]
