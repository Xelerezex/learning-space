def caesar(text, key, alphabet='ABCDEFGHIJKLMNOPQRSTUVWXYZ'):
    return alphabet[(alphabet.index(text) + key) % len(alphabet)]


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
              'gamma': 'FSOKANUERHMBTIYCWLQPZXVGJD'
              }
    x = 0
    if reverse:
        x, n = n, x
    return ROTORS[n][ROTORS[x].index(symbol)]


def reflector(symbol, n):
    REFLECTORS = {0: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
                  1: 'YRUHQSLDPXNGOKMIEBFZCWVJAT',
                  2: 'FVPJIAOYEDRZXWGCTKUQSBNMHL',
                  3: 'ENKQAUYWJICOPBLMDXZVFTHRGS',
                  4: 'RDOBJNTKVEHMLFCWZAXGYIPSUQ',
                  }
    return REFLECTORS[n][REFLECTORS[0].index(symbol)]


def enigma(text, ref, rot1, shift1, rot2, shift2, rot3, shift3):
    data = [i.upper() for i in text if i.isalpha()]
    forward = (rot3, rot2, rot1)
    back = (rot1, rot2, rot3)
    shifts = (shift3, shift2, shift1)
    shifts_back = (shift1, shift2, shift3)
    dec_text = ''
    for char in data:
        for num, rot in enumerate(forward):
            char = caesar(char, shifts[num])
            char = rotor(char, rot)
            char = caesar(char, -shifts[num])
        char = reflector(char, ref)
        for num, rot in enumerate(back):
            char = caesar(char, shifts_back[num])
            char = rotor(char, rot, True)
            char = caesar(char, -shifts_back[num])
        dec_text += char
    return dec_text
