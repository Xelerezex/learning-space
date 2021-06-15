# def verbing(s):
#     return s if len(s) < 3 else s + ('ing','ly')['ing' in s]

def verbing(s):
    if len(s) < 3:
        return s
    elif s.endswith("ing"):
        return s + "ly"
    else:
        return s + "ing"
