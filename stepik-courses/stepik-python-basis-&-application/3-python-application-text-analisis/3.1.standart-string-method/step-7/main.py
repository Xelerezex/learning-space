haystack = input()
needle = input()

count = 0
i = -1
while True:
    i = haystack.find(needle, i + 1)
    if i == -1:
        print(count)
        break
    count += 1
