exceptions = {}
throwed_exceptions = []


def found_path(exceptions, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in exceptions:
        return []
    for node in exceptions[start]:
        if node not in path:
            newpath = found_path(exceptions, node, end, path)
            if newpath:
                return newpath
    return []


n = int(input())
for _ in range(n):
    inpt = input().split()
    child = inpt[0]
    parents = inpt[2:]
    exceptions[child] = parents

m = int(input())
for _ in range(m):
    throwing = input()
    for throwed_exception in throwed_exceptions:
        if len(found_path(exceptions, throwing, throwed_exception)) > 1:
            print(throwing)
            break
    throwed_exceptions.append(throwing)
