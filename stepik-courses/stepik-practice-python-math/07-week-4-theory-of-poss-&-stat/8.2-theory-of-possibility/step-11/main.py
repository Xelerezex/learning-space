from random import choice


def list_pull(L):
    return [x for y in L for x in list_pull(y)] if isinstance(L, list) else [L]


roads = str(input()).split(" ")
quantity_tram = list(map(int, str(input()).split(" ")))
identif = str(input()).split(" ")
position = int(input())

depo = list_pull([[roads[i] for _ in range(quantity_tram[i])] for i in range(len(quantity_tram))])

data = [[choice(depo) for _ in range(position)] for _ in range(200_000)]
data_if = [data[i][position - 1] for i in range(len(data)) if ((data[i][position - 1] in identif))]

answer = (len(data_if) / len(data)) * 100

print(f"{round(answer, 1)}%")
