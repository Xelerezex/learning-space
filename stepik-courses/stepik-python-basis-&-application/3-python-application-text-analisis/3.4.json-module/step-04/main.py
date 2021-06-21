import json


def test(x, c):
    for i in z:
        if x in i['parents']:
            c.add(i['name'])
            c = test(i['name'], c)
    return (c)


z = json.loads(input())
z.sort(key=(lambda x: x['name']))
for i in z:
    print(i['name'], ':', len(test(i['name'], c=set())) + 1)
