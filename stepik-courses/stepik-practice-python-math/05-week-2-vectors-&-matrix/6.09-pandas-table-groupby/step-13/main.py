import pandas as pd

ds = pd.read_csv('StudentsPerformance.csv')
meanScore = ds.groupby(['gender', 'parental level of education']).mean().mean(axis=1)
print(meanScore.loc[('male', meanScore.loc['female'].idxmax())].round(1))
