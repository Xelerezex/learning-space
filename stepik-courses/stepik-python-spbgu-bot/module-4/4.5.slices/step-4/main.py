matrix = [input().split(" ") for _ in range(int(input()))]
print(*[" ".join(item[1::2]) for item in matrix[1::2]], sep='\n')
