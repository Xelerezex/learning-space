import requests

PATH_INPUT = './Files/03_06_02_input.txt'

with open(PATH_INPUT) as in_f_obj:
    url = in_f_obj.read().strip()

r = requests.get(url)
counter = 0

print(len(r.text.splitlines()))

PATH_OUTPUT = './Files/03_06_02_output.txt'

with open(PATH_OUTPUT, 'w') as out_f_obj:
    out_f_obj.write(str(counter))
