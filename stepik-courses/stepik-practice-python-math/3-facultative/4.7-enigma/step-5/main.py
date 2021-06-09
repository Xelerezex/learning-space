def enigma(text, ref, rot1, rot2, rot3):
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    text = text.upper()
    text_list = [x for x in text if x in alphabet]
    text_len = len(text_list)
    for i in range(0, text_len):
        forward = rotor(rotor(rotor(text_list[i], rot3, False), rot2, False), rot1, False)
        reflected = reflector(forward, ref)
        backward = rotor(rotor(rotor(reflected, rot1, True), rot2, True), rot3, True)
        text_list[i] = backward
    return ''.join(text_list)


def reflector(symbol, n):
    REFLECTORS = {0: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
                  1: 'YRUHQSLDPXNGOKMIEBFZCWVJAT',
                  2: 'FVPJIAOYEDRZXWGCTKUQSBNMHL',
                  3: 'ENKQAUYWJICOPBLMDXZVFTHRGS',
                  4: 'RDOBJNTKVEHMLFCWZAXGYIPSUQ'}
    symbol_index = REFLECTORS[0].index(symbol)
    return REFLECTORS[n][symbol_index]


def rotor(symbol, n, reverse=False):
    ROTORS = {0: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
              1: 'EKMFLGDQVZNTOWYHXUSPAIBRCJ',
              2: 'AJDKSIRUXBLHWTMCQGZNPYFVOE',
              3: 'BDFHJLCPRTXVZNYEIWGAKMUSQO',
              4: 'ESOVPZJAYQUIRHXLNFTGKDCMWB',
              5: 'VZBRGITYUPSDNHLXAWMJQOFECK',
              6: 'JPGVOUMFYQBENHZRDKASXLICTW',
              7: 'NZJHGRCXMYSWBOUFAIVLPEKQDT',
              8: 'FKQHTLXOCBJSPDZRAMEWNIUYGV',
              'beta': 'LEYJVCNIXWPBQMDRTAKZGFUHOS',
              'gamma': 'FSOKANUERHMBTIYCWLQPZXVGJD'}
    if not reverse:
        symbol_index = ROTORS[0].index(symbol)
        return ROTORS[n][symbol_index]
    else:
        symbol_index = ROTORS[n].index(symbol)
        return ROTORS[0][symbol_index]
