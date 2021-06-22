aces = "🂡🂱🃁🃑"
cards = ["1" if x in aces else "0" for x in list(input())]

k = 100000


def check():
    random.shuffle(cards)
    return '1111' in "".join(cards)


result = sum([1 for _ in range(k) if check()])
print(f"{round(result/k*100, 2)}%")
