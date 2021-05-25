def closest_mod_5(x):
    if x % 5 == 0:
        return x
    else:
        for i in range(x):
            if x % 5 != 0:
                x += 1
            elif x % 5 == 0:
                return x
