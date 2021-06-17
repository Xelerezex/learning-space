import re


class Enigma:
    __alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    __rotor = {1: ('AELTPHQXRU', 'BKNW', 'CMOY', 'DFG', 'IV', 'JZ', 'S'),
               2: ('FIXVYOMW', 'CDKLHUP', 'ESZ', 'BJ', 'GR', 'NT', 'A', 'Q'),
               3: ('ABDHPEJT', 'CFLVMZOYQIRWUKXSG', 'N')}

    __refl = {1: ('AY', 'BR', 'CU', 'DH', 'EQ', 'FS', 'GL', 'IP', 'JX', 'KN', 'MO', 'TZ', 'VW'),
              2: ('AF', 'BV', 'CP', 'DJ', 'EI', 'GO', 'HY', 'KR', 'LZ', 'MX', 'NW', 'TQ', 'SU')}

    __stepping = {1: 17, 2: 5, 3: 22, 4: 10, 5: 0}

    def __init__(self, reflector=1, rotors=[3, 2, 1], shifts=[0, 0, 0]):
        self.__shifts = shifts[::]
        self.__rotors = rotors
        self.__reflector_type = reflector

    def __rotor_reflector(self, symbol, rotor_or_refl, n, reverse=False):
        seq = list(*filter(lambda s: symbol in s, rotor_or_refl.get(n, [symbol])))
        return seq[(seq.index(symbol) + 1 - 2 * reverse) % len(seq)]

    def __shift(self, char, key):
        return self.__alphabet[(self.__alphabet.index(char) + key) % len(self.__alphabet)]

    def __move_disks(self):
        def step(n): return (n + 1) % 26
        self.__shifts[0] = step(self.__shifts[0])
        for i in range(len(self.__shifts) - 1):
            if self.__shifts[i] == self.__stepping[self.__rotors[i]] or (
                    not i and self.__shifts[i + 1] + 1 ==
                    self.__stepping[self.__rotors[i + 1]]):

                self.__shifts[i + 1] = step(self.__shifts[i + 1])
            else:
                break

    def __pass_through_disks(self, symbol, reverse=False):
        prev_shift = 0
        d = 1 - 2 * reverse
        for n, i in zip(self.__rotors[::d], self.__shifts[::d]):
            symbol = self.__rotor_reflector(self.__shift(symbol, i - prev_shift), self.__rotor, n, reverse)
            prev_shift = i
        symbol = self.__shift(symbol, -prev_shift)
        return symbol

    def encode_symbol(self, symbol):
        self.__move_disks()
        c = self.__pass_through_disks(symbol[:1])
        c = self.__rotor_reflector(c, self.__refl, self.__reflector_type, reverse=True)
        return self.__pass_through_disks(c, reverse=True)

    def encode_text(self, text):
        string = re.sub(r'\W', '', text.upper())
        try:
            return ''.join([self.encode_symbol(symbol) for symbol in string])
        except ValueError as e:
            return e


def enigma(text, ref, rot1, shift1, rot2, shift2, rot3, shift3):
    enigm = Enigma(ref, [rot3, rot2, rot1], [shift3, shift2, shift1])
    return enigm.encode_text(text)
