# def list_pull(L):
#    return [x for y in L for x in list_pull(y)] if isinstance(L, list) else [L]

def list_pull(L):
    result = []
    for item in L:
        if isinstance(item, list):
            result.extend(list_pull(item))
        else:
            result.append(item)
    return result
