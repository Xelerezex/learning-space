classes = {}


def add_class(classes, class_name, parents):
    if class_name not in classes:
        classes[class_name] = []
    classes[class_name].extend(parents)
    for parent in parents:
        if parent not in classes:
            classes[parent] = []


def found_path(classes, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in classes:
        return None
    for node in classes[start]:
        if node not in path:
            newpath = found_path(classes, node, end, path)
            if newpath:
                return newpath
    return None


def answer(classes, parent, child):
    if not(parent or child) in classes or not found_path(classes, child, parent):
        return 'No'
    return 'Yes'


n = int(input())
for _ in range(n):
    class_description = input().split()
    class_name = class_description[0]
    class_parents = class_description[2:]
    add_class(classes, class_name, class_parents)

q = int(input())
for _ in range(q):
    question = input().split()
    parent = question[0]
    child = question[1]
    print(answer(classes, parent, child))
