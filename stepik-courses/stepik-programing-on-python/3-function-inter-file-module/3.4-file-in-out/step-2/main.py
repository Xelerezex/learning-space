# test_string = 'a12b10c3d1'

digits = set('0123456789')
i = 0
multiplier = ''
decrypted = ''

with open('03_04_02_input.txt') as in_f_obj:
    string = in_f_obj.readline().strip()

char = string[i]
i += 1

while i < len(string):

    while string[i] in digits:
        multiplier += string[i]
        i += 1
        if i > (len(string) - 1):
            break
    decrypted += (char * int(multiplier))

    multiplier = ''
    if i > (len(string) - 1):
        break
    char = string[i]

    i += 1

PATH = './Files/03_04_02_ouput.txt'

with open(PATH, 'w') as out_f_obj:
    out_f_obj.write(decrypted)
