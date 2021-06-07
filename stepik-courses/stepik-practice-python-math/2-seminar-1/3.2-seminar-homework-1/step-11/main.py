def is_prime(n):
    return not any(i for i in range(2, int(n ** 0.5) + 1) if not n % i)
