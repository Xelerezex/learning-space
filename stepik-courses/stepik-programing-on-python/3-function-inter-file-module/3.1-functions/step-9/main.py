def modify_list(l):
    le = len(l) - 1
    i = le
    while i != -1:
        if l[i] % 2:
            del l[i]
        else:
            l[i] = l[i] // 2
        i -= 1
    return
