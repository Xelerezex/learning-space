tab = {i: [0, 0] for i in range(1, 12)}

with open('dataset_3380_5.txt') as inf:

    for i in inf:
        line = i.strip().split('\t')
        tab[int(line[0])][0] += int(line[2])
        tab[int(line[0])][1] += 1

    for i in tab.keys():
        if tab[i][1] == 0:
            print(i, '-')
        else:
            print(i, (tab[i][0] / tab[i][1]))
