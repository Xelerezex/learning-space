from random import choice

N, M, K = [int(input()) for i in range(3)]

depo = [1] * N + [0] * M
data = [[choice(depo) for _ in range(K)] for _ in range(100_000)]
data_if = [1 for i in range(len(data)) if data[i][-1] == 1]

answer = (sum(data_if) / len(data)) * 100

print(f"{round(answer, 1)}%")
