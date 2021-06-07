def fix_start(s):
    return s[0] + s[1:].replace(s[0], '*')


print(fix_start(input()))
