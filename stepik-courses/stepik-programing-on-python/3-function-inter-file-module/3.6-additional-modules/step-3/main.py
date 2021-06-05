import requests

url_pattern = 'https://stepik.org/media/attachments/course67/3.6.3/'

PATH_INPUT = './Files/03_06_03_input.txt'

with open(PATH_INPUT) as in_f_obj:
    url = in_f_obj.read().strip()

counter = 0

while True:
    r = requests.get(url)
    if 'We' in str(r.text.strip()):
        break
    url = url_pattern + str(r.text.strip())


text = r.text.strip()

PATH_OUTPUT = './Files/03_06_03_output.txt'

with open(PATH_OUTPUT, 'w') as out_f_obj:
    out_f_obj.write(text)
