import itertools

def isPrime(n):
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n and n % d != 0:
        d += 2
    return d * d > n

def primes(number = 1):
    while True:
        number += 1
        if isPrime(number):
            yield number

#print(list(itertools.takewhile(lambda x : x <= 31, primes())))
