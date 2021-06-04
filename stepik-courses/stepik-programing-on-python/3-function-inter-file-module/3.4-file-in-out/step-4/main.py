averages = []
marks_math = []
marks_phys = []
marks_rus = []
counter = 0
value01 = 0
value02 = 0
value03 = 0

PATH_INPUT = './Files/03_04_04_input.txt'

with open(PATH_INPUT) as in_f_obj:

    for line in in_f_obj:
        line = line.rstrip().split(';')
        student_average = ((int(line[1]) + int(line[2]) + int(line[3])) / 3)
        averages.append(student_average)
        marks_math.append(int(line[1]))
        marks_phys.append(int(line[2]))
        marks_rus.append(int(line[3]))
        counter += 1

PATH_OUTPUT = './Files/03_04_04_output.txt'

with open(PATH_OUTPUT, 'w') as out_f_obj:

    for _ in averages:
        out_f_obj.write(str(_) + '\n')

    for _ in marks_math:
        value01 += int(_)
    for _ in marks_phys:
        value02 += int(_)
    for _ in marks_rus:
        value03 += int(_)
    average_math = value01 / counter
    average_phys = value02 / counter
    average_rus = value03 / counter

    out_f_obj.write(str(average_math) + ' ' + str(average_phys) + ' ' + str(average_rus))
