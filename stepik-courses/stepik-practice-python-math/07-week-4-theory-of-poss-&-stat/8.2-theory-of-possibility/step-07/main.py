from random import uniform

L, M = int(input()), int(input())

all_data = [uniform(0, L) for i in range(1_000_000)]
data_if = [i for i in all_data if i >= M or (L - i) >= M]
answer = (len(data_if) / len(all_data)) * 100

print(f"{round(answer, 1)}%")
