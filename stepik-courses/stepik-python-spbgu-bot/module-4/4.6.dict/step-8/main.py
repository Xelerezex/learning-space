DICT = {}

for i in range(int(input())):
    key = input()
    if key not in DICT.keys():
        DICT[key] = 1
    elif key in DICT.keys():
        DICT[key] += 1

for i in sorted(DICT):
    print(f"{i}: {DICT[i]}")
