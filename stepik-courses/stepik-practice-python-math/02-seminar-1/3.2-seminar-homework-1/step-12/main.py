def donuts(n):
    return 'Всего пончиков: {}'.format(n if n <= 9 else 'много')


print(donuts(int(input())))
