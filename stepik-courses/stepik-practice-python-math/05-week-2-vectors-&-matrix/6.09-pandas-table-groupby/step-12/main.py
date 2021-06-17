import pandas as pd

df = pd.read_csv('StudentsPerformance.csv')

group = df.groupby(['gender', 'race/ethnicity'])
print(group['reading score'].median().max())
