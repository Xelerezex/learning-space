print(sum([sum(map(int, i.split(" "))) for i in [input() for _ in range(int(input()) + 1)][1:]]))
