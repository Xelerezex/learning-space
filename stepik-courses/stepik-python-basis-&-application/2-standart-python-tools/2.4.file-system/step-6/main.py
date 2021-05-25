import os

with open('./Files/result.txt', 'w') as f:
    for current_dir, dirs, files in os.walk('./Files/main'):
        if list(filter(lambda x: x.endswith('.py'), files)):
            f.write('{}\n'.format(current_dir))


def sortFile(src, dst):
    x, y = open(src, 'r'), open(dst, 'w')
    b = x.readlines()
    x.close()
    b.sort()
    for i in b:
        y.write(i.strip() + "\n")
    y.close()


sortFile('./Files/result.txt', './Files/BLYAT.txt')
