import string
for i in range(int(input())):
    _str = input()
    ln = len(_str) > 10
    uc = any((letter in _str for letter in string.ascii_uppercase))
    lc = any((letter in _str for letter in string.ascii_lowercase))
    dc = any((letter.isdigit() for letter in _str))
    sc = True if _str.find(" ") == -1 else False
    if (ln & uc & lc & dc & sc):
        print(_str[0])
