try:
    print({
        "int":
        lambda: (int(input()) + int(input())) or "Empty Ints",
        "str":
        lambda: input() or "Empty String",
        "list":
        lambda: (lambda x: x and x.split()[-1])(input()) or "Empty List"
    }[input()]())
except KeyError:
    print("Unknown type")
