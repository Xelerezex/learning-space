dic = {input().lower() for i in range(int(input()))}

wrd = set()
for w in range(int(input())):
    wrd |= {i.lower() for i in input().split()}

print(*wrd.difference(dic), sep="\n")
