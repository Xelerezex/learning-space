length, first, second = int(input()), map(
    int, input().split(" ")), map(int, input().split(" "))
print(*map(sum, zip(first, second)))
