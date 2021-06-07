def kaprekar_step(digits):
    min_number_str = ''.join(map(str, sorted(digits)))

    return int(min_number_str[::-1]) - int(min_number_str)
