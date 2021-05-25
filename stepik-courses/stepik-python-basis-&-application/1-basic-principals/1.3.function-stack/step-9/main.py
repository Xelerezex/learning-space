def C(list):
    n, k = map(int, list.split())
    if k == 0:
        return 1
    if k > n:
        return 0
    list1 = f'{n-1} {k}'
    list2 = f'{n-1} {k-1}'
    return C(list1) + C(list2)


x = str(input())
print(C(x))
