def kaprekar_loop(n, s=set(), f=True):
    p = str(n)
    if f and (len(p) not in [3, 4, 6] or len(set(p)) == 1 or n in [100, 1000, 100000]):
        print(f"Ошибка! На вход подано число {n}, не удовлетворяющее условиям процесса Капрекара")
        return
    print(n)
    nn = (lambda L: int(str(sorted(L, reverse=True))[1:-1:3]) - int(str(sorted(L))[1:-1:3]))([int(i) for i in p])
    if nn == n:
        return
    if nn in s:
        print(f"Следующее число - {nn}, кажется процесс зациклился...")
    else:
        kaprekar_loop(nn, s=s | {n}, f=False)
