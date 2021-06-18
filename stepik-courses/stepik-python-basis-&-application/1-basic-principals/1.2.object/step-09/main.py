# objects = [1, 2, 1, 2, 3]
mass = []
for i in objects:
    mass.append(id(i))
g = set(mass)
print(len(g))
