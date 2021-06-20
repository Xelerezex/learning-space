import requests as re

PATH = './Files/dataset_24476_3.txt'

with open(PATH) as file:
    for num in file:
        response = re.get(
            'http://numbersapi.com/{number}/math?json=true'.format(number=num.rstrip())).json()

        print('Interesting') if response['found'] else print('Boring')
