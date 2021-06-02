num = int(input())
res = [i for i in range(2, (int(num**(1 / 2)))) if not num % i]
print(res[0] if res else num)
