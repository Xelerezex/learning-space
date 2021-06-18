a = input()  # input auto use type str
s1 = a.upper().count('c'.upper())
s2 = a.upper().count('g'.upper())
S = s1 + s2
print(S / len(a) * 100)
