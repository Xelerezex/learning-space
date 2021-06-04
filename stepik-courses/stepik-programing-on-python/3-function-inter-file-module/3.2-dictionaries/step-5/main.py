def update_dictionary(d, key, value):
    if key in d:
        d[key].append(value)
    elif key is not d:
        if 2 * key is d:
            d[2 * key].append(value)
        elif (2 * key is not d) and d.get(2 * key) == None:
            d[2 * key] = []
            d[2 * key].append(value)
        elif (2 * key is not d) and d.get(2 * key) != None:
            d[2 * key].append(value)
    return
