def both_ends(s):
    return '' if len(s) < 2 else s[:2] + s[-2:]


print(both_ends(input()))
