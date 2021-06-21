huddle = [int(value) for value in input().split()]

h_length = len(huddle)
h_sum = sum(huddle)

if h_length < 2:
    print('Ошибка. Кучек слишком мало, чтобы можно было решить задачу.')

elif (h_length == 2 and huddle[0] != huddle[1]) or (h_sum % 2 and not h_length % 2):
    print('Кучки нельзя уравнять')

else:
    print('Кучки можно уравнять')
