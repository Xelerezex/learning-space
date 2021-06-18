dictionary = {}

PATH_INPUT = './Files/03_04_03_input.txt'

with open(PATH_INPUT) as in_f_obj:
    for line in in_f_obj:
        line = line.lower()
        for word in line.split():
            if word not in dictionary:
                dictionary[word] = 1
            elif word in dictionary:
                dictionary[word] += 1

max_quantity = 1

for key, value in dictionary.items():
    current_quantity = dictionary[key]
    if current_quantity > max_quantity:
        max_quantity = current_quantity
        word_with_max_quantity = key

PATH_OUTPUT = './Files/03_04_03_output.txt'

with open(PATH_OUTPUT, 'w') as out_f_obj:
    most_popular = (word_with_max_quantity + ' ' + str(max_quantity))
    out_f_obj.write(most_popular)
