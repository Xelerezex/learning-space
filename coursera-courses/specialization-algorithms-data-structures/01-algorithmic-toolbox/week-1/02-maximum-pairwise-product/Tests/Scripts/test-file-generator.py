import random


FILE_NAME = 'test-data-4.txt'
PATH = '/home/person/Документы/__repo__/learning-space/coursera-courses/specialization-algorithms-data-structures/01-algorithmic-toolbox/week-1/02-maximum-pairwise-product/Tests/' + FILE_NAME


with open(PATH, 'w') as file:
    for item in range(0, 199_999):
        file.write(str(random.randint(0, 200_000)) + '\n')
